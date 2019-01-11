#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("boiledEggs.in");
ofstream fout("boiledEggs.out");

int main()
{
    int totalTest;
    fin >> totalTest;
    for (int c = 1; c <= totalTest; ++c)
    {
        int n, p, q, totalWeight = 0, total = 0;
        fin >> n >> p >> q;
        for (int i = 1; i <= n; ++i)
        {
            int nowEgg;
            fin >> nowEgg;
            if (totalWeight + nowEgg <= q && i <= p)
            {
                ++total;
                totalWeight += nowEgg;
            }
        }

        fout << "Case " << c << ": " << total << '\n';
    }

    return 0;
}