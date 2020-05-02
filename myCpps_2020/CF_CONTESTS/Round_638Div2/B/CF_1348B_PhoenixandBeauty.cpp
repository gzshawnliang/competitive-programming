/*
===========================================================
* @Name:           1348B Phoenix and Beauty
* @Author:         Shawn
* @create Time:    2020/5/1 22:35:42
* @url:            https://codeforces.com/contest/1348/problem/B
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxX = 100;

void solve()
{
    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        int n, k; cin >> n >> k;

            vector<int> a(n);
            set<int> s;
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i]; s.insert(a[i]);
        }

        for (int x = 1; x <= maxX && s.size() < k; ++x)
        {
            s.insert(x);
        }

        if (s.size() > k)
        {
            cout << "-1\n";
            continue;
        }
        else
        {
            int tolL = 10000 / k;

            cout << k * tolL << '\n';
            for (int c = 1; c <= tolL; ++c)
            {
                for (auto x:s) cout << x << ' ';
            }
            cout << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1348B_PhoenixandBeauty.in", "r", stdin);
        freopen("CF_1348B_PhoenixandBeauty.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}