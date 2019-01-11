#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

ifstream fin("bishops.in");
ofstream fout("bishops.out");

bool g(int y, int x, int n)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
}

// Out-put for map.
// void mapout(map<point,bool> a)
// {
//     for (auto it = a.begin(); it != a.end(); ++it)
//     {
//         fout << (it->first).x << " , " << (it->first).y << " , " << it->second << '\n';
//     }
//     fout << '\n';
// }

long long solve(int n, int k, vector< vector<bool> > a)
{
    if (k == 0)
    {
        return 1;
    }

    long long total = 0;

    //fout << "k = " << k << '\n';
    //mapout(a);

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            if (a[y][x] == false)
            {
                vector< vector<bool> > b = a;
                int tempY, tempX;
                tempY = y;
                tempX = x;
                while (g(tempY, tempX, n) == true)
                {
                    b[tempY][tempX] = true;
                    ++tempY;
                    ++tempX;
                }
                tempY = y;
                tempX = x;
                while (g(tempY, tempX, n) == true)
                {
                    b[tempY][tempX] = true;
                    --tempY;
                    ++tempX;
                }
                tempY = y;
                tempX = x;
                while (g(tempY, tempX, n) == true)
                {
                    b[tempY][tempX] = true;
                    ++tempY;
                    --tempX;
                }
                tempY = y;
                tempX = x;
                while (g(tempY, tempX, n) == true)
                {
                    b[tempY][tempX] = true;
                    --tempY;
                    --tempX;
                }
                
                total += solve(n, k - 1, b);
            }
        }
    }

    return total;
}

int main()
{
    while (true)
    {
        int n, k;
        fin >> n >> k;
        if (n + k == 0)
        {
            break;
        }
        vector< vector<bool> > a(n,vector<bool>(n, false));

        long long order = solve(n, k, a);
        for (int i = 2; i <= n; ++i)
        {
            order /= i;
        }

        fout << order << '\n';
    }

    return 0;
}