#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("busDrive.in");
ofstream fout("busDrive.out");

int main()
{
    while (true)
    {
        int n = -1, d = -1, r = -1;
        fin >> n >> d >> r;

        if (n == 0)
        {
            break;
        }

        vector<int> morning(n), evening(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> morning[i];
        }

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> evening[i];
        }

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());

        int total = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            if (morning[i] + evening[i] > d)
            {
                total += morning[i] + evening[i] - d;
            }
        }

        fout << total * r << '\n';
    }

    return 0;
}