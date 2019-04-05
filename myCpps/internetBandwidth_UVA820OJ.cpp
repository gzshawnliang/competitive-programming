#include <bits/stdc++.h>

using namespace std;


int solve(int start, int end, vector<bool> & visit, vector<vector<int>> & a, vector<vector<int>> & g)
{
    int n = a.size() - 1;

    queue<int> q;
    vector<int> f(n + 1, -1);

    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == end)
        {
            int _min = INT_MAX;

            int now = end;
            while (now != start)
            {
                _min = min(_min, a[now][f[now]]);

                now = f[now];
            }

            now = end;
            while (now != start)
            {
                a[now][f[now]] -= _min;
                a[f[now]][now] -= _min;

                now = f[now];
            }

            return _min;
        }

        int size = g[u].size();
        for (int i = 0; i <= size - 1; ++i)
        {
            int v = g[u][i];

            if (a[u][v] <= 0 || visit[v] == true) continue;

            visit[v] = true;
            f[v] = u;
            q.push(v);
        }
    }

    return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int t = 0;
    while (true)
    {
        int n = 0;
        cin >> n;
        if (n == 0) break;

        ++t;

        int start, end, m; cin >> start >> end >> m;

        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0)), g(n + 1);
        for (int c = 1; c <= m; ++c)
        {
            int u, v, w; cin >> u >> v >> w;

            if (a[u][v] == 0)
            {
                g[u].push_back(v); g[v].push_back(u);
            }

            a[u][v] += w; a[v][u] += w;
        }
        
        int ans = 0;
        vector<bool> visit(n + 1, false);

        while (true)
        {
            int res = solve(start, end, visit, a, g);
            if (res == -1) break;

            ans += res;

            for (int i = 1; i <= n; ++i)
            {
                visit[i] = false;
            }
        }

        cout << "Network " << t << '\n';
        cout << "The bandwidth is " << ans << ".\n\n";
    }

   	cout.flush();
   	return 0;
}

