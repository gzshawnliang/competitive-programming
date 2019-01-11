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

ofstream fout("!test.out");

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

struct nums
{
    int a;
    int b;
    int c;

    // bool operator<(const nums & newNum) const
    // {
    //     if (a != newNum.a)
    //     {
    //         return a < newNum.a;
    //     }
    //     else
    //     {
    //         return b < newNum.b;
    //     }
    // };

    bool operator<(const nums & newNum) const
    {
        int size1 = (to_string(b) + to_string(c)).size();
        int size2 = (to_string(newNum.b) + to_string(newNum.c)).size();
        
        if (size1 != size2)
        {
            return size1 < size2;
        }
        else
        {
            return a < newNum.a;
        }
    };
};

int main()
{
    set<nums> store;
    for (int i = 2; i <= 10000; ++i)
    {
        int a = 2 * i, b = i * i - 1, c = i * i + 1;
        int allGcd = gcd(gcd(a, b), gcd(a, c));
        a /= allGcd; b /= allGcd; c /= allGcd;

        nums temp{min(a, b), max(a, b), c};
        store.insert(temp);
    }

    for (auto it = store.begin(); it != store.end(); ++it)
    {
        fout << it->a << ' ' << it->b << ' ' << it->c << '\n';
    }

    return 0;
}