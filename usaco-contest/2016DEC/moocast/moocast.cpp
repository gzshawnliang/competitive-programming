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

ifstream fin("moocast.in");
ofstream fout("moocast.out");

struct cow
{
    long long y;
    long long x;
    long long p;
};

long long sq(long long i)
{
    return i * i;
}

int solve(int i, vector<bool> & visit, vector<cow> & a)
{
    int n = a.size(), total = 1;

    visit[i] = true;

    for (int j = 0; j <= n - 1; ++j)
    {
        if (i == j) continue;
        else if (sq(a[i].x - a[j].x) + sq(a[i].y - a[j].y) <= sq(a[i].p))
        {
            if (visit[j] == false)
            {
                total += solve(j, visit, a);
            }
        }
    }

    return total;
}

int main()
{
    int n; fin >> n;

    vector<cow> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i].x >> a[i].y >> a[i].p;
    }

    vector<bool> visit(n, false);

    int ans = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = 0; j <= n - 1; ++j)
        {
            visit[j] = false;
        }

        ans = max(ans, solve(i, visit, a));
    }

    fout << ans << '\n';

    return 0;
}