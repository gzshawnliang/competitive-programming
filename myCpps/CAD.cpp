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

ifstream fin("CAD.in");
ofstream fout("CAD.out");

int main()
{
    while (true)
    {
        fout << fixed << setprecision(5);
        int p = -1, q, r, s;
        fin >> p >> q >> r >> s;
        if (p == -1)
        {
            return 0;
        }
        if (q >= p / 2)
        {
            q = p - q; 
        }
        if (s >= r / 2)
        {
            s = r - s; 
        }
        
        long double temp1 = 1.0;
        int i0 = p, i1 = r;
        while (i0 >= p - q + 1 || i1 >= r - s + 1)
        {
            if (i0 >= p - q + 1)
            {
                temp1 *= i0;
                --i0;
            }
            if (i1 >= r - s + 1)
            {
                temp1 /= i1;
                --i1;
            }
        }

        bool divide;
        long double temp2 = 1.0;
        if (q > s)
        {
            divide = true;
            for (long double i = q; i >= s + 1; --i)
            {
                temp2 *= i;
            }
        }
        else
        {
            divide = false;
            for (long double i = s; i >= q + 1; --i)
            {
                temp2 *= i;
            }
        }

        long double ans;

        if (divide == true)
        {
            ans = temp1 / temp2;
        }
        else
        {
            ans = temp1 * temp2;
        }

        if(ans <= 100000000)
        {
            fout << ans << '\n';
        }
        else
        {
            fout << "0.00000\n";
        }
    }
}