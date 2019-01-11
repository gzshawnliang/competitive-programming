#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <vector>

using namespace std;


const int INF = 1000000;

struct node
{
    int u;
    int w;

    bool operator<(const node & temp) const
    {
        return w > temp.w;
    }
};

void trans(int u, int & _count, vector<int> & index)
{
    if (index[u] == -1)
    {
        ++_count;
        index[u] = _count;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, m, ts, te, _count = -1; cin >> n >> m >> ts >> te;

        vector<int> dis(n, INF), index(n, -1);
        vector<vector<int>> dp(n, vector<int>(m, INF)), g(n);

        trans(ts, _count, index);
        trans(te, _count, index);
        int s = index[ts], e = index[te];

        for (int c = 1; c <= m; ++c)
        {
            int tu, t1, w;
            cin >> tu >> t1 >> w;

            trans(tu, _count, index);
            trans(t1, _count, index);
            int u = index[tu], v = index[t1];

            dp[u][v] = min(dp[u][v], w); dp[v][u] = min(dp[v][u], w);
            g[u].push_back(v); g[v].push_back(u);
        }

        vector<bool> visit(n, false);
        priority_queue<node> q;

        dis[s] = 0;
        node start{s, 0};
        q.push(start);
        
        for (int c = 1; c <= n - 1; ++c)
        {
            if (q.empty() == true)
            {
                break;
            }

            int u = q.top().u;
            while (visit[u] == true && q.empty() == false)
            {
                q.pop();
                u = q.top().u;
            }

            visit[u] = true;
            
            int size = g[u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g[u][i];
                if (visit[v] == false && dis[v] > dis[u] + dp[u][v])
                {
                    dis[v] = dis[u] + dp[u][v];

                    node temp{v, dis[v]};
                    q.push(temp);
                }
            }
        }

        cout << "Case #" << t << ": ";
        if (dis[e] >= INF)
        {
            cout << "unreachable\n";
        }
        else
        {
            cout << dis[e] << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
