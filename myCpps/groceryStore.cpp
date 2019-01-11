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

ofstream fout("groceryStore.out");

int main()
{
    fout << fixed << setprecision(2);
    
    //int a=(int)1e8;

    for (long long a = 1; a * a * a * a < 16000000000000 && a * 4 <= 2000; ++a)
    {
        for (long long b = a; b * b * b * a < 16000000000000 && b * 3 + a <= 2000; ++b)
        {
            for (long long c = b; c * c * b * a < 16000000000000 && c * 2 + b + a <= 2000; ++c)
            {
                if (a * b * c > 1000000)
                {
                    if ((1000000 * (a + b + c)) % (a * b * c - 1000000) == 0)
                    {
                        long long d = (1000000 * (a + b + c)) / (a * b * c - 1000000);
                        if (a + b + c + d <= 2000 && d >= c)
                        {
                            fout << a / 100.0 << " " << b / 100.0 << " " << c / 100.0 << " " << d / 100.0 << '\n';
                        }
                    }
                }
            }
        }
    }

    return 0;
}