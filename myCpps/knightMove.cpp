#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("knightMove.in");
ofstream fout("knightMove.out");

bool g(int y, int x)
{
    return y >= 0 && y <= 7 && x >= 0 && x <= 7;
}

struct point
{
    int y;
    int x;
};

int solve(int nowY, int nowX, int targetY, int targetX)
{
    if (g(nowY, nowX) == false || g(targetY, targetX) == false)
    {
        return 0;
    }
    else if (nowY == targetY && nowX == targetX)
    {
        return 0;
    }

    vector<int> yPlus = {2, 2, 1, -1, -2, -2, -1, 1};
    vector<int> xPlus = {-1, 1, 2, 2, 1, -1, -2, -2};

    queue<point> q;
    point startPosition{nowY, nowX};
    q.push(startPosition);

    vector<vector<int>> d(8, vector<int>(8, 0));
    vector<vector<bool>> path(8, vector<bool>(8, false));
    d[nowY][nowX] = 0; path[nowY][nowX] = true;

    while (!(q.empty()))
    {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        for (int i = 0; i <= 7; ++i)
        {
            int Cy = y + yPlus[i], Cx = x + xPlus[i];

            if (g(Cy, Cx) == true && path[Cy][Cx] == false)
            {
                point temp{Cy, Cx};
                q.push(temp);
                d[Cy][Cx] = d[y][x] + 1;
                path[Cy][Cx] = true;

                if (Cy == targetY && Cx == targetX)
                {
                    return d[Cy][Cx];
                }
            }
        }
    }

    return 1;
}

int main()
{
    while (true)
    {
        string in1 = "Shawn", in2 = "Shawn";
        fin >> in1 >> in2;

        if (in1 == "Shawn")
        {
            break;
        }

        int y1 = 7 - (in1[1] - '1'), x1 = in1[0] - 'a', y2 = 7 - (in2[1] - '1'), x2 = in2[0] - 'a';
        
        int ans = solve(y1, x1, y2, x2);

        fout << "To get from " << in1 << " to " << in2 << " takes " << ans << " knight moves.\n";
    }

    return 0;
}