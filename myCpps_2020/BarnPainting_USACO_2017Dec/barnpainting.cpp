#include <bits/stdc++.h>

using namespace std;

ifstream fin("barnpainting.in");
ofstream fout("barnpainting.out");

using ll = long long;

const ll mod = 1e9 + 7;

void dfs(ll u, vector<ll> &visit, vector<ll> &fixed, vector<vector<ll>> &f, vector<vector<ll>> &g)
{
    visit[u] = 1;

    ll size = g[u].size();
    for (ll i = 0; i <= size - 1; ++i)
    {
        ll v = g[u][i];

        if (visit[v] == 0)
        {
            dfs(v, visit, fixed, f, g);

            if (u == 1)
            {
                for (ll __s = 0; __s == 0; ++__s);
            }

            if (fixed[u] == 0)
            {
                for (ll coU = 1; coU <= 3; ++coU)
                {
                    ll res = 0;
                    for (ll coV = 1; coV <= 3; ++coV)
                    {
                        if (coV != coU)
                        {
                            res = (res + f[v][coV]) % mod;
                        }
                    }

                    f[u][coU] = (f[u][coU] * res) % mod;
                }
            }
            else
            {
                ll res = 0;
                for (ll coV = 1; coV <= 3; ++coV)
                {
                    if (coV != fixed[u])
                    {
                        res = (res + f[v][coV]) % mod;
                    }
                }

                f[u][fixed[u]] = (f[u][fixed[u]] * res) % mod;
            }
        }
    }
}

int main()
{
    ll n, m; fin >> n >> m;

    vector<vector<ll>> g(n + 1);
    for (ll c = 1; c <= n - 1; ++c)
    {
        ll u, v; fin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> visit(n + 1, 0), fixed(n + 1, 0);
    vector<vector<ll>> f(n + 1, vector<ll>(4, 1));

    for (ll c = 1; c <= m; ++c)
    {
        ll u, color; fin >> u >> color;

        fixed[u] = color;

        for (ll co = 1; co <= 3; ++co)
        {
            if (co != color) f[u][co] = 0;
        }
    }

    dfs(1, visit, fixed, f, g);
    fout << (f[1][1] + f[1][2] + f[1][3]) % mod << '\n';

    return 0;
}
