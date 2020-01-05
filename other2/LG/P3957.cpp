#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

ifstream fin("P3957.in");
ofstream fout("P3957.out");

const int inf = 2147483647;

struct grid
{
    int d;
    int v;
};

int maxPoint(int g, int d, vector<grid> & m)
{
    int ans = -1 * inf, n = m.size(), left = max(1, d - g), right = d + g, j = 0, head = 1, tail = 0;

    vector<int> dp(n, -1 * inf), q(500001, 0);
    dp[0] = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        while (m[i].d - m[j].d >= left && j < i)
        {
            if (dp[j] != -1 * inf)
            {
                while (head <= tail && dp[q[tail]] <= dp[j])
                {
                    --tail;
                }

                ++tail;
                q[tail] = j;
            }

            ++j;
        }

        while (head <= tail && m[i].d - m[q[head]].d > right)
        {
            ++head;
        }

        if (head <= tail)
        {
            dp[i] = dp[q[head]] + m[i].v;
            ans = max(ans, dp[i]);
        }
    }

    return ans;
}

int main()
{
    int n, d, k; fin >> n >> d >> k;
    ++n;

    long long _sum = 0;

    vector<grid> m(n);
    m[0].d = 0; m[0].v = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        fin >> m[i].d >> m[i].v;

        if (m[i].v >= 0)
        {
            _sum += m[i].v;
        }
    }

    if (_sum < k)
    {
        fout << "-1\n";
        return 0;
    }

    int l = 0, r = max(m.back().d, d), ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        
        int res = maxPoint(mid, d, m);

        if (res < k)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }

    fout << ans << '\n';

    return 0;
}