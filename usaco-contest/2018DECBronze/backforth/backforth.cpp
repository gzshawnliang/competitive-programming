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

ifstream fin("backforth.in");
ofstream fout("backforth.out");

void pick(int count, int total, vector<int> & a, vector<int> & b, set<int> & ans)
{
    int sizeA = a.size(), sizeB = b.size();

    if (count == 6)
    {
        ans.insert(total);
    }
    else if (count % 2 == 0)
    {
        vector<bool> vis(101, false);

        for (int i = 0; i <= sizeA - 1; ++i)
        {
            if (a[i] > 0 && vis[a[i]] == false)
            {
                int temp = a[i];
                vis[temp] = true;
                a[i] = 0;
                
                int tempP = 0, tempB = 0;
                for (int j = 0; j <= sizeB; ++j)
                {
                    if (b[j] == 0)
                    {
                        tempB = b[j];
                        tempP = j;

                        b[j] = temp;

                        break;
                    }
                }

                pick(count + 1, total - temp, a, b, ans);

                a[i] = temp;
                b[tempP] = tempB;
            }
        }
    }
    else
    {
        vector<bool> vis(101, false);

        for (int i = 0; i <= sizeB - 1; ++i)
        {
            if (b[i] > 0 && vis[b[i]] == false)
            {
                int temp = b[i];
                vis[temp] = true;
                b[i] = 0;
                
                int tempP = 0, tempA = 0;
                for (int j = 0; j <= sizeB; ++j)
                {
                    if (a[j] == 0)
                    {
                        tempA = a[j];
                        tempP = j;

                        a[j] = temp;

                        break;
                    }
                }

                pick(count + 1, total + temp, a, b, ans);

                b[i] = temp;
                a[tempP] = tempA;
            }
        }
    }
}

int main()
{
    set<int> ans;
    vector<int> a(11, 0), b(11, 0);

    for (int i = 0; i <= 9; ++i)
    {
        fin >> a[i];
    }
    for (int i = 0; i <= 9; ++i)
    {
        fin >> b[i];
    }

    pick(2, 1000, a, b, ans);

    fout << ans.size() << '\n';

    return 0;
}
