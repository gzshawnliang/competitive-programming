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

ifstream fin("scareCrow.in");
ofstream fout("scareCrow.out");

int main()
{
    int T;
    fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        string field;
        int size;
        fin >> size >> field;

        int total = 0;
        for (int i = 0; i <= size - 1; ++i)
        {
            if (field[i] == '.')
            {
                ++total;
                i += 2;
            }
        }

        fout << "Case " << t << ": " << total << '\n';
    }
}