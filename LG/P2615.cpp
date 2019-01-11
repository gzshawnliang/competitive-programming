#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

ifstream fin("P2615.in");
ofstream fout("P2615.out");

struct point
{
    int y;
    int x;
};

bool g(int y, int x, int n)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
}

void put(int y, int x, int number, vector<vector<int>> & a, int & lastY, int & lastX)
{
    a[y][x] = number;
    lastY = y;
    lastX = x;
}

int main()
{
    int n; fin >> n;

    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<point> pos(n * n + 1);

    int lastY, lastX;
    
    put(0, (n - 1) / 2, 1, a, lastY, lastX);

    for (int k = 2; k <= n * n; ++k)
    {
        if (lastY == 0 && lastX != n - 1)
        {
            put(n - 1, lastX + 1, k, a, lastY, lastX);
        }
        else if (lastX == n - 1 && lastY != 0)
        {
            put(lastY - 1, 0, k, a, lastY, lastX);
        }
        else if (lastY == 0 && lastX == n - 1)
        {
            put(lastY + 1, lastX, k, a, lastY, lastX);
        }
        else if (a[lastY - 1][lastX + 1] == 0)
        {
            put(lastY - 1, lastX + 1, k, a, lastY, lastX);
        }
        else
        {
            put(lastY + 1, lastX, k, a, lastY, lastX);
        }
    }

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            if (x > 0) fout << ' ';
            fout << a[y][x];
        }

        fout << '\n';
    }

    return 0;
}