/*
===========================================================
* @Name:           UVa-10325 The Lottery
* @Author:         Shawn
* @create Time:    2020/2/25 23:08:27
* @url:            
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const ill maxM = 15;

ill gcd(ill a, ill b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ill lcm(ill a, ill b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    while (true)
    {
        ill n = 0, m = 0; cin >> n >> m;
        if (n + m == 0) break;

        vector<ill> a(m, 0);
        for (ill i = 0; i <= m - 1; ++i) cin >> a[i];

        ill ans = 0;
        for (ill i = 1; i <= (1 << m) - 1; ++i)
        {
            bitset<maxM> b(i);

            ill now = 1;
            for (ill j = 0; j <= m - 1; ++j)
                if (b[j] == 1)
                    now = lcm(now, a[j]);

            if (b.count() % 2 == 1)
            {
                ans += (n / now);
            }
            else
            {
                ans -= (n / now);
            }
        }

        cout << n - ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("UVa10325_TheLottery.in", "r", stdin);
        freopen("UVa10325_TheLottery.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}