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

using namespace std;

ifstream fin("placeTheGuards_UVA11080.in");
ofstream fout("placeTheGuards_UVA11080.out");

int main()
{
    int testCase; fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int v, e, totalApart = 0;
        fin >> v >> e;
        vector<vector<bool>> a(v, vector<bool>(v, false));
        vector<int> color(v, -1);
        for (int k = 1; k <= e; ++k)
        {
            int f, t; fin >> f >> t;
            a[f][t] = true;
            a[t][f] = true;
        }

        if (e == 0)
        {
            fout << v << '\n';
            continue;
        }

        int total0 = 0, totalAparts = 0;
        bool isBicolorable = true;
        for (int k = 0; k <= v - 1; ++k)
        {
            if (color[k] == -1)
            {
                int tempTotal0 = 0, maxDeepness = 1;

                queue<int> q;
                q.push(k);
                color[k] = 0;
                ++tempTotal0;
                while (isBicolorable == true && !(q.empty()))
                {
                    int temp = q.size();
                    int s = q.front();
                    q.pop();
                    for (int i = 0; i <= v - 1; ++i)
                    {
                        if (a[s][i] == true)
                        {
                            if (color[i] == -1)
                            {
                                q.push(i);
                                ++maxDeepness;
                                if (color[s] == 0)
                                {
                                    color[i] = 1;
                                }
                                else
                                {
                                    color[i] = 0;
                                    ++tempTotal0;
                                }
                            }
                            else if (color[s] == color[i])
                            {
                                isBicolorable = false;
                                break;
                            }
                        }
                    }
                }

                if (maxDeepness == 1)
                {
                    ++totalAparts;
                }
                else
                {
                    total0 += min(maxDeepness - tempTotal0, tempTotal0);
                }
            }
        }
        

        if (isBicolorable == true)
        {
            fout << totalAparts + min(v - total0, total0) << '\n';
        }
        else
        {
            fout << "-1\n";
        }
    }

    return 0;
}
