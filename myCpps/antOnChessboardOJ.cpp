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


int main()
{
    while (true)
    {
        int m;
        cin >> m;

        if (m == 0)
        {
            break;
        }
        else if (m == 1)
        {
            cout << "1 1\n";
            continue;
        }
        else if (m == 2)
        {
            cout << "1 2\n";
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
            cout << lbound + 1 << ' ' << lbound + 1 << '\n';
            continue;
        }

        if (lbound % 2 == 0)
        {
            if (m - lNum <= lbound - 1)
            {
                cout << lbound << ' ' << lbound + lNum - m << '\n';
            }
            else 
            {
                cout << lbound + 1 << ' ' << m - lNum - lbound + 1 << '\n';
            }
        }
        else
        {
            if (m - lNum <= lbound - 1)
            {
                cout << lbound + lNum - m << ' ' << lbound  << '\n';
            }
            else 
            {
                cout <<  m - lNum - lbound + 1 << ' ' << lbound + 1 << '\n';
            }
        }
    }

    return 0;
}
