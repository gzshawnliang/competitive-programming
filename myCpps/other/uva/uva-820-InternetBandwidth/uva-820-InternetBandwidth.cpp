#include <bits/stdc++.h>

using namespace std;

ifstream fin("uva-820-InternetBandwidth.in");
ofstream fout("uva-820-InternetBandwidth.out");

const int INF = INT_MAX / 2;

class EdmondsKarp
{

  private:
    vector<vector<int>> bandwidth;
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
                if (parent[next] == -1 && bandwidth[cur][next] > 0 && cur != next)
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

  public:
    EdmondsKarp(vector<vector<int>> & sourGraph, int size1)
    {
        this->n = size1;
        this->bandwidth = sourGraph;
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
                bandwidth[prev][cur] -= new_flow;
                bandwidth[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};

class Dinic
{
  private:
    vector<vector<int>> levelGraph;

    int n; //图的顶点数
    int s; //源点
    int t; //汇点

    //dfs代表一次增广,函数返回本次增广的流量,返回0表示无法增广
    int dfs(int curr, int flow, const vector<int> & level)
    {
        if (curr == t)
        {
            return flow;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (levelGraph[curr][i] > 0         //联通
                && level[i] == level[curr] + 1) //是分层图的下一层
            {
                int minflow = min(flow, levelGraph[curr][i]);

                int result = dfs(i, minflow, level);
                if (result > 0)         //能到汇点result > 0
                {
                    //回溯时候更改路径上的正向流和反向流
                    levelGraph[curr][i] -= result;
                    levelGraph[i][curr] += result;
                    return result;
                }
            }
        }
        return 0;
    }

    bool bfs_CreateLevelGraph(vector<int> & level)
    {
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next = 1; next <= n; ++next)
            {
                if (levelGraph[cur][next] > 0       //若该残量不为0
                    && level[next] < 0              //next还未分配层次
                )
                {
                    level[next] = level[cur] + 1;
                    q.push(next);
                }
            }
        }
        if (level[t] > 0)
            return true;
        else
            return false;//汇点的level小于零,表明BFS不到汇点
    }

  public:
    Dinic(vector<vector<int>> & sourGraph, int size1)
    {
        levelGraph = sourGraph;
        this->n = size1;
    }

    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;

        int totalFlow = 0;

        while (true)
        {
            //第i个节点的层次数组
            vector<int> level(n + 1, -1);

            //建立分层网络，无法到汇点停止
            bool result = bfs_CreateLevelGraph(level);
            if (result == false)
            {
                //分层网络无法到汇点
                break;
            }

            //dfs深度搜索寻找增广路，找不到停止循环
            int inf=INF;
            while (true)
            {
                int new_flow = dfs(s, inf, level);
                if (new_flow == 0)
                {
                    //找不到增广路退出
                    break;
                }
                else
                {
                    totalFlow += new_flow;
                }
                //cout << new_flow << " ";
            }
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

        // EdmondsKarp EdmondsKarp1(a, n);
        // int ans = EdmondsKarp1.Maxflow(s, t);

        Dinic Dinic1(a, n);
        int ans = Dinic1.Maxflow(s, t);

        fout << "Network " << caseId << '\n';
        fout << "The bandwidth is " << ans << ".\n\n";
        ++caseId;
    }

    return 0;
}
