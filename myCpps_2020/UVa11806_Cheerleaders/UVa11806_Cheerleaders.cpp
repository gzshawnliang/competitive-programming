/*
===========================================================
* @Name:           UVa-11806 Cheerleaders
* @Author:         Shawn
* @create Time:    2020/2/27 23:10:09
* @url:            
* @Description:    
===========================================================
*/

#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 400, mod = 1000007;

void solve()
{
    vector<vector<int>> C(N + 1, vector<int>(N + 1, 0)); C[0][0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }
    }

    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n, m, k; cin >> n >> m >> k;

        if (k > n * m)
        {
            cout << "Case " << t << ": 0\n";
            continue;
        }

        int ans = 0;
        for (int i = 0; i <= (1 << 4) - 1; ++i)
        {
            bitset<4> b(i);
            int tmpSiz = n * m;
            if (b[0] == 1) tmpSiz -= n;
            if (b[1] == 1) tmpSiz -= n;
            if (b[2] == 1) tmpSiz -= m;
            if (b[3] == 1) tmpSiz -= m;
            tmpSiz += (b[0] + b[1]) * (b[2] + b[3]);

            if (b.count() % 2 == 0) ans = (ans + C[tmpSiz][k]) % mod;
            else                    ans = (ans + mod - C[tmpSiz][k]) % mod;
        }

        cout << "Case " << t << ": " << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("UVa11806_Cheerleaders.in", "r", stdin);
        freopen("UVa11806_Cheerleaders.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}