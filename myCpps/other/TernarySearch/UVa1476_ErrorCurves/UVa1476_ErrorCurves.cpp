/*
===========================================================
* @Name:           UVa-1476 Error Curves
* @Author:         Thomas
* @create Time:    2020/5/23 20:02:29
* @url:            https://onlinejudge.org/external/14/1476.pdf
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

struct coefficient //系数
{
    int a, b, c;
};

//二次方程式
double f(double x, vector<coefficient> & coefficients, int n)
{
    //int n=coefficients.size();
    double ret = coefficients[0].a * x * x + coefficients[0].b * x + coefficients[0].c;
    for (int i = 1; i <= n - 1; ++i)
        ret = max(ret, coefficients[i].a * x * x + coefficients[i].b * x + coefficients[i].c);

    return ret;
}

//三分搜索
//https://yuihuang.com/ternary-search/
//https://blog.csdn.net/u011787119/article/details/44598871
double ternary_search(double left, double right, vector<coefficient> & coefficients, int n)
{
    double midL, midR, ans;
    while (right - left > eps)
    {
        midL = (left + right) / 2.0;
        midR = (midL + right) / 2.0;

        double fL = f(midL, coefficients, n);
        double fR = f(midR, coefficients, n);

        //如果是求最大值的话这里判>=即可
        //如果是求最小值的话这里判<=即可
        if (fL <= fR)
            right = midR;
        else
            left = midL;

        ans = fL;
    }
    return ans;
}

//三分搜索2
//https://cp-algorithms.com/num_methods/ternary_search.html
//https://www.geeksforgeeks.org/ternary-search/
double ternary_search2(double left, double right, vector<coefficient> & coefficients, int n)
{
    double midL, midR, ans;
    while (right - left > eps)
    {
        midL = left + (right - left) / 3.0;
        midR = right - (right - left) / 3.0;

        double fL = f(midL, coefficients, n);
        double fR = f(midR, coefficients, n);

        //如果是求最大值的话这里判>=即可
        //如果是求最小值的话这里判<=即可
        if (fL <= fR)
            right = midR;
        else
            left = midL;

        ans = fL;
    }
    return ans;
}

void solve()
{
    cout << fixed << std::setprecision(4);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<coefficient> coefficients; //输入的系数
        int size1 = n;
        while (size1--)
        {
            coefficient coe;
            cin >> coe.a >> coe.b >> coe.c;
            coefficients.push_back(coe);
        }
        double ans = ternary_search2(0.0, 1000.0, coefficients, n);
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("UVa1476_ErrorCurves.in", "r", stdin);
    //freopen("UVa1476_ErrorCurves.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}