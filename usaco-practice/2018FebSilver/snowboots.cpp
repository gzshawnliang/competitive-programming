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

int solve(int nowPos, int nowUse, vector<int> & f, vector<boot> & a, vector<int> & dp)
{
    int n = f.size(), b = a.size(), ans = 251;

    if (nowPos == n - 1)
    {
        return nowUse;
    }
    else if (nowUse == b || dp[nowPos] <= nowUse)
    {
        return 251;
    }
    else
    {
        dp[nowPos] = nowUse;

        int maxreach = nowPos;
        boot now = a[nowUse];
        for (int i = nowPos; i <= n - 1 && i - nowPos <= now.d; ++i)
        {
            if (nowUse == 0)
            {
                cout << "";
            }

            if (f[i] > now.s)
            {
                continue;
            }
            else
            {
                maxreach = i;
                
                ans = min(ans, solve(i, nowUse + 1, f, a, dp));
            }
        }

        if (maxreach > nowPos)
        {
            ans = min(ans, solve(maxreach, nowUse, f, a, dp));
        }

        return ans;
    }
}

int main()
{
    int n, b; fin >> n >> b;

    vector<int> f(n);
    vector<int> dp(n, 251);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> f[i];
    }

    vector<boot> a(b);
    for (int i = 0; i <= b - 1; ++i)
    {
        fin >> a[i].s >> a[i].d;
    }

    fout << solve(0, 0, f, a, dp) << '\n';

    return 0;
}
