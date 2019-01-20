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
    int num,
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
    else if (a[y][x] != t)
    {
        m[num].insert(a[y][x]);

        return 0;
    }
    else if (visit[y][x] == true)
    {
        return 0;
    }
    else
    {
        visit[y][x] = true;

        int ans = 1;
        ans += solve1(num, y + 1, x + 0, t, a, m, visit);
        ans += solve1(num, y - 1, x + 0, t, a, m, visit);
        ans += solve1(num, y + 0, x + 1, t, a, m, visit);
        ans += solve1(num, y + 0, x - 1, t, a, m, visit);

        return ans;
    }
}

int main()
{
    int n; fin >> n;

    vector<vector<int>> a(n, vector<int>(n, 0));

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            fin >> a[y][x];
        }
    }

    int max1 = 0, max2 = 0, num = 0;
    
    map<int, int> s;
    map<int, set<int>> m;
    vector<vector<bool>> tempVisit(n, vector<bool>(n, false));

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            if (tempVisit[y][x] == false)
            {
                max1 = max(max1, solve1(num, y, x, a[y][x], a, m, tempVisit));

                s[num] = a[y][x];

                ++num;
            }
        }
    }

    fout << max1 << '\n' << max2 << '\n';

    return 0;
}
