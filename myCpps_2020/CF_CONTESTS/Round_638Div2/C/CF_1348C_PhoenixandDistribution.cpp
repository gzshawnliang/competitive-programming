/*
===========================================================
* @Name:           1348C Phoenix and Distribution
* @Author:         Shawn
* @create Time:    2020/5/1 22:35:42
* @url:            https://codeforces.com/contest/1348/problem/C
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        int n, k; cin >> n >> k;

        string s; cin >> s;
        sort(s.begin(), s.end());

        set<char> st1;
        for (int i = 0; i <= k - 1; ++i) st1.insert(s[i]);

        if (st1.size() > 1)
        {
            cout << *st1.rbegin() << '\n';
        }
        else
        {
            string ans = "";
            ans += *st1.begin();

            set<char> st2;
            for (int i = k; i <= n - 1; ++i) st2.insert(s[i]);
            
            if (st2.size() > 1)
            {
                for (int i = k; i <= n - 1; ++i) ans += s[i];
                cout << ans << '\n';
            }
            else
            {
                int tol = (n - k) / k;
                    if ((n - k) % k > 0) ++tol;

                for (int c = 1; c <= tol; ++c) ans += s[k];
                
                cout << ans << '\n';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1348C_PhoenixandDistribution.in", "r", stdin);
        freopen("CF_1348C_PhoenixandDistribution.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}