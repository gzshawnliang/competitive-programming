#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("Marbles_UVA10090.in");
ofstream fout("Marbles_UVA10090.out");

long long gcd(long long a, long long b, long long & x, long long & y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;

        return a;
    }
    else
    {
        long long res = gcd(b, a % b, y, x);
        y -= (a / b) * x;

        return res;
    }
}

int main()
{
    while (true)
    {
        long long n = 0, c1, n1, c2, n2;
        fin >> n;
        if (n == 0) break;

        fin >> c1 >> n1 >> c2 >> n2;

        long long tempX, tempY, x, y;
        long long res = gcd(n1, n2, tempX, tempY);

        long long lower = ceil(-1.0 * n * tempX / n2);
        long long upper = floor(1.0 * n * tempY / n1);

        if (lower > upper || n % res > 0)
        {
            fout << "failed\n";
            continue;
        }

        if (c1 * n2 > c2 * n1)
        {
            x = tempX * n / res + n2 / res * lower;
            y = tempY * n / res - n1 / res * lower;
        }
        else
        {
            x = tempX * n / res + n2 / res * upper;
            y = tempY * n / res - n1 / res * upper;
        }

        fout << x << ' ' << y << '\n';
    }
    return 0;
}
