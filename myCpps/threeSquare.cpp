#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

ifstream fin("threeSquare.in");
ofstream fout("threeSquare.out");

int main()
{
    int total;
    fin >> total;
    for (int t = 1; t <= total; ++t)
    {
        int k;
        fin >> k;
        int maxLoop = sqrt(k);
        bool ok = false;
        for (int a = 0; a <= maxLoop && ok == false; ++a)
        {
            for (int b = a; b <= maxLoop && ok == false; ++b)
            {
                if (0)
                {
                    for (int c = b; c <= maxLoop && ok == false; ++c)
                    {
                        if (a * a + b * b + c * c == k)
                        {
                            fout << a << ' ' << b << ' ' << c << '\n';
                            ok = true;
                        }
                    }
                }
                else
                {
                    int c = k - a * a - b * b;
                    int temp = sqrt(c);
                    if (temp * temp == c)
                    {
                        fout << a << ' ' << b << ' ' << temp << '\n';
                        ok = true;
                    }
                }
            }
        }
        if (ok == false)
        {
            fout << "-1\n";
        }
    }

    return 0;
}