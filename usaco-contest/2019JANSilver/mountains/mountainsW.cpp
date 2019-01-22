#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("mountains.in");
ofstream fout("mountains.out");

const double eps = 1e-3;

struct point
{
    double x;
    double y;
};

struct triagle
{
    point tp1;
    point tp2;
    point tp3;

    bool operator<(const triagle & temp) const
    {
        if (tp2.x != temp.tp2.x)
        {
            return tp2.x < temp.tp2.x;
        }
        else
        {
            return tp1.y < temp.tp1.y;
        }
    }
};

double d(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double s(point tp1, point tp2, point tp3)
{
    double a = d(tp1, tp2),
           b = d(tp1, tp3),
           c = d(tp2, tp3);

    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool inSide(point p, point tp1, point tp2, point tp3)
{
    double s1 = s(p, tp1, tp2),
            s2 = s(p, tp1, tp3),
            s3 = s(p, tp2, tp3),
            st = s(tp1, tp2, tp3);

    return abs((s1 + s2 + s3) - st) < eps;
}

int main2()
{
    point A{-100, 0};
        
    point B{A.x - A.y, 0.0};
    point C{A.x + A.y, 0.0};

    point P{6, 6};

    fout << inSide(P, A, B, C) << '\n';
}

int main()
{
    int n; fin >> n;
    
    vector<triagle> t(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        point A; fin >> A.x >> A.y;
        
        point B{A.x - A.y, 0.0};
        point C{A.x + A.y, 0.0};

        t[i].tp1 = A; t[i].tp2 = B; t[i].tp3 = C;
    }

    sort(t.begin(), t.end());

    int ans = n;
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = 0; j <= n - 1; ++j)
        {
            if (j == i)
            {
                continue;
            }
            else if (inSide(t[i].tp1, t[j].tp1, t[j].tp2, t[j].tp3) == true)
            {
                --ans;
                break;
            }
            else if (t[i].tp3.x <= t[j].tp2.x)
            {
                break;
            }
        }
    }

    fout << ans << '\n';

    return 0;
}
