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

ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

struct boot
{
    int s;
    int d;
};

int solve(int nowPos, int nowUse, vector<int> & f, vector<boot> & a, vector<vector<bool>> & visit)
{
    int n = f.size(), b = a.size(), ans = 251;

    if (nowPos == n - 1)
    {
        return nowUse;
    }
    else if (nowUse == b || visit[nowPos][nowUse] == true)
    {
        return 251;
    }
    else
    {
        visit[nowPos][nowUse] = true;

        boot now = a[nowUse];
        for (int i = nowPos; i <= n - 1 && i - nowPos <= now.d; ++i)
        {
            if (f[i] > now.s)
            {
                continue;
            }
            else
            {
                ans = min(ans, solve(i, nowUse + 1, f, a, visit));

                if (i > nowPos)
                {
                    ans = min(ans, solve(i, nowUse, f, a, visit));
                }
            }
        }

        return ans;
    }
}

int main()
{
    int n, b; fin >> n >> b;

    vector<int> f(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> f[i];
    }

    vector<boot> a(b);
    for (int i = 0; i <= b - 1; ++i)
    {
        fin >> a[i].s >> a[i].d;
    }

    vector<vector<bool>> visit(n,vector<bool>(b, false));
    fout << solve(0, 0, f, a, visit) << '\n';

    return 0;
}
