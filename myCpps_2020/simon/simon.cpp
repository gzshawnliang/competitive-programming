#include <bits/stdc++.h>

using namespace std;

ifstream fin("simon.in");
ofstream fout("simon.out");

const long long inf = LLONG_MAX / 2;

double dis(long long x1, long long y1, long long x2, long long y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    long long x1 = 0, y1 = 0;
    long long x2 = 300, y2 = 0;
    long long x3 = 100, y3 = 400;
    long long x4 = 500, y4 = 100;
    long long x5 = 600, y5 = 300;

    long long minX = inf, maxX = 0, minY = inf,snake maxY = 0;
    minX = min(minX, x1); maxX = max(maxX, x1);
    minX = min(minX, x2); maxX = max(maxX, x2);
    minX = min(minX, x3); maxX = max(maxX, x3);
    //minX = min(minX, x4); maxX = max(maxX, x4);
    minX = min(minX, x5); maxX = max(maxX, x5);

    minY = min(minY, y1); maxY = max(maxY, y1);
    minY = min(minY, y2); maxY = max(maxY, y2);
    minY = min(minY, y3); maxY = max(maxY, y3);
    minY = min(minY, y4); maxY = max(maxY, y4);
    minY = min(minY, y5); maxY = max(maxY, y5);

    long long ansX, ansY;
    double ansD = inf;
    for (long long x = minX; x <= maxX; ++x)
    {
        for (long long y = minY; y <= maxY; ++y)
        {
            double res = 0.0;
            res += dis(x, y, x1, y1);
            res += dis(x, y, x2, y2);
            res += dis(x, y, x3, y3);
            res += dis(x, y, x4, y4);
            res += dis(x, y, x5, y5);

            if (res < ansD)
            {
                ansD = res;
                ansX = x; ansY = y;
            }
        }
    }

    fout << ansD << ": (" << ansX << ", " << ansY << ")\n";

    return 0;
}
