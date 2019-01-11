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


const double PI = 3.1415926536;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(3);

    while (true)
    {
        int i1 = 0, i2 = 0, i3 = 0, i4 = 0; cin >> i1 >> i2 >> i3 >> i4;

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

        cout << size * w << " mL\n";
    }

   	cout.flush();
   	return 0;
}
