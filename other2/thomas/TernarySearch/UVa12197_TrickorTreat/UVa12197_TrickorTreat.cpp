/*
===========================================================
* @Name:           UVa-12197 Trick or Treat
* @Author:         Thomas
* @create Time:    2020/5/25 10:24:05
* @url:            https://onlinejudge.org/external/121/12197.pdf
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const double eps = 1e-10;

double f(double m, vector<double> & x, vector<double> & y, int n)
{
    double ret = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        ret = max(ret, (m - x[i]) * (m - x[i]) + y[i] * y[i]);
    }
    return ret;
}

double f2(double m, vector<double> & x, vector<double> & y, int n)
{
    double ret = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        ret = max(ret, sqrt((m - x[i]) * (m - x[i]) + y[i] * y[i]));
    }
    return ret;
}

double ternary_search(double & left, double right, vector<double> & x, vector<double> & y, int n)
{
    double midL, midR, ans;
    while (right - left > eps)
    {
        midL = (left + right) / 2.0;
        midR = (midL + right) / 2.0;

        double fL = f(midL, x,y, n);
        double fR = f(midR, x,y, n);

        //如果是求最大值的话这里判>=即可
        //如果是求最小值的话这里判<=即可
        if (fL <= fR)
            right = midR;
        else
            left = midL;

        ans = fL;
    }
    return f2(left, x, y, n);
}

double ternary_search2(double & left, double right, vector<double> & x, vector<double> & y, int n)
{
    double midL, midR, ans;
    while (right - left > eps)
    {
        midL = left + (right - left) / 3.0;
        midR = right - (right - left) / 3.0;

        double fL = f(midL, x, y, n);
        double fR = f(midR, x, y, n);

        //如果是求最大值的话这里判>=即可
        //如果是求最小值的话这里判<=即可
        if (fL <= fR)
            right = midR;
        else
            left = midL;
    }
    return f2(left, x, y, n);
}

void solve()
{
    cout << fixed << std::setprecision(9);
    while (true)
    {
        int n = 0;
        cin >> n;
        if (n == 0)
            break;

        vector<double> x(n);
        vector<double> y(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> x[i] >> y[i];
        }

        double left = -200000.0;
        double right = 200000.0;
        //double ans = ternary_search(left, right, x, y, n);
        double ans = ternary_search2(left, right, x, y, n);
        cout << left+ 5e-10 << " " << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("UVa12197_TrickorTreat.in", "r", stdin);
    freopen("UVa12197_TrickorTreat.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}