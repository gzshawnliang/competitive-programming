#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const int INF = INT_MAX;

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
                if (result > 0) //能到汇点result > 0
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
                if (levelGraph[cur][next] > 0 //若该残量不为0
                    && level[next] < 0        //next还未分配层次
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
            return false; //汇点的level小于零,表明BFS不到汇点
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
            int inf = INF;
            while (true)
            {
                int new_flow = dfs(s, inf, level);
                if (new_flow == 0)
                {
                    //找不到增广路退出
                    break;
                }
                else if (new_flow == INF)
                {
                    totalFlow = INF;
                }
                else
                {
                    totalFlow += new_flow;
                }
                //cout << new_flow << " ";
            }
            if (totalFlow == INF)
                break;
        }

        return totalFlow;
    }
};

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
            if (new_flow == INF)
            {
                return -1;
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



class solution
{
    vector<vector<int>> g;

  public:
    void solve(int caseId)
    {
        int N, H;
        cin >> N >> H;
        //起始点是1，终点是N+2，input点从2~N+1
        int source = 1;
        int target = N + 2;        
        vector<tuple<int, int, int>> ladder(N + 3);
        for (int i = 2; i <= N + 1; ++i)
        {
            int x, a, b;
            cin >> x >> a >> b;
            ladder[i] = {x, a, b};
        }
        sort(ladder.begin() + 2, ladder.end() - 1);

        // for (int i = 2; i <= N+1; ++i)
        // {
        //     auto [x, a, b] = ladder[i];
        //     x *=40;

        //     cout << "(" << x << "," << a  << ")\n";
        //     cout << "(" << x << "," << b  << ")\n";
        //     cout << i <<". SEGMENT((" << x << "," << a  << "),("<< x << "," << b << "))\n";

        //     cout << "\n";
        // }
        // cout << "------------------------\n";

        //建图
        g = vector<vector<int>>(N + 3, vector<int>(N + 3, -1));
        for (int i = 2; i <= N + 1; ++i)
        {
            auto [x1, A1, B1] = ladder[i];

            if (A1 == 0)
                g[source][i] = INF;

            if (B1 == H)
                g[i][target] = INF;

            /*
                情况1       情况2       情况3       情况4       情况5                情况6
                    b2          b2      b1         b1               b2          b1      
                    |           |       |   b2      |               |           |       
                b1  |       b1  |       |   |       |               |           |   b2
                |   |       |   |       |   |       |               |           |   |
                |   |       |   |       a1  |       a1              a2          |   |
                |   |       |   a2          a2                                  |   |
                a1  |       a1                          b2    b1                |   a2
                    a2                                  |     |                 |
                                                        |     |                 |
                                                        |     |                 a1
                                                        a2    a1
            */
           
            queue<tuple<int, int>> q;
            q.push({A1, B1});
            set<int> ignore;

            while (!q.empty())
            {
                auto [a1, b1] = q.front();
                q.pop();
                int next = i + 1;

                while (next <= N + 1 && b1 - a1 > 0)
                {
                    while (ignore.count(next) == 1)
                        ++next;

                    if (next > N + 1)
                        break;

                    auto [x2, a2, b2] = ladder[next];

                    int shadowLen =min(b1,b2)-max(a1,a2);       //第一个线段投影到第二个线段的长度

                    if (shadowLen <=0) //情况4,情况5
                    {
                        //do nothing
                    }
                    else
                    {
                        if (g[i][next] == -1)
                            g[i][next] = shadowLen;
                        else
                            g[i][next] += shadowLen;

                        //cout << i << "-" << next << ":" << g[i][next] <<endl;
                        g[next][i] = g[i][next];
                        
                        if (shadowLen == b1 - a2) //情况2,缩短线段
                        {
                            b1 = a2;
                        }
                        else if (shadowLen == b1 - a1) //情况1,不需要下个线段了，退出循环
                        {
                            break;
                        }
                        else if (shadowLen == b2 - a1) //情况3,缩短线段
                        {
                            a1 = b2;
                        }
                        else if (shadowLen == b2 - a2) //情况6,拆分两个线段
                        {
                            q.push({a1, a2});
                            q.push({b2, b1});
                            ignore.insert(next);
                            break;
                        }
                    }
                    ++next;
                }
            }
        }

        // for (int i = 1; i <= N+2; ++i)
        //     for (int j = 1; j <= N+2; ++j)
        //         if(g[i][j]>=0 && i!=j)
        //             cout << i << " " << j << " " << g[i][j] << "\n";

        // Dinic Dinic1(g, N + 2);
        // int ans = Dinic1.Maxflow(source, target);

        EdmondsKarp EdmondsKarp1(g, N+2);
        int ans = EdmondsKarp1.Maxflow(source, target);       

        cout << "Case #" << caseId << ": " << (ans == INF ? -1 : ans) << "\n";
        return;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("ladders_and_snakes.in", "r", stdin);
    //freopen("ladders_and_snakes2.out", "w", stdout);
    freopen("FB_2019_ROUND_1_CLaddersandSnakes.out", "w", stdout);
#endif
    int t;
    cin >> t;
    solution sln1;
    for (int i = 1; i <= t; ++i)
        sln1.solve(i);

    cout.flush();

    return 0;
}