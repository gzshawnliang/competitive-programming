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

ifstream fin("maxProduct.in");
ofstream fout("maxProduct.out");

int main()
{
    int count = 0;
    while (true)
    {
        ++count;
        int n = 0;
        long long ans = 0;
        fin >> n;
        if (n == 0)
        {
            return 0;
        }
        vector<int> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }
        for (int start = 0; start <= n - 1; ++ start)
        {
            for (int end = start; end <= n - 1; ++ end)
            {
                long long total = 1;
                for (int i = start; i <= end; ++ i)
                {
                    total *= a[i];
                }
                if (total > ans)
                {
                    ans = total;
                }
            }
        }
        
        fout << "Case #" << count << ": The maximum product is " << ans << ".\n\n";
    }
}