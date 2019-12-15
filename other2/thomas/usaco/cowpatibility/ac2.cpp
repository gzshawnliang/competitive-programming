#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("cowpatibility.in", "r", stdin);
        freopen("cowpatibility.out", "w", stdout);
    #endif

    map<string, long long> f;
    long long n, Ans, ans;
    string s;

    cin >>n;
    Ans = n * (n - 1) / 2; //总共对数

    for (int i = 1; i <= n; i++)
    {
        vector<string> a(6);      
        for (int j = 1; j <= 5; j++)
            cin >> a[j];

        sort(a.begin() + 1, a.end()); //从小到大排序
        int len = 32;
        ans = 0;
        for (int i = 1; i < len; i++)
        { 
            //二进制枚举出所有情况
            int cnt = 0;
            string s = "";
            for (int j = 1; j <= 5; ++j)
            {
                if (i & (1 << (j - 1)))
                {
                    cnt++;
                    s += "?" + a[j];
                } //将选出的口味用“？”连接出来
            }
            if (cnt %2 ==1)
                ans += f[s]++; //奇数个则累加
            else
                ans -= f[s]++; //否则减去
        }
        Ans -= ans; //减去和谐的，容斥
    }
    cout << Ans;
    return 0;
}