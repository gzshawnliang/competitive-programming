#include <bits/stdc++.h>

using namespace std;


struct segment
{
    int t;
    int num;
};
segment _segment(int t, int num)
{
    segment temp{t, num}; return temp;
}

bool g0(int x, int y, int nx, int ny)
{
    return x >= 0 && x <= nx - 1 && y >= 0 && y <= ny - 1;
}

bool g1(int num, int nx, int ny)
{
    return num >= 0 && num <= nx * ny - 1;
}

int turn(int x, int y, int nx, int ny)
{
    return y * nx + x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<int> xP = {-1, 1, 0, 0},
                yP = {0, 0, -1, 1};

    while (true)
    {
        int nx = 0, ny = 0; cin >> nx >> ny;
        if (nx + ny == 0) break;

        vector<int> numP = {-nx, -1, nx, 1};

        vector<vector<bool>> a(nx * ny, vector<bool>(nx * ny, false));
        for (int y = 0; y <= ny - 1; ++y)
        {
            for (int x = 0; x <= nx - 1; ++x)
            {
                for (int p = 0; p <= 3; ++p)
                {
                    int nextX = x + xP[p],
                        nextY = y + yP[p];

                    if (g0(nextX, nextY, nx, ny) == true)
                    {
                        a[turn(x, y, nx, ny)][turn(nextX, nextY, nx, ny)] = true;
                    }
                }
            }
        }

        int r; cin >> r;
        for (int c = 1; c <= r; ++c)
        {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            a[turn(x1, y1, nx, ny)][turn(x2, y2, nx, ny)] = false;
        }

        int m; cin >> m;
        vector<int> pass(nx * ny * 100, -1);
        for (int c = 1; c <= m; ++c)
        {
            int t, x, y; cin >> t >> x >> y;
            
            pass[t] = turn(x, y, nx, ny);
        }

        queue<segment> q; q.push(_segment(0, turn(0, 0, nx, ny)));
        vector<bool> visit(nx * ny, false);

        int ans = -1;
        while (q.empty() == false && ans == -1)
        {
            segment now = q.front(); q.pop();

            if (now.num == turn(nx - 1, ny - 1, nx, ny))
            {
                ans = now.t;
                break;
            }

            visit[now.num] = true;
            
            for (int p = 0; p <= 3; ++p)
            {
                segment next;
                next.t = now.t + 1;
                next.num = now.num + numP[p];

                if (g1(next.num, nx, ny) == false)
                {
                    continue;
                }
                else if (a[now.num][next.num] == false)
                {
                    continue;
                }
                else if (visit[next.num] == true)
                {
                    continue;
                }
                else if (pass[next.t] == next.num)
                {
                    continue;
                }
                
                q.push(next);
            }

            if (pass[now.t + 1] != now.num)
            {
                q.push(_segment(now.t + 1, now.num));
            }
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
