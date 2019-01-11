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
#include <queue>
#include <map>

using namespace std;

ifstream fin("wakingUpBrain_UVA10507.in");
ofstream fout("wakingUpBrain_UVA10507.out");

int _count;
vector<int> used;
int trans(char chr)
{
    if (used[chr - 'A']  == -1)
    {
        used[chr - 'A'] = _count;
        ++_count;
        return _count - 1;
    }
    else
    {
        return used[chr - 'A'];
    }
}

int solve(int n, int year, vector<bool> & wakeUp, vector<vector<int>> & g)
{
    bool _find = false, allWaken = true;
    vector<bool> temp = wakeUp;
    for (int i = 0; i <= n - 1; ++i)
    {
        if (wakeUp[i] == false)
        {
            allWaken = false;
            int total = 0, size = g[i].size();
            for (int j = 0; j <= size - 1; ++j)
            {
                if (wakeUp[g[i][j]] == true)
                {
                    ++total;
                }
            }

            if (total >= 3)
            {
                temp[i] = true;
                _find = true;
            }
        }
    }

    if (allWaken == true)
    {
        return year;
    }
    else if (_find == false)
    {
        return -1;
    }
    else
    {
        wakeUp = temp;
        return solve(n, year + 1, wakeUp, g);
    }
}

int main()
{
    while (true)
    {
        _count = 0;
        used.clear();
        for (int c = 1; c <= 26; ++c)
        {
            used.push_back(-1);
        }

        int n = -1; fin >> n;
        if (n == -1) break;
        int m; fin >> m;
        vector<bool> wakeUp(n, false);
        vector<vector<int>> g(n);
        string in; fin >> in;
        wakeUp[trans(in[0])] = true;
        wakeUp[trans(in[1])] = true;
        wakeUp[trans(in[2])] = true;
        for (int c = 1; c <= m; ++c)
        {
            fin >> in;
            g[trans(in[0])].push_back(trans(in[1]));
            g[trans(in[1])].push_back(trans(in[0]));
        }

        int res = solve(n, 0, wakeUp, g);
        if (res == -1)
        {
            fout << "THIS BRAIN NEVER WAKES UP\n";
        }
        else
        {
            fout << "WAKE UP IN, " << res << ", YEARS\n";
        }
    }

    return 0;
}