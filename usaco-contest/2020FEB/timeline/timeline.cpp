#include <bits/stdc++.h>

using namespace std;

ifstream fin("timeline.in");
ofstream fout("timeline.out");

int main()
{
    int n, maxN, m; fin >> n >> maxN >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int tmp; fin >> tmp;
        g[0].push_back({i, tmp});
    }

    for (int c = 1; c <= m; ++c)
    {
        int u, v, d; fin >> u >> v >> d;
        g[u].push_back({v, d});
    }

    vector<int> num(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; q.push({0, 0});
    
    while (q.empty() == false)
    {
        pair<int, int> now = q.top();
        q.pop();

        for (auto it = g[now.second].begin(); it != g[now.second].end(); ++it)
        {
            pair<int, int> nxt = {now.first + it->second, it->first};

            if (num[nxt.second] < nxt.first)
            {
                num[nxt.second] = nxt.first;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        fout << num[i] <<'\n';
    }

    return 0;
}
