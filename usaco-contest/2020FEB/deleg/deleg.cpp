#include <bits/stdc++.h>

using namespace std;

ifstream fin("deleg.in");
ofstream fout("deleg.out");

bool dfs(int u, int lst, int k, vector<int> &f, vector<vector<int>> &g)
{
    int siz = g[u].size();
    set<int> child;
    vector<int> child_cnt(k + 1, 0);
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];
        if (v != lst)
        {
            bool res = dfs(v, u, k, f, g);
            if (res == false) return false;

            ++child_cnt[f[v] + 1];
            child.insert(f[v] + 1);
        }
    }

    if (u == 12 && k == 2)
    {
        for (int __s = 0; __s == 0; ++__s);
    }

    siz = child.size();
    if (siz > 0)
    {
        if (siz == 1)
        {
            int tmp = *child.begin();

            if (tmp == k) f[u] = 0;
            else if (tmp * 2 == k)
            {
                if (child_cnt[tmp] % 2 == 0) f[u] = 0;
                else                         f[u] = tmp;
            }
            else if (child_cnt[tmp] > 1)
            {
                return false;
            }
            else
            {
                f[u] = tmp;
            }
        }
        else
        {
            for (auto it = child.begin(); it != child.end(); ++it)
            {
                int now = *it, ned = k - now;

                if (now == k || now == 0 || child_cnt[now] == 0) continue;

                if (abs(child_cnt[now] - child_cnt[ned]) == 1)
                {
                    if (f[u] != -1) return false;

                    if (child_cnt[now] > child_cnt[ned])
                    {
                        f[u] = now;
                        child_cnt[max(now, ned)] = 0;
                    }
                    else
                    {
                        f[u] = ned;
                        child_cnt[max(now, ned)] = 0;
                    }
                }
                else if (child_cnt[now] == child_cnt[ned])
                {
                    if (now == ned)
                    {
                        if (child_cnt[now] % 2 == 0)
                        {
                            f[u] = 0;
                            return true;
                        }
                        else
                        {
                            if (f[u] != -1) return false;
                            f[u] = now;
                        }
                    }
                    else
                    {
                        f[u] = 0;
                        return true;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else
    {
        f[u] = 0;
    }

    return true;
}

int main()
{
    int n; fin >> n;

    vector<vector<int>> g(n + 1);
    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; fin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    fout << 1;
    for (int k = 2; k <= n - 1; ++k)
    {
        if ((n - 1) % k > 0)
        {
            fout << '0'; continue;
        }

        vector<int> f(n + 1, -1);
        
        fout << dfs(1, 0, k, f, g);
    }
    fout << '\n';

    return 0;
}
