#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

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
        auto compareFunc = [](const double x, const double y) { return x > y; };
        sort(c.begin() + 1, c.end(),compareFunc);

        //取出最大的前k个
        for (int i = 1; i <= k ; ++i)
            s += c[i];

        //if (s > 0)
        //{
            cout << "m:" << setw(12) << mid << ": ";
            for (int i = 1; i <= k; ++i)
            {
                cout << setw(15) << c[i] << " ";
            }
            cout << "f(m): " << setw(12) << s << " \n";
        //}

        return s > 0;
    }    

    double getMaxFraction()
    {
        //二分
        double L = 0, R = 1e9;
        while (R - L > eps)
        {
            double m = (L + R) / 2.0;
            cout << "L:" << setw(12) <<  L << " R:" << setw(12) << R << ",";
            if (check(m)) 
                L = m;    //mid 可行，答案比 mid 大
            else 
                R = m;    //mid 太大，不可行，答案比 mid 小
        }
        return L;
    }

};

int main()
{
    //输入
#ifndef ONLINE_JUDGE
    freopen("frac-programming.in", "r", stdin);
    //freopen("frac-programming.out", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    fraction frac1(n,k);
    string s;
    getline(cin,s);

    getline(cin,s);
    stringstream ssa(s);

    for (int i = 1; i <= n; ++i)
        ssa >> frac1.a[i];

    getline(cin,s);

    stringstream ssb(s);
    ssb.str(s);

    for (int i = 1; i <= n; ++i)
        ssb >> frac1.b[i];

    //输出
    cout << frac1.getMaxFraction() << "\n";
    return 0;
}