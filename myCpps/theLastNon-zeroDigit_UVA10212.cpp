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
#include <stack>

using namespace std;

ifstream fin("theLastNon-zeroDigit_UVA10212.in");
ofstream fout("theLastNon-zeroDigit_UVA10212.out");

int main()
{
    while (true)
    {
        long long n = -1, m = -1;
        fin >> n >> m;
        if (n == -1) break;

        long long ans = 1, _count = 0;
        for (long long c = 1; c <= m; ++c)
        {
            long long temp = n;
            while (temp % 2LL == 0)
            {
                temp /= 2LL;
                --_count;
            }
            while (temp % 5LL == 0)
            {
                temp /= 5LL;
                ++_count;
            }

            ans = (ans * temp) % 10LL;
            
            --n;
        }

        if (_count > 0)
        {
            for (int i = 1; i <= _count; ++i)
            {
                ans = (ans * 5LL) % 10LL;
            }
        }
        else
        {
            for (int i = 1; i <= -1 * _count; ++i)
            {
                ans = (ans * 2LL) % 10LL;
            }
        }

        fout << ans << '\n';
    }

    return 0;
}