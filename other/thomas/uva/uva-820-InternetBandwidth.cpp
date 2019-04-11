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
            //cout << new_flow << " ";
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
    //vector<vector<int>> * bandwidth;
    vector<vector<int>> levelGraph;
    int n;          //图的顶点数
    int s;          //源点
    int t;          //汇点

    int dfs(int curr,int flow, const vector<int> & level,vector<int> & parent)
    {
        if(curr==t)
        {
            return flow;
        }

        for (int i = 1; i <= n ; ++i)
        {
            if( curr != i  
            && levelGraph[curr][i] >0           //联通
            && level[i]==level[curr]+1)         //是分层图的下一层 
            {
                flow = min(flow, levelGraph[curr][i]);
                parent[i] = curr;

                int result = dfs(i, flow, level, parent);
                if(result >0)
                {
                    // levelGraph[curr][i] -= result;
                    // levelGraph[i][curr] += result;
                    return result;
                }
            }
        }

        return 0;
    }

    bool bfs_LevelGraph(vector<int> & level)
    {
        vector<int> visted(n + 1, false);
        //visted[s]=true;
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next = 1; next <= n; ++next)
            {
                if (levelGraph[cur][next] > 0 
                && cur != next 
                //&& visted[next] == false 
                && level[next]<0)
                {
                    //visted[next] = true;
                    level[next] = level[cur] + 1;
                    if (next == t)
                    {
                        return true;
                    }
                    q.push(next);
                }
            }
        }
        if (level[t] > 0)
            return true;
        else
            return false;   //汇点的level小于零,表明BFS不到汇点 
    }

  public:
    Dinic(vector<vector<int>> * bandwidth1, int size1)
    {
        levelGraph = *bandwidth1;
        this->n = size1;

    }

    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;

        int totalFlow = 0;
        
        
        while (true)
        {
            //建立分层网络
            vector<int> level(n + 1, -1);
            //memset(&level[0], -1, sizeof(level[0]) * level.size());

            bool result = bfs_LevelGraph(level);
            if(result==false)
            {
                //分层网络无法到汇点
                break;
            }

            //寻找增广路
            vector<int> parent(n + 1, -1);
            //memset(&parent[0], -1, sizeof(parent[0]) * parent.size());
            parent[s]=-2;
            int new_flow = dfs(s,INF,level,parent);
            if (new_flow == 0)
            {
                //没有路到达t
                break;
            }
            cout << new_flow << " ";

            totalFlow += new_flow;
            int cur = t;
            while (cur != s)
            {
                int prev = parent[cur];
                levelGraph[prev][cur] -= new_flow;
                levelGraph[cur][prev] += new_flow;
                cur = prev;
            }

            // for (auto i : level)
            // {
            //     cout << i << " ";
            // }

        }

        return totalFlow;
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
