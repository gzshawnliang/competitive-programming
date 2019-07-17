#include <bits/stdc++.h>

using namespace std;

ifstream fin("crossedLadders_UVA10566.in");
ofstream fout("crossedLadders_UVA10566.out");

const double eps = 1e-9;

bool check(double m, double x, double y, double c)
{
    double a = sqrt(x * x - m * m), b = sqrt(y * y - m * m);
    double p = x * b / (a + b), q = y * a / (a + b);
    double k = (p + q + m) / 2;
    double s = sqrt(k * (k - p) * (k - q) * (k - m));
    double h = 2 * s / m;

    return h < c;
}

int main()
{
    fout << fixed << setprecision(3);
    while (true)
    {
        double x = 0.0, y = 0.0, c = 0.0; fin >> x >> y >> c;
        if (x + y + c == 0.0) break;

        double l = 0.0, r = min(x, y);
        while (true)
        {
            double m = (l + r) / 2.0;

            if (check(m, x, y, c) == true)
            {
                r = m;
            }
            else
            {
                l = m;
            }

            if (abs(l - r) < eps)
            {
                break;
            }
        }

        fout << l << '\n';
    }

    return 0;
}
