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

const double eps=1e-10;

struct coefficient
{
    int a,b,c;
};


double f(double x,vector<coefficient> & coefficients,int n)
{
    //int n=coefficients.size();
    double ret = coefficients[0].a * x * x + coefficients[0].b * x + coefficients[0].c;
    for (int i = 1; i <= n - 1; ++i)
    {
        ret=max(ret,coefficients[i].a * x * x + coefficients[i].b * x + coefficients[i].c);
    }
    return ret;
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
        vector<coefficient> coefficients;
        int size1=n;
        while (size1--)
        {
            coefficient coe;
            cin >> coe.a >> coe.b >> coe.c;
            coefficients.push_back(coe);
        }
        
        double right =1000.0;
        double left =0.0;
        double midl, midr;
        while (right-left > eps)
        {
            midl = (left + right) / 2;
            midr = (midl + right) / 2;
            
            //如果是求最大值的话这里判>=即可
            //如果是求最小值的话这里判<=即可
            if(f(midl,coefficients,n) <= f(midr,coefficients,n))
                right = midr;
            else left = midl;
        }
        cout << f(left,coefficients,n) << "\n";

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