#include <bits/stdc++.h>

using namespace std;


const int N = 2000;
const int maxD = N + N + 1;

struct point
{
    int x;
    int y;
};
point _point(int x, int y)
{
    point temp{x, y}; return temp;
}

bool g(int x, int y, int maxX, int maxY)
{
    return x >= 0 && x <= maxX && y >= 0 && y <= maxY;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<int> xP = {-1, 1, 0, 0},
                yP = {0, 0, -1, 1};

    while (true)
    {
        int p1; cin >> p1;
        if (p1 == 0) break;

        int maxX = 0, maxY = 0;

        vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
        vector<vector<char>> type(N + 1, vector<char>(N + 1, -1));
        vector<vector<int>> d(N + 1, vector<int>(N + 1, maxD));

        vector<point> mall0(p1);
        for (int i = 0; i <= p1 - 1; ++i)
        {
            cin >> mall0[i].x >> mall0[i].y;

            type[mall0[i].x][mall0[i].y] = 0;
            d[mall0[i].x][mall0[i].y] = 0;

            maxX = max(maxX, mall0[i].x); maxY = max(maxY, mall0[i].y);
        }

        int p2; cin >> p2;
        vector<point> mall1(p2);
        for (int i = 0; i <= p2 - 1; ++i)
        {
            cin >> mall1[i].x >> mall1[i].y;
            type[mall1[i].x][mall1[i].y] = 1;

            maxX = max(maxX, mall1[i].x); maxY = max(maxY, mall1[i].y);
        }

        int ans = maxD;

        queue<point> q;
        q.push(mall0[0]);
        visit[mall0[0].x][mall0[0].y] = true;

        while (q.empty() == false)
        {
            point now = q.front();
            q.pop();


            for (int _p = 0; _p <= 3; ++_p)
            {
                point next;
                next.x = now.x + xP[_p];
                next.y = now.y + yP[_p];

                if (g(next.x, next.y, maxX, maxY) == false)
                {
                    continue;
                }
                else if (type[next.x][next.y] == 1)
                {
                    ans = min(ans, d[now.x][now.y] + 1);
                    continue;
                }

                if (d[next.x][next.y] > d[now.x][now.y] + 1)
                {
                    d[next.x][next.y] = d[now.x][now.y] + 1;
                }
                else if (visit[next.x][next.y] == true)
                {
                    continue;
                }

                visit[next.x][next.y] = true;

                q.push(next);
            }
        }

        cout << ans << '\n';
    }
    

   	cout.flush();
   	return 0;
}

