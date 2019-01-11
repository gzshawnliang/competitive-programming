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

ifstream fin("networkConnections_UVA793.in");
ofstream fout("networkConnections_UVA793.out");

int _find(int v, vector<int> & p)
{
    if (p[v] == v)
    {
        return v;
    }
    else
    {
        int res =  _find(p[v], p);
        p[v] = res;

        return res;
    }
}

int main()
{
    int testCase; fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        if (c > 1) fout << '\n';

        int n, correct = 0, incorrect = 0;
        fin >> n;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            p[i] = i;
        }

        string in; getline(fin, in);
        while (true)
        {
            getline(fin, in); if (in == "") break;
            int size = in.size();
            char start = in[0];
            int i = 2, u, v;
            string temp;
            while (i <= size - 1)
            {
                if (in[i] == ' ')
                {
                    u = stoi(temp);
                    temp = "";
                }
                else
                {
                    temp += in[i];
                }
                ++i;
            }
            v = stoi(temp);
            
            int res0 = _find(u, p);
            int res1 = _find(v, p);

            if (start == 'q')
            {
                if (res0 == res1)
                {
                    ++correct;
                }
                else
                {
                    ++incorrect;
                }
            }
            else if (res0 != res1)
            {
                p[res1] = res0;
            }
        }

        fout << correct << ',' << incorrect << '\n';
    }

    return 0;
}