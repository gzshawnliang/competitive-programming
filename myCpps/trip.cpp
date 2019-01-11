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

void solve()
{
    ifstream fin("trip.in");
    ofstream fout("trip.out");

    while (true)
    {
        int people, ava, total = 0;
        fin >> people;

        if (people == 0)
        {
            break;
        }

        vector<int> a(people);
        for (int i = 0; i <= people - 1; ++i)
        {
            double temp;
            fin >> temp;
            a[i] = (int)round(temp * 100);
            total += a[i];
        }

        int ans = 0, overCount = 0;
        ava = total / people;
        int difference = total - ava * people;
        for (int i = 0; i <= people - 1; ++i)
        {
            if (a[i] > ava)
            {
                //ans += a[i] - ava;
                ++overCount;
            }
            else
            {
                ans += ava - a[i];
            }
        }

        for (int i = 0; i <= overCount - 1; ++i)
        {
            if (difference <= 0)
            {
                break;
            }
            --difference;
        }
        ans += difference;

        fout << '$' << fixed << setprecision(2) << ans / 100.0 << '\n';
    }
}

int main()
{
    solve();
    return 0;
}