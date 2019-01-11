#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


int exitX;

bool g(int y, int x, int n, int m)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= m - 1;
}

void solve(int nowY, int nowX, vector<vector<int>> a, int nowMax, int nowCount, int n, int m, vector<vector<bool>> path)
{
    if (g(nowY, nowX, n, m) == true)
    {
        if (a[nowY][nowX] == nowCount && path[nowY][nowX] == false)
        {
            path[nowY][nowX] = true;

            if (nowY == n - 1)
            {
                exitX = min(exitX, nowX);
                return;
            }
            else if (nowCount < nowMax)
            {
                solve(nowY + 1, nowX, a, nowMax, nowCount + 1, n, m, path);
                solve(nowY - 1, nowX, a, nowMax, nowCount + 1, n, m, path);
                solve(nowY, nowX + 1, a, nowMax, nowCount + 1, n, m, path);
                solve(nowY, nowX - 1, a, nowMax, nowCount + 1, n, m, path);
            }
            else
            {
                solve(nowY + 1, nowX, a, nowMax + 1, 1, n, m, path);
                solve(nowY - 1, nowX, a, nowMax + 1, 1, n, m, path);
                solve(nowY, nowX + 1, a, nowMax + 1, 1, n, m, path);
                solve(nowY, nowX - 1, a, nowMax + 1, 1, n, m, path);
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase;
    cin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        if (c != 1)
        {
            cout << '\n';
        }

        exitX = 1000;

        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<bool>> path(n, vector<bool>(m, false));

        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                cin >> a[y][x];
            }
        }

        for (int x = 0; x <= m - 1; ++x)
        {
            solve(0, x, a, 1, 1, n, m, path);

            if (exitX != 1000)
            {
                cout << "1 " << x + 1 << '\n' << n << ' ' << exitX + 1 << '\n';
                break;
            }
        }

    }

   	cout.flush();
   	return 0;
}
