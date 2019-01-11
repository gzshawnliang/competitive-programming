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

ifstream fin("antOnChessboard.in");
ofstream fout("antOnChessboard.out");

int main()
{
    while (true)
    {
        int m;
        fin >> m;

        if (m == 0)
        {
            break;
        }
        else if (m == 1)
        {
            fout << "1 1\n";
            continue;
        }
        else if (m == 2)
        {
            fout << "1 2\n";
            continue;
        }

        int lbound = sqrt(m - 1);
        while (lbound * lbound - lbound + 1 < m)
        {
            ++lbound;
        }
        --lbound;

        int lNum = lbound * lbound - lbound + 1;

        if (lbound * lbound + lbound + 1 == m)
        {
            fout << lbound + 1 << ' ' << lbound + 1 << '\n';
            continue;
        }

        if (lbound % 2 == 0)
        {
            if (m - lNum <= lbound - 1)
            {
                fout << lbound << ' ' << lbound + lNum - m << '\n';
            }
            else 
            {
                fout << lbound + 1 << ' ' << m - lNum - lbound + 1 << '\n';
            }
        }
        else
        {
            if (m - lNum <= lbound - 1)
            {
                fout << lbound + lNum - m << ' ' << lbound  << '\n';
            }
            else 
            {
                fout <<  m - lNum - lbound + 1 << ' ' << lbound + 1 << '\n';
            }
        }
    }

    return 0;
}