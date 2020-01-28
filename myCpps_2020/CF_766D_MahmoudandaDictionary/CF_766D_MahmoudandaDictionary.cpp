/*
===========================================================
* @Name:           766D Mahmoud and a Dictionary
* @Author:         Shawn
* @create Time:    2020/1/28 12:45:22
* @url:            https://codeforces.com/contest/766/problem/D
* @Description:    
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int fnd(int x, vector<int> &f)
{
    if (x == -1) return -1;

    if (f[x] == x) return x;
    else return f[x] = fnd(f[x], f);
}

void solve()
{
    int n, m, q; cin >> n >> m >> q;

    vector<string> its(n);
    map<string, int> sti;

    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> its[i]; sti[its[i]] = i;
    }

    vector<int> f(n), opp(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        f[i] = i;
        opp[i] = -1;
    }

    for (int c = 1; c <= m; ++c)
    {
        int t;
        string str1, str2;
        cin >> t >> str1 >> str2;

        int x = fnd(sti[str1], f), y = fnd(sti[str2], f);

        int xp = fnd(opp[x], f), yp = fnd(opp[y], f);

        if (t == 1)
        {
            if (xp == y || yp == x)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";

                f[x] = y;

                if (xp >= 0 && yp >= 0) f[xp] = yp;
                if (yp == -1) opp[y] = xp;
            }
        }
        else
        {
            if (x == y)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";

                if (xp >= 0) f[y] = xp;
                else         opp[x] = y;

                if (yp >= 0) f[x] = yp;
                else         opp[y] = x;
            }
        }
    }

    for (int c = 1; c <= q; ++c)
    {
        string str1, str2; cin >> str1 >> str2;

        int x = sti[str1], y = sti[str2];
        x = fnd(x, f); y = fnd(y, f);

        int xp = fnd(opp[x], f), yp = fnd(opp[y], f);

        if      (x == y)             cout << "1\n";
        else if (yp == x || xp == y) cout << "2\n";
        else                         cout << "3\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_766D_MahmoudandaDictionary.in", "r", stdin);
        freopen("CF_766D_MahmoudandaDictionary.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}