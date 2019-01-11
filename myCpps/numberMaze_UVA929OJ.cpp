#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;


const int INF = 1000000;

struct node
{
    int b;
    int d;

    bool operator<(const node & temp) const
    {
        return d > temp.d;
    }
};

bool inRange(int a, int total)
{
    return a >= 1 && a <= total;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, m, total, first; cin >> n >> m;
        total = n * m;
        vector<vector<int>> dp(total + 1, vector<int>(total + 1, INF)), g(total + 1);

        for (int c0 = 0; c0 <= n - 1; ++c0)
        {
            for (int c1 = 1; c1 <= m; ++c1)
            {
                int now = c0 * m + c1, in;
                cin >> in;

                if (now == 1)
                {
                    first = in;
                }

                if (inRange(now - 1, total) == true && c1 != 1)
                {
                    dp[now][now - 1] = in;
                    dp[now - 1][now] = in;
                    g[now].push_back(now - 1);
                    g[now - 1].push_back(now);
                }
                if (inRange(now + 1, total) == true && c1 != m)
                {
                    dp[now][now + 1] = in;
                    dp[now + 1][now] = in;
                    g[now].push_back(now + 1);
                    g[now + 1].push_back(now);
                }
                if (inRange(now - m, total) == true)
                {
                    dp[now][now - m] = in;
                    dp[now - m][now] = in;
                    g[now].push_back(now - m);
                    g[now - m].push_back(now);
                }
                if (inRange(now + m, total) == true)
                {
                    dp[now][now + m] = in;
                    dp[now + m][now] = in;
                    g[now].push_back(now + m);
                    g[now + m].push_back(now);
                }
            }
        }

        vector<bool> visit(total + 1, false);
        vector<int> dis(total + 1, INF); dis[1] = 0;

        priority_queue<node> q;

        node temp0{1, 0};
        q.push(temp0);

        for (int c = 1; c <= total - 1; ++c)
        {
            if (q.empty() == true)
            {
                break;
            }

            int u = q.top().b;
            while (visit[u] == true && q.empty() == false)
            {
                q.pop();
                u = q.top().b;
            }

            visit[u] = true;

            int size0 = g[u].size();
            for (int i = 0; i <= size0 - 1; ++i)
            {
                int v = g[u][i];
                if (visit[v] == false && dis[v] > dis[u] + dp[u][v])
                {
                    dis[v] = dis[u] + dp[u][v];

                    node temp1{v, dis[v]};
                    q.push(temp1);
                }
            }
        }
        
        cout << dis[n * m] + first << '\n'; 
    }

   	cout.flush();
   	return 0;
}
