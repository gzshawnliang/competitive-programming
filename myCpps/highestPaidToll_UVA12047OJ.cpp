#include <bits/stdc++.h>

using namespace std;


const int inf = INT_MAX / 2;

struct segment
{
    int u;
    int p;

    bool operator < (const segment & temp) const
    {
        return p > temp.p;
    }
};
segment _segment(int u, int p)
{
    segment temp{u, p}; return temp;
}

struct edge
{
    int u;
    int v;
};
edge _edge(int u, int v)
{
    edge temp{u, v}; return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n, m, s, e, pMax; cin >> n >> m >> s >> e >> pMax;
        
        vector<edge> edges(m);
        vector<vector<int>> a(n + 1, vector<int>(n + 1, -1)),
                            g(n + 1),
                            gr(n + 1);

        for (int i = 0; i <= m - 1; ++i)
        {
            int u, v, p; cin >> u >> v >> p;

            edges[i] = _edge(u, v);

            a[u][v] = p;
            g[u].push_back(v);
            gr[v].push_back(u);
        }

        bool isFirstS = true;
        vector<int> dS(n + 1, inf); dS[s] = 0;
        priority_queue<segment> pqS; pqS.push(_segment(s, 0));
        while (pqS.empty() == false)
        {
            segment now = pqS.top(); pqS.pop();

            if (now.p >= dS[now.u] && isFirstS == false) continue;
            isFirstS = false;
            dS[now.u] = now.p;

            int size = g[now.u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g[now.u][i];

                pqS.push(_segment(v, now.p + a[now.u][v]));
            }
        }

        for (int __s = 0; __s == 0; ++__s);

        bool isFirstE = true;
        vector<int> dE(n + 1, inf); dE[e] = 0;
        priority_queue<segment> pqE; pqE.push(_segment(e, 0));
        while (pqE.empty() == false)
        {
            segment now = pqE.top(); pqE.pop();

            if (now.p >= dE[now.u] && isFirstE == false) continue;
            isFirstE = false;
            dE[now.u] = now.p;

            int size = gr[now.u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = gr[now.u][i];

                pqE.push(_segment(v, now.p + a[v][now.u]));
            }
        }

        int ans = -1;
        for (int i = 0; i <= m - 1; ++i)
        {
            edge nowEdge = edges[i];

            if (dS[nowEdge.u] + a[nowEdge.u][nowEdge.v] + dE[nowEdge.v] <= pMax)
            {
                ans = max(ans, a[nowEdge.u][nowEdge.v]);
            }
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

