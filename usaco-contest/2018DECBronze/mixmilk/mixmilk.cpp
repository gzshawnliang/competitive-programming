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
#include <set>
#include <map>

using namespace std;

ifstream fin("mixmilk.in");
ofstream fout("mixmilk.out");

void pour(int &c1, int &m1, int &c2, int &m2)
{
    if (m1 + m2 <= c2)
    {
        m2 = m1 + m2;
        m1 = 0;
    }
    else
    {
        m1 -= (c2 - m2);
        m2 = c2;
    }
}

int main()
{
    int c1, m1, c2, m2, c3, m3;
    fin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    for (int c = 1; c <= 33; ++c)
    {
        pour(c1, m1, c2, m2);
        pour(c2, m2, c3, m3);
        pour(c3, m3, c1, m1);
    }
    pour(c1, m1, c2, m2);

    fout << m1 << '\n' << m2 << '\n' << m3 << '\n';

    return 0;
}
