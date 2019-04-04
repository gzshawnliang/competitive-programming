#include <bits/stdc++.h>

using namespace std;

ifstream fin("uva-820-InternetBandwidth.in");
ofstream fout("uva-820-InternetBandwidth.out");

const int INF = INT_MAX / 2;

int bfs(int s, int t,int n, vector<int> & parent, const vector<vector<int>> & bandwidth)
{
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next = 1; next <= n;++next)
        {
            if (parent[next] == -1 && bandwidth[cur][next]>0 && cur !=next)
            {
                parent[next] = cur;
                int new_flow = min(flow, bandwidth[cur][next]);
                if (next == t)
                {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow_EdmondsKarp(int s, int t, int n, vector<vector<int>> & bandwidth)
{
    int flow = 0;

    while (true)
    {
        vector<int> parent(n+1, -1);
        int new_flow = bfs(s, t,n, parent, bandwidth);
        if (new_flow == 0)
        {
            break;
        }
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            bandwidth[prev][cur] -= new_flow;
            bandwidth[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main()
{
    int n = 0;
    int caseId = 1;
    while (fin >> n)
    {
        if (n == 0)
        {
            break;
        }
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        int s = 0;
        int t = 0;
        int m = 0;
        fin >> s >> t >> m;

        for (int i = 0; i <= m - 1; ++i)
        {
            int u = 0;
            int v = 0;
            int c = 0;
            fin >> u >> v >> c;
            a[u][v] += c;
            a[v][u] += c;
        }
        int ans = maxflow_EdmondsKarp(s, t, n, a);

        fout << "Network " << caseId << '\n';
        fout << "The bandwidth is " << ans << ".\n\n";
        ++caseId;
    }

    return 0;
}
