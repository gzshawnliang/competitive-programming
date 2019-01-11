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

ofstream fout("perfectCubes.out");

int main()
{
    for (int a = 6; a <= 200; ++a)
    {
        for (int b = 2; b <= a; ++b)
        {
            for (int c = b; a * a * a - c * c * c - b * b * b > c * c * c; ++c)
            {
                double cubeD = a * a * a - b * b * b - c * c * c;

                for (int i = 1; i <= 200; ++i)
                {
                    if (i * i * i == cubeD)
                    {
                        fout << "Cube = " << a << ", Triple = (" << b << ',' << c << ',' << i << ")\n";
                        break;
                    }
                }
            }
        }
    }

    return 0;
}