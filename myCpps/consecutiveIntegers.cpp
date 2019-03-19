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

ifstream fin("consecutiveIntegers.in");
ofstream fout("consecutiveIntegers.out");

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == -1)
        {
            return 0;
        }

        for (int l = sqrt(2 * n); l >= 1; --l)
        {
            int a = (2 * n + l - l * l) / (2 * l);
            if ((2 * a + l - 1) * l == 2 * n)
            {
                cout << n << " = " << a << " + ... + " << a + l - 1 << '\n';
                break;
            }
        }
    }
    return 0;
}