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

ifstream fin("dancineTheCheekyCheeky_UVA11452.in");
ofstream fout("dancineTheCheekyCheeky_UVA11452.out");

int main()
{
    int T; fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        string a, loop; fin >> a;
        int size = a.size(), miss, start;

        if (size % 3 == 0)
        {
            start = size / 3;
        }
        else
        {
            start = size / 3 + 1;
        }
        
        for (int s = start; s <= size / 2; ++s)
        {
            string temp1 = a.substr(0, s), temp2 = a.substr(s, s);
            if (temp1 == temp2)
            {
                miss = size - s * 2;
                loop = temp1;
                break;
            }
        }

        int _count = 8, sizeL = loop.size();
        for (int i = miss; _count > 0; ++i)
        {
            i %= sizeL;

            fout << loop[i];
            --_count;
        }

        fout << "...\n";
    }

    return 0;
}