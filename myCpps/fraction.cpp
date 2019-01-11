#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("fraction.in");
ofstream fout("fraction.out");

int main()
{
    struct nums
    {
        long long x;
        long long y;
    };
    while(true)
    {
        long long k;
        fin >> k;
        if (fin.eof())
        {
            break;
        }
        vector<nums> a;
        for (long long y = k + 1; y <= 2 * k; ++y)
        {
            if ((k * y) % (y - k) == 0)
            {
                long long x = (k * y) / (y - k);
                nums temp{x, y};
                a.push_back(temp);
            }
        }
        int size = a.size();
        fout << size << '\n';
        for (int i = 0; i <= size - 1; ++i)
        {
            fout << "1/" << k << " = 1/" << a[i].x << " + 1/" << a[i].y << '\n';
        }
    }
}