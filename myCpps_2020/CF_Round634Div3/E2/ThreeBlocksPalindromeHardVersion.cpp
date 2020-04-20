#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int tolC = 26;

void solve()
{
    int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
            int n; cin >> n;
            vector<int> a(n + 1, 0);
            vector<vector<int>> cntC(n + 1, vector<int>(tolC + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];

            for (int chr = 1; chr <= tolC; ++chr)
            {
                if (chr == a[i]) cntC[i][chr] = cntC[i - 1][chr] + 1;
                else             cntC[i][chr] = cntC[i - 1][chr];
            }
        }

            int ans = 1;
        for (int i = 0; i <= n; ++i)
        {
            int j = n + 1 - i;
            if (j <= i) break;

            int res1 = 0;
            for (int chr = 1; chr <= tolC; ++chr)
            {
                res1 = max(res1, min(cntC[i][chr], cntC[n][chr] - cntC[j - 1][chr]));
            }

            int res2 = 0;
            for (int chr = 1; chr <= tolC; ++chr)
            {
                res2 = max(res2, cntC[j - 1][chr] - cntC[i][chr]);
            }

            ans = max(ans, res1 * 2 + res2);
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