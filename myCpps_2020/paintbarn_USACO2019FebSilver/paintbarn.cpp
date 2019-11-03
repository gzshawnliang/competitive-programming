#include <bits/stdc++.h>

using namespace std;

ifstream fin("paintbarn.in");
ofstream fout("paintbarn.out");

const int maxL = 1000;

int main()
{
    int n, k; fin >> n >> k;

    vector<vector<int>> a(maxL + 1, vector<int>(maxL + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        int x1, y1, x2, y2; fin >> x1 >> y1 >> x2 >> y2;
        ++x1; ++y1;

        for (int y = y1; y <= y2; ++y)
        {
            ++a[y][x1 - 1]; --a[y][x2];
        }
    }

    int ans = 0;
    for (int y = 0; y <= maxL; ++y)
    {
        int nowL = 0;
        for (int x = 0; x <= maxL; ++x)
        {
            if (nowL == k) ++ans;

            nowL += a[y][x];
        }
    }

    fout << ans << '\n';

    return 0;
}
