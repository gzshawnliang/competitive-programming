/*
===========================================================
 * @名称:		Dropping tests
 * @作者:		Shawn 
 * @创建时间: 2019-12-25 17:17:50 
 * @修改人:   Shawn 
 * @修改时间: 2019-12-25 17:17:50 
 * @备注:	    分数规划模板题	
 * @题目来源： http://poj.org/problem?id=2976
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("POJ_2976.in");
ofstream fout("POJ_2976.out");

bool check(int k, double mid, vector<int> &a, vector<int> &b)
{
    int n = a.size();

    vector<double> p(n, 0);
    for (int i = 0; i <= n - 1; ++i)
    {
        p[i] = (double)a[i] - mid * (double)b[i];
    }

    sort(p.begin(), p.end(), greater<int>());

    double ans = 0.0;
    for (int i = 0; i <= k - 1; ++i)
    {
        ans += p[i];
    }

    return ans >= 0.0;
}

int main()
{
    while (true)
    {
        int n = 0, k = 0; fin >> n >> k;
        if (n + k == 0) break;

        k = n - k;

        vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i <= n - 1; ++i) fin >> a[i];
        for (int i = 0; i <= n - 1; ++i) fin >> b[i];

        double l = 0.0, r = 1.0;
        for (int c = 1; c <= 100; ++c)
        {
            double mid = (l + r) / 2;

            if (check(k, mid, a, b) == true)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        fout << (int)(l * 100.0 + 0.5) << '\n';
    }

    return 0;
}
