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

ifstream fin("radarInstallation.in");
ofstream fout("radarInstallation.out");

int d = 0;

struct point
{
    int x;
    int y;
    // bool operator<(const point &temp)
    // {
    //     if (abs(y - temp.y) < abs(x - temp.x))
    //     {
    //         return x < temp.x;
    //     }
    //     else
    //     {
    //         double Xpos = temp.x + sqrt(d * d - temp.y * temp.y);
    //         double result = sqrt((x - Xpos) * (x - Xpos) + y * y);
    //         return result > d;
    //     }
    // }

    bool operator<(const point &temp)
    {
        double Xpos1 = temp.x + sqrt(d * d - temp.y * temp.y);
        double Xpos2 = x + sqrt(d * d - y * y);
        return Xpos2 < Xpos1;
    }
};

int check(vector<point> & radars, double Xpos, int d, int start)
{
    int n = radars.size(), i = start;
    while (i <= n - 1)
    {
        double result = sqrt((radars[i].x - Xpos) * (radars[i].x - Xpos) + radars[i].y * radars[i].y);
        if (result <= d)
        {
            ++i;
        }
        else
        {
            return i;
        }
    }

    return n;
}

int main()
{
    int c = 0;
    while (true)
    {
        ++c;

        int n = 0;
        fin >> n >> d;

        if (n == 0)
        {
            break;
        }

        vector<point> radars(n);
        bool out = false;
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> radars[i].x >> radars[i].y;
            if (radars[i].y > d)
            {
                out = true;
            }
        }

        if (out == true)
        {
            fout << "Case " << c << ": -1\n";
            continue;
        }
        else if (n == 1)
        {
            fout << "Case " << c << ": 1\n";
            continue;
        }

        sort(radars.begin(), radars.end());

        // for (int i = 0; i <= n - 1; ++i)
        // {
        //     fout << radars[i].x << ' ' << radars[i].y << '\n';
        // }

        int i = 0, count = 0;
        while (i <= n - 1)
        {
            point nowPoint = radars[i];
            double Xpos = nowPoint.x + sqrt(d * d - nowPoint.y * nowPoint.y);

            i = check(radars, Xpos, d, i + 1);
            ++count;
        }

        fout << "Case " << c << ": " << count << '\n';
    }

    return 0;
}