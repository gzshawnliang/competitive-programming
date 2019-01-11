#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

ifstream fin("chessBoard.in");
ofstream fout("chessBoard.out");

int main()
{
    const double root2 = sqrt(2);
    fout << fixed << setprecision(3);

    int total;
    fin >> total;

    for (int c = 1; c <= total; ++c)
    {
        if (c > 1)
        {
            fout << '\n';
        }
        int n;
        fin >> n;
        if (n == 1)
        {
            fout << "0.000\n";
            continue;
        }

        fout << 4 * (n - 1) + root2 * (n - 2) * (n - 2) << '\n';
    }
}