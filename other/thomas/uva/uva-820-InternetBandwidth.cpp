#include <bits/stdc++.h>

using namespace std;

ifstream fin("uva-820-InternetBandwidth.in");
ofstream fout("uva-820-InternetBandwidth.out");

const int INF = INT_MAX / 2;

class EdmondsKarp
{

  private:
    vector<vector<int>> * bandwidth;
    int n;

    int bfs(int s, int t, vector<int> & parent)
    {
        //vector<vector<int>> bandwidth = *a;
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INF});

        while (!q.empty())
        {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next = 1; next <= n; ++next)
            {
                if (parent[next] == -1 && (*bandwidth)[cur][next] > 0 && cur != next)
                {
                    parent[next] = cur;
                    int new_flow = min(flow, (*bandwidth)[cur][next]);
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

  public:
    EdmondsKarp(vector<vector<int>> * bandwidth1, int size1)
    {
        this->n = size1;
        this->bandwidth = bandwidth1;
    }

    int Maxflow(int s, int t)
    {
        int flow = 0;

        while (true)
        {
            vector<int> parent(n + 1, -1);
            int new_flow = bfs(s, t, parent);
            if (new_flow == 0)
            {
                break;
            }
            flow += new_flow;
            int cur = t;
            while (cur != s)
            {
                int prev = parent[cur];
                (*bandwidth)[prev][cur] -= new_flow;
                (*bandwidth)[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};

class Dinic
{
  private:
    vector<vector<int>> * bandwidth;
    vector<vector<int>>  levelGraph;
    int n;

    void bfs(int s, int t, vector<int> & level)
    {
        vector<int> visted(n + 1, false);
        visted[s]=true;
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next = 1; next <= n; ++next)
            {
                if ((*bandwidth)[cur][next] > 0 && cur != next && visted[next] == false)
                {
                    visted[next] = true;
                    level[next] = level[cur] + 1;
                    if (next == t)
                    {
                        return;
                    }
                    q.push(next);
                }
            }
        }
    }

  public:
    Dinic(vector<vector<int>> * bandwidth1, int size1)
    {
        this->n = size1;
        this->bandwidth = bandwidth1;
        levelGraph= * bandwidth1;
    }

    int Maxflow(int s, int t)
    {
        int flow = 0;

        while (true)
        {
            vector<int> level(n + 1, -1);
            bfs(s, t, level);
            // int new_flow = 0;
            // if (new_flow == 0)
            // {
            //     break;
            // }
            // flow += new_flow;
            // int cur = t;
            // while (cur != s)
            // {
            //     int prev = level[cur];
            //     (*bandwidth)[prev][cur] -= new_flow;
            //     (*bandwidth)[cur][prev] += new_flow;
            //     cur = prev;
            // }
            for (auto i : level)
            {
                cout << i << " ";
            }
            break;
        }

        return flow;
    }
};

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
        // EdmondsKarp EdmondsKarp1(&a,n);
        // int ans = EdmondsKarp1.Maxflow(s, t);

        Dinic Dinic1(&a, n);
        int ans = Dinic1.Maxflow(s, t);

        fout << "Network " << caseId << '\n';
        fout << "The bandwidth is " << ans << ".\n\n";
        ++caseId;
    }

    return 0;
}
