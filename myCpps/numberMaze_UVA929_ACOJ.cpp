#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;


const int INF = 1000000;

struct node
{
    int y;
    int x;
    int w;

    bool operator<(const node & temp) const
    {
        return w > temp.w;
    }
};

bool g(int y, int x, int n, int m)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= m - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, m, first;
        cin >> n >> m;

        vector<vector<bool>> visit(n, vector<bool>(m, false));
        vector<vector<int>> dp(n, vector<int>(m, INF)), a(n, vector<int>(m));

        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                cin >> a[y][x];
            }
        }
        dp[0][0] = a[0][0];

        priority_queue<node> q;
        node start{0, 0, a[0][0]};
        q.push(start);
        while (!q.empty())
        {
            node now = q.top();
            q.pop();
            if (visit[now.y][now.x] == false)
            {
                visit[now.y][now.x] = true;

                for (int i = 0; i <= 3; ++i)
                {
                    node next{now.y + move[i][0], now.x + move[i][1], 0};
                    if (g(next.y, next.x, n, m) == true)
                    {
                        if (visit[next.y][next.x] == false)
                        {
                            next.w = dp[now.y][now.x] + a[next.y][next.x];
                            if (next.w < dp[next.y][next.x])
                            {
                                dp[next.y][next.x] = next.w;
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }

        cout << dp[n - 1][m - 1] << '\n';
    }

   	cout.flush();
   	return 0;
}
