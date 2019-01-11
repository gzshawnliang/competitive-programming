#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

ifstream fin("P3956.in");
ofstream fout("P3956.out");

int INF = 2147483647;

//int fx[4] = {-1, 0, 1, 0}, fy[4] = {0, -1, 0, 1};
vector<int> fx = {-1, 0, 1, 0}, fy = {0, -1, 0, 1};

int m, n, ans = INF;

void dfs(int y, int x, int sum, bool magic, vector<vector<int>> & a, vector<vector<int>> & dp)
{
    if (y < 1 || x < 1 || y > m || x > m) return;
    else if (!a[y][x]) return;
    else if (sum >= dp[y][x]) return;

    dp[y][x] = sum;
    if (y == m && x == m)
    {
        ans = min(ans, sum);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int nextY = y + fx[i];
        int nextX = x + fy[i];
        if (a[nextY][nextX])
        {
            if (a[nextY][nextX] == a[y][x])
            {
                dfs(nextY, nextX, sum, false, a, dp);
            }
            else
            {
                dfs(nextY, nextX, sum + 1, false, a, dp); 
            }
        }
        else if (!a[nextY][nextX] && !magic)
        {
            a[nextY][nextX] = a[y][x];
            dfs(nextY, nextX, sum + 2, true, a, dp);
            a[nextY][nextX] = 0;
        }
    }
}
int main()
{
    vector<vector<int>> a(110, vector<int>(110, 0)), dp(110, vector<int>(110, INF));

    fin >> m >> n;

    for (int i = 1; i <= n; ++i)
    {
        int y, x, c;
        fin >> y >> x >> c;
        a[y][x] = c + 1;
    }

    dfs(1, 1, 0, false, a, dp);

    if (ans == INF)
    {
        ans = -1;
    }

    fout << ans << '\n';

    return 0;
}