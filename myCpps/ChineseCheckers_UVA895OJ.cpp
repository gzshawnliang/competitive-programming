#include <bits/stdc++.h>

using namespace std;


struct segment
{
    int y;
    int x;
    int t;

    bool operator<(const segment & temp) const
    {
        if (y != temp.y)
        {
            return y > temp.y;
        }
        else
        {
            return x < temp.x;
        }
    }
};
segment _segment(int y, int x, int t)
{
    segment temp{y, x, t}; return temp;
}

bool g(int y, int x, int yn, int xn)
{
    return y >= 1 && y <= yn && x >= 1 && x <= xn;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<int> yP = {-1, -1, 0, 1, 1, 1, 0, -1},
                xP = {0, 1, 1, 1, 0, -1, -1, -1};

    int t = 0;
    while (true)
    {
        int yn = 0, xn = 0; cin >> yn >> xn;
        if (yn + xn == 0) break;

        ++t;
        if (t > 1) cout << '\n';

        int p = 2 * xn;

        vector<vector<int>> a(yn + 1, vector<int>(xn + 1, 0));
        for (int c = 1; c <= p * 2; ++c)
        {
            int y, x; cin >> y >> x;

            if (c <= p)
            {
                a[y][x] = 1;
            }
            else
            {
                a[y][x] = 2;
            }
        }

        int yS, xS; cin >> yS >> xS;


        vector<vector<bool>> visit(yn + 1, vector<bool>(xn + 1, false));
        vector<segment> ans;
        queue<segment> q; q.push(_segment(yS, xS, 0));
        while (q.empty() == false)
        {
            segment now = q.front(); q.pop();

            if (now.y != yS || now.x != xS)
            {
                ans.push_back(now);
            }

            visit[now.y][now.x] = true;

            for (int p = 0; p <= 7; ++p)
            {
                segment next;
                next.t = now.t + 1;
                next.y = now.y + (yP[p] * 2);
                next.x = now.x + (xP[p] * 2);

                if (yP[p] == -1)
                {
                    continue;
                }
                if (g(next.y, next.x, yn, xn) == false)
                {
                    continue;
                }
                else if (visit[next.y][next.x] == true)
                {
                    continue;
                }
                else if (a[next.y][next.x] != 0)
                {
                    continue;
                }
                else if (a[now.y + yP[p]][now.x + xP[p]] == 0)
                {
                    continue;
                }

                q.push(next);
            }
        }

        for (int p = 0; p <= 7; p += 2)
        {
            segment next;
            next.t = 1;
            next.y = yS + yP[p];
            next.x = xS + xP[p];

            if (yP[p] == -1)
            {
                continue;
            }
            else if (g(next.y, next.x, yn, xn) == false)
            {
                continue;
            }
            else if (visit[next.y][next.x] == true)
            {
                continue;
            }
            else if (a[next.y][next.x] != 0)
            {
                continue;
            }

            ans.push_back(next);
        }

        sort(ans.begin(), ans.end());

        int size = ans.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            cout << ans[i].y << ' ' << ans[i].x << ' ' << ans[i].t << '\n';
        }
    }
    

   	cout.flush();
   	return 0;
}

