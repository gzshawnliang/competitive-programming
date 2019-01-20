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

ifstream fin("multimoo.in");
ofstream fout("multimoo.out");

bool g(int y, int x, int n)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
}

int solve1
(
    int y,
    int x,
    int t,
    vector<vector<int>> & a,
    map<int, set<int>> & m,
    vector<vector<bool>> & visit
)
{
    int n = a.size();

    if (g(y, x, n) == false)
    {
        return 0;
    }
    else if (visit[y][x] == true)
    {
        return 0;
    }
    else if (a[y][x] != t)
    {
        m[t].insert(a[y][x]);

        return 0;
    }
    else
    {
        visit[y][x] = true;

        int ans = 1;
        ans += solve1(y + 1, x + 0, t, a, m, visit);
        ans += solve1(y - 1, x + 0, t, a, m, visit);
        ans += solve1(y + 0, x + 1, t, a, m, visit);
        ans += solve1(y + 0, x - 1, t, a, m, visit);

        return ans;
    }
}

int solve2
(
    int y,
    int x,
    int t1,
    int t2,
    vector<vector<bool>> & visit,
    vector<vector<int>> & a,
    vector<vector<bool>> & paint
)
{
    int n = a.size();

    if (g(y, x, n) == false)
    {
        return 0;
    }
    else if (visit[y][x] == true || (a[y][x] != t1 && a[y][x] != t2))
    {
        return 0;
    }
    else
    {
        visit[y][x] = true;

        if (a[y][x] == t1)
        {
            paint[y][x] = true;
        }

        int ans = 1;
        ans += solve2(y + 1, x + 0, t1, t2, visit, a, paint);
        ans += solve2(y - 1, x + 0, t1, t2, visit, a, paint);
        ans += solve2(y + 0, x + 1, t1, t2, visit, a, paint);
        ans += solve2(y + 0, x - 1, t1, t2, visit, a, paint);

        return ans;
    }
}

int main()
{
    int n; fin >> n;

    map<int, set<int>> m;
    vector<vector<int>> a(n, vector<int>(n, 0));

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            fin >> a[y][x];
        }
    }

    int max1 = 0, max2 = 0;
     
    vector<vector<int>> tempA = a;
    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            if (tempA[y][x] > 0)
            {
                vector<vector<bool>> tempVisit(n, vector<bool>(n, false));
                max1 = max(max1, solve1(y, x, a[y][x], tempA, m, tempVisit));
            }
        }
    }
    
    vector<vector<bool>> paint(n, vector<bool>(n, false));
    
    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            if (paint[y][x] == false)
            {
                vector<vector<bool>> visit(n, vector<bool>(n, false));
                
                for (auto it = m[a[y][x]].begin(); it != m[a[y][x]].end(); ++it)
                {
                    max2 = max(max2, solve2(y, x, a[y][x], *it, visit, a, paint));
                }
            }
        }
    }

    fout << max1 << '\n' << max2 << '\n';

    return 0;
}
