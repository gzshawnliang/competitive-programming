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

ifstream fin("fillTheSquare.in");
ofstream fout("fillTheSquare.out");

bool g(int n, int y, int x)
{
    return y >= 0 && x >= 0 && y <= n - 1 && x <= n - 1;
}

int main()
{
    int totalTest;
    fin >> totalTest;

    for (int c = 1; c <= totalTest; ++c)
    {
        int n;
        fin >> n;

        vector<vector<char>> a(n, vector<char>(n, '.'));

        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                fin >> a[y][x];
            }
        }

        fout << "Case " << c << ":\n";

        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                if (a[y][x] == '.')
                {
                    a[y][x] = 'A';

                    while (true)
                    {
                        bool ok = true;

                        if (g(n, y - 1, x) == true)
                        {
                            if (a[y][x] == a[y - 1][x])
                            {
                                ok = false;
                            }
                        }

                        if (g(n, y, x - 1) == true)
                        {
                            if (a[y][x] == a[y][x - 1])
                            {
                                ok = false;
                            }
                        }

                        if (g(n, y + 1, x) == true)
                        {
                            if (a[y][x] == a[y + 1][x])
                            {
                                ok = false;
                            }
                        }

                        if (g(n, y, x + 1) == true)
                        {
                            if (a[y][x] == a[y][x + 1])
                            {
                                ok = false;
                            }
                        }

                        if (ok == false)
                        {
                            ++a[y][x];
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                fout << a[y][x];
            }
            fout << '\n';
        }
    }

    return 0;
}
