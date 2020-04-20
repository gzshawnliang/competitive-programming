#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int tolC = 200;

void solve()
{
    int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
            int n; cin >> n;
            vector<int> a(n + 1, 0);
            vector<vector<int>> cntC(n + 1, vector<int>(tolC + 1, 0)), pos(tolC + 1);
            
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];

            for (int chr = 1; chr <= tolC; ++chr)
            {
                if (chr == a[i]) cntC[i][chr] = cntC[i - 1][chr] + 1;
                else             cntC[i][chr] = cntC[i - 1][chr];
            }

            pos[a[i]].push_back(i);
        }

        int ans = 0;

        for (int col = 1; col <= tolC; ++col)
            ans = max(ans, cntC[n][col]);

        for (int col = 1; col <= tolC; ++col)
        {
            int siz = pos[col].size();
            for (int i = 0, j = siz - 1; i < j; ++i, --j)
            {
                int stt = pos[col][i], end = pos[col][j], maxTolC = 0;
                for (int col2 = 1; col2 <= tolC; ++col2)
                    maxTolC = max(maxTolC, cntC[end - 1][col2] - cntC[stt][col2]);

                ans = max(ans, (i + 1) * 2 + maxTolC);
            }
        }


        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("ThreeBlocksPalindromeHardVersion.in", "r", stdin);
        freopen("ThreeBlocksPalindromeHardVersion.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}