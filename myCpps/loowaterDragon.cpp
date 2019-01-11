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

ifstream fin("loowaterDragon.in");
ofstream fout("loowaterDragon.out");

int main()
{
    while (true)
    {
        int n, m;
        fin >> n >> m;

        if (n == 0)
        {
            break;
        }

        if (n > m)
        {
            fout << "Loowater is doomed!\n";
            continue;
        }

        vector<int> heads(n), knights(m);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> heads[i];
        }

        for (int i = 0; i <= m - 1; ++i)
        {
            fin >> knights[i];
        }

        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        int total = 0;
        int j = 0;
        for (int i = 0; j <= n - 1; ++i)
        {
            if (i == m)
            {
                total = -1;
                fout << "Loowater is doomed!\n";
                break;
            }
            else
            {
                if (knights[i] >= heads[j])
                {
                    total += knights[i];
                    ++j;
                }
            }
        }

        if (total >= 0)
        {
            fout << total << '\n';
        }
    }
}