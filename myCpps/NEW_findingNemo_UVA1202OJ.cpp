#include <bits/stdc++.h>

using namespace std;


const int maxP = 201, inf = INT_MAX / 4;

bool g(int x, int y)
{
    return x >= 0 && x <= maxP && y >= 0 && y <= maxP;
}

struct segment
{
    int x;
    int y;
    int d;

    bool operator<(const segment & temp) const
    {
        return d > temp.d;
    }
};
segment _segment(int x, int y, int d)
{
    segment temp{x, y, d}; return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<int> xp = {0, 1, 0, -1},
                yp = {1, 0, -1, 0};

    while (true)
    {
        int wc = -1, dc = -1; cin >> wc >> dc;
        if (wc == -1) break;

        vector<vector<vector<int>>> a(maxP + 1, vector<vector<int>> (maxP + 1, vector<int>(4, 0)));
        for (int x = 0; x <= maxP; x += maxP)
        {
            for (int y = 0; y <= maxP; y += maxP)
            {
                for (int p = 0; p <= 3; ++p)
                {
                    if (g(x + xp[p], y + yp[p]) == false)
                    {
                        a[x][y][p] = inf;
                    }
                }
            }
        }

        for (int c = 1; c <= wc; ++c)
        {
            int x, y, d, t; cin >> x >> y >> d >> t;
            ++x; ++y;

            if (x == 1 || x == maxP || y == 1 || y == maxP) continue;

            if (d == 0)
            {
                for (int nowX = x; nowX <= x + t - 1; ++nowX)
                {
                    a[nowX][y][2] = inf;
                    a[nowX][y - 1][0] = inf;
                }
            }
            else
            {
                for (int nowY = y; nowY <= y + t - 1; ++nowY)
                {
                    a[x][nowY][3] = inf;
                    a[x - 1][nowY][1] = inf;
                }
            }
        }

        for (int c = 1; c <= dc; ++c)
        {
            int x, y, d; cin >> x >> y >> d;
            ++x; ++y;

            if (x == 1 || x == maxP || y == 1 || y == maxP) continue;

            if (d == 0)
            {
                a[x][y][2] = 1;
                a[x][y - 1][0] = 1;
            }
            else
            {
                a[x][y][3] = 1;
                a[x - 1][y][1] = 1;
            }
        }

        double nx_d, ny_d; cin >> nx_d >> ny_d;
        int nx = floor(nx_d), ny = floor(ny_d);
        ++nx; ++ny;

        if (g(nx, ny) == false)
        {
            cout << "0\n";
            continue;
        }

        vector<vector<int>> dp(maxP + 1, vector<int>(maxP + 1, inf));
        priority_queue<segment> pq; pq.push(_segment(1, 1, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.d >= dp[now.x][now.y]) continue;

            dp[now.x][now.y] = now.d;

            if (now.x == nx && now.y == ny)
            {
                break;
            }

            for (int p = 0; p <= 3; ++p)
            {
                segment next;
                next.x = now.x + xp[p];
                next.y = now.y + yp[p];
                next.d = now.d + a[now.x][now.y][p];

                if (g(next.x, next.y) == true && a[now.x][now.y][p] <= 1)
                {
                    pq.push(next);
                }
            }
        }

        if (dp[nx][ny] < inf)
        {
            cout << dp[nx][ny] << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }

   	cout.flush();
   	return 0;
}

