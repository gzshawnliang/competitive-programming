#include <bits/stdc++.h>

using namespace std;

ifstream fin("leapsTallBuildings_UVA10372.in");
ofstream fout("leapsTallBuildings_UVA10372.out");

const double PI = 3.1415926, eps = 1e-6;

struct dot
{
    double x;
    double y;
};
dot _dot(double x, double y)
{
    dot temp{x, y};
    return temp;
}

int main()
{
    fout << fixed << setprecision(2);

    while (true)
    {
        int n = 0;
        fin >> n;
        if (n == 0)
            break;

        double xt = 0.0;
        vector<dot> a;
        for (int c = 1; c <= n; ++c)
        {
            double h, d;
            fin >> h >> d;

            a.push_back(_dot(xt, h));
            a.push_back(_dot(xt + d, h));

            xt += d;
        }
        a.erase(a.begin());

        int size = a.size();
        double ansK = 0.0;
        for (int i = 0; i <= size - 1; ++i)
        {
            double nowK = a[i].y / ((a[i].x - xt) * a[i].x);
            ansK = min(ansK, nowK);
        }

        double x1 = 1e-20;
        double y1 = ansK * x1 * (x1 - xt);
        double angle = atan(y1 / x1) / PI * 180.0;

        double midPos = xt / 2;
        double maxH = ansK * midPos * (midPos - xt);
        double f_v = sqrt(maxH * 2 * 9.8);
        double f = f_v / sin(angle * PI / 180.0);

        fout << angle << ' ' << f << '\n';
    }

    return 0;
}
