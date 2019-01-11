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

using namespace std;

ifstream fin("BWpaint.in");
ofstream fout("BWpaint.out");

int main()
{
    while (true)
    {
        int m = -1, n;
        bool c;

        fin >> m >> n >> c;
        if (m == 0)
        {
            break;
        }

        int s = (m - 7) * (n - 7);
        if (s % 2 == 0)
        {
            fout << s / 2 << '\n';
        }
        else
        {
            if (c == 1)
            {
                fout << (s + 1) / 2 << '\n';
            }
            else
            {
                fout << (s - 1) / 2 << '\n';
            }
        }
    }
}