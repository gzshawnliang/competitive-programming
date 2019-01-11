#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

//weeeeeeee I am so good so I wrote this script !
using namespace std;

ifstream fin("gridGame.in");
ofstream fout("gridGame.out");

long long total = 0;

int solve(vector< vector<int> > & a, vector<int> & yR, vector<int> & xR)
{
    ++total;
    int size = a[0].size(), minCount = 1000000;
    bool sth = false;
    for (int y = 0; y <= size - 1; ++y)
    {
        if (yR[y] == 1)
        {
            continue;
        }
        for (int x = 0; x <= size - 1; ++x)
        {
            if (xR[x] == 1)
            {
                continue;
            }
            sth = true;
            yR[y] = 1;
            xR[x] = 1;
            minCount = min(minCount, a[y][x] + solve(a, yR, xR));
            yR[y] = 0;
            xR[x] = 0;
        }
    }

    if (sth == false)
    {
        return 0;
    }
    else
    {
        return minCount;
    }
}

int main()
{
    int count;
    fin >> count;

    for (int t = 1; t <= count; ++t)
    {
        total = 0;
        int size;
        fin >> size;
        vector< vector<int> > a(size, vector<int>(size));
        vector<int> yR(size, 0);
        vector<int> xR(size, 0);
        for (int y = 0; y <= size - 1; ++y)
        {
            for (int x = 0; x <= size - 1; ++x)
            {
                fin >> a[y][x];
            }
        }

        fout << solve(a, yR, xR) << "   loops : " << total <<'\n';
    }

    return 0;
}