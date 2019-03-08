#include <bits/stdc++.h>

using namespace std;

ifstream fin("paintbarn.in");
ofstream fout("paintbarn.out");

int main()
{
    int n, k; fin >> n >> k;

    int maxY = 0, maxX = 0;
    vector<vector<int>> a(200 + 1, vector<int>(200 + 1, 0));
    for (int c = 1; c <= n; ++c)
    {
        int x1, y1, x2, y2; fin >> x1 >> y1 >> x2 >> y2;

        maxY = max(maxY, y2); maxX = max(maxX, x2);

        for (int y = y1; y <= y2; ++y)
        {
            for (int x = x1; x <= x2; ++x)
            {
                ++a[x][y];
            }
        }
    }

    for (int y = 0; y <= maxY + 1; ++y)
    {
        for (int x = 0; x <= maxX + 1; ++x)
        {
            fout << a[y][x];
        }
        fout << '\n';
    }

    return 0;
}
