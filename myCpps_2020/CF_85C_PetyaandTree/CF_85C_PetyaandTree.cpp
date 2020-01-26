/*
===========================================================
* @Name:           85C Petya and Tree
* @Author:         Shawn
* @create Time:    2020/1/26 17:47:06
* @url:            https://codeforces.com/contest/85/problem/C
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const ill inf = LLONG_MAX / 2;

void dfsNO1(ill u, vector<ill> &minE, vector<ill> &maxE, vector<ill> &a, vector<ill> &lch, vector<ill> &rch)
{
    if (lch[u] == -1)
    {
        minE[u] = a[u];
        maxE[u] = a[u];
    }
    else
    {
        dfsNO1(lch[u], minE, maxE, a, lch, rch);
        dfsNO1(rch[u], minE, maxE, a, lch, rch);

        minE[u] = minE[lch[u]];
        maxE[u] = maxE[rch[u]];
    }
}

void dfsNO2(ill u, vector<ill> &f, vector<ill> &depth, vector<ill> &minE, vector<ill> &maxE, vector<ill> &a, vector<ill> &lch, vector<ill> &rch)
{
    if (lch[u] == -1) return;
    
    depth[lch[u]] = depth[u] + 1;
    depth[rch[u]] = depth[u] + 1;

    f[lch[u]] = f[u] + minE[rch[u]];
    f[rch[u]] = f[u] + maxE[lch[u]];

    dfsNO2(lch[u], f, depth, minE, maxE, a, lch, rch);
    dfsNO2(rch[u], f, depth, minE, maxE, a, lch, rch);
}

void solve()
{
    ill n; cin >> n;

    ill rot = -1;
    vector<ill> a(n + 1, 0), lch(n + 1, -1), rch(n + 1, -1);
    vector<pair<ill, ill>> allNod;
    for (ill u = 1; u <= n; ++u)
    {
        ill las; cin >> las >> a[u];
        allNod.push_back({a[u], u});

        if (las == -1)
        {
            rot = u;
        }
        else
        {
            if (lch[las] == -1) lch[las] = u;
            else                rch[las] = u;

            if (a[lch[las]] > a[rch[las]]) swap(lch[las], rch[las]);
        }
    }
    sort(allNod.begin(), allNod.end());

    vector<ill> minE(n + 1, inf), maxE(n + 1, 0);
    dfsNO1(rot, minE, maxE, a, lch, rch);

    vector<ill> f(n + 1, 0), depth(n + 1, 0);
    dfsNO2(rot, f, depth, minE, maxE, a, lch, rch);

    
    ill q; cin >> q;
    for (ill c = 1; c <= q; ++c)
    {
        ill x; cin >> x;

        auto ite = upper_bound(allNod.begin(), allNod.end(), make_pair(x, -1 * inf));

        if (ite == allNod.end()) --ite;
        if (lch[ite->second] >= 1) --ite;

        ill u = ite->second;
        cout << (double)(f[u]) / (double)(depth[u]) << '\n';
    }
}

int main()
{
    cout << fixed << setprecision(10);

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_85C_PetyaandTree.in", "r", stdin);
        freopen("CF_85C_PetyaandTree.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}