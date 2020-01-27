/*
===========================================================
* @Name:           468B Two Sets
* @Author:         Shawn
* @create Time:    2020/1/27 13:39:02
* @url:            https://codeforces.com/contest/468/problem/B
* @Description:    bitset
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxN = 1e9 + 1;

int fnd(int x, vector<int> &grp)
{
    if (grp[x] == x)
    {
        return x;
    }
    else
    {
        int res = fnd(grp[x], grp);
        grp[x] = res;

        return res;
    }
}

void solve()
{
    int n, a, b; cin >> n >> a >> b;

    vector<int> v(n + 1, 0);
    map<int, int> f;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];

        f[v[i]] = i;
    }

    vector<int> grp(n + 3, -1);
    for (int i = 1; i <= n + 2; ++i)
    {
        grp[i] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (f.count(a - v[i]) > 0) grp[fnd(i, grp)] = grp[fnd(f[a - v[i]], grp)];
        else                       grp[fnd(i, grp)] = grp[fnd(n + 2, grp)];

        if (f.count(b - v[i]) > 0) grp[fnd(i, grp)] = grp[fnd(f[b - v[i]], grp)];
        else                       grp[fnd(i, grp)] = grp[fnd(n + 1, grp)];
    }

    if (fnd(n + 1, grp) == fnd(n + 2, grp))
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i)
        {
            if (i > 1) cout << ' ';
            cout << (fnd(i, grp) != fnd(n + 1, grp));
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_468B_TwoSets.in", "r", stdin);
        freopen("CF_468B_TwoSets.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}