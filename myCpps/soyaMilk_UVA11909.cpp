#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("soyaMilk_UVA11909.in");
ofstream fout("soyaMilk_UVA11909.out");

const double PI = 3.1415926536;

int main()
{
    fout << fixed << setprecision(3);

    while (true)
    {
        int i1 = 0, i2 = 0, i3 = 0, i4 = 0; fin >> i1 >> i2 >> i3 >> i4;

        if (i1 + i2 + i3 + i4 == 0)
        {
            break;
        }

        double l = (double)i1, w = (double)i2, h = (double)i3, a = (double)i4;

        double size;

        double _tan = tan((90 - a) * PI / 180.0);

        if (a < atan(h / l) / PI * 180.0)
        {
            size = l * h - l * (l / _tan) / 2;
        }
        else
        {
            size = h * h * _tan / 2;
        }

        fout << size * w << " mL\n";
    }

    return 0;
}