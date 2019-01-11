#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

int main()
{
    double fx1, fy1, fx2, fy2,
           sx1, sy1, sx2, sy2,
           tx1, ty1, tx2, ty2;
    
    fin >> fx1 >> fy1 >> fx2 >> fy2
        >> sx1 >> sy1 >> sx2 >> sy2
        >> tx1 >> ty1 >> tx2 >> ty2;

    int ans = abs(fx1 - fx2) * abs(fy1 - fy2) + abs(sx1 - sx2) * abs(sy1 - sy2);

    for (double x = tx1 + 0.5; x <= tx2; x += 1.0)
    {
        for (double y = ty1 + 0.5; y <= ty2; y += 1.0)
        {
            if ((fx1 <= x && x <= fx2 && fy1 <= y && y <= fy2) || (sx1 <= x && x <= sx2 && sy1 <= y && y <= sy2) == true)
            {
                --ans;
            }
        }
    }

    fout << ans << '\n';

    return 0;
}
