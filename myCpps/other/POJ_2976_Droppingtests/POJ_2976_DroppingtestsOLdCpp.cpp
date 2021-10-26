#include <iostream>
//#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const double eps = 1e-7;

bool compare(const int & a,const int & b)
{
	return a>b;
}

class fraction
{
    int n, k;

    public:
    vector<int> a;
    vector<int> b;    

    fraction(int n,int k)
    {
        this->n=n;
        this->k=k;

        a.assign(n+1,0);
        b.assign(n+1,0);
    }

    bool check(double mid)
    {
        double s = 0;
        vector<double> c(n + 1);
        for (int i = 1; i <= n; ++i)
            c[i] = (double)a[i] - mid * (double)b[i];

        //从大到小排序
        sort(c.begin() + 1, c.end(), compare);

        //取出前n-k个
        for (int i = 1; i <= n-k ; ++i)
            s += c[i];

        return s > 0;
    }    

    double getMaxFraction()
    {
        //二分
        double L = 0, R = 1e9;
        while (R - L > eps)
        {
            double mid = (L + R) / 2.0;
            if (check(mid)) 
                L = mid;    //mid 可行，答案比 mid 大
            else 
                R = mid;    //mid 不可行，答案比 mid 小
        }
        return L;
    }

};

int main()
{
    //输入
#ifndef ONLINE_JUDGE
    freopen("POJ_2976_Droppingtests.in", "r", stdin);
    //freopen("frac-programming.out", "w", stdout);
#endif

    while (true)
    {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;

        fraction frac1(n, k);
        string s;
        getline(cin, s);

        getline(cin, s);
        stringstream ssa(s);

        for (int i = 1; i <= n; ++i)
            ssa >> frac1.a[i];

        getline(cin, s);

        stringstream ssb(s);
        ssb.str(s);

        for (int i = 1; i <= n; ++i)
            ssb >> frac1.b[i];

        //输出
        cout << (int)(frac1.getMaxFraction() *100+0.5) << "\n";
    }

    return 0;
}