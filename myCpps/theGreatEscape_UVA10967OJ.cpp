#include <bits/stdc++.h>

using namespace std;


const int inf = INT_MAX / 2;

struct point
{
    int y;
    int x;
};
point _point(int y, int x)
{
    point temp{y, x}; return temp;
}

struct segment
{
    point u;
    char direction;
    int t;

    bool operator < (const segment & temp) const
    {
        return t > temp.t;
    }
};
segment _segment(point u, char direction, int t)
{
    segment temp{u, direction, t}; return temp;
}

bool g(point p, int n, int m)
{
    return p.y >= 0 && p.y <= n - 1 && p.x >= 0 && p.x <= m - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<int> yp = {-1, 0, 1, 0},
                xp = {0, 1, 0, -1};
                
    string getDir = "SWNE";
    map<char, int> getPos;
    for (int i = 0; i <= 3; ++i) getPos[getDir[i]] = i;
    
    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n, m; cin >> n >> m;

        int dc = 0;
        vector<point> doors;
        vector<vector<char>> a(n, vector<char>(m, '.'));
        vector<vector<int>> dtr(n, vector<int>(m, 0));
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                cin >> a[y][x];

                if (a[y][x] != '.' && a[y][x] != '#')
                {
                    ++dc;
                    doors.push_back(_point(y, x));
                }
            }
        }

        for (int i = 0; i <= dc - 1; ++i)
        {
            cin >> dtr[doors[i].y][doors[i].x];
        }

        priority_queue<segment> pq; pq.push(_segment(_point(n - 1, 0), 'W', 0));
        vector<vector<int>> dp(n, vector<int>(m, inf));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (g(now.u, n, m) == false) continue;
            else if (a[now.u.y][now.u.x] == '#') continue;
            else if (a[now.u.y][now.u.x] != '.' && now.direction != a[now.u.y][now.u.x]) continue;
            else if (now.t >= dp[now.u.y][now.u.x]) continue;

            dp[now.u.y][now.u.x] = now.t;

            if (now.u.y == 0 && now.u.x == m - 1)
            {
                break;
            }

            if (now.u.y == 2 && now.u.x == 1)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            if (a[now.u.y][now.u.x] == '.')
            {
                for (int p = 0; p <= 3; ++p)
                {
                    point v{now.u.y + yp[p], now.u.x + xp[p]};

                    if (g(v, n, m) == false)
                    {
                        continue;
                    }
                    else if (a[v.y][v.x] == '#')
                    {
                        continue;
                    }
                    else if (a[v.y][v.x] == '.')
                    {
                        pq.push(_segment(v, getDir[p], now.t + 1));
                    }
                    else if (getDir[p] == a[v.y][v.x])
                    {
                        pq.push(_segment(v, getDir[p], now.t + 1));
                    }
                }
            }
            else
            {
                int pos = getPos[now.direction], nextPos;

                nextPos = pos - 1;
                if (nextPos == -1) nextPos = 3;
                pq.push
                (
                    _segment
                    (   _point(now.u.y + yp[nextPos], now.u.x + xp[nextPos]),
                        getDir[nextPos],
                        now.t + dtr[now.u.y][now.u.x] + 1
                    )
                );

                nextPos = pos + 1;
                if (nextPos == 4) nextPos = 0;
                pq.push
                (
                    _segment
                    (   _point(now.u.y + yp[nextPos], now.u.x + xp[nextPos]),
                        getDir[nextPos],
                        now.t + dtr[now.u.y][now.u.x] + 1
                    )
                );

                nextPos = pos;
                pq.push
                (
                    _segment
                    (   _point(now.u.y + yp[nextPos], now.u.x + xp[nextPos]),
                        getDir[nextPos],
                        now.t + dtr[now.u.y][now.u.x] * 2 + 1
                    )
                );
            }
        }

        if (dp[0][m - 1] < inf)
        {
            cout << dp[0][m - 1] << '\n';
        }
        else
        {
            cout << "Poor Kianoosh\n";
        }




    }

   	cout.flush();
   	return 0;
}

