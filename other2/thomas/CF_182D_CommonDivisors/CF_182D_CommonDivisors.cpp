/*
===========================================================
 * @名称:    182D Common Divisors
 * @作者:    Thomas 
 * @创建时间: 2019-11-08 16:28:30 
 * @修改人:   Thomas 
 * @修改时间: 2019-11-08 16:28:30 
 * @备注:    字符串的前i项是Divisor
 * @题目来源： https://codeforces.com/problemset/problem/182/D
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_182D_CommonDivisors.in", "r", stdin);
        //freopen("CF_182D_CommonDivisors.out", "w", stdout);
    #endif
    
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    int ans = 0;
    int minLen = min(n, m);
    
    //i代表字符串的前i项
    for (int i = 1; i <= minLen; ++i)
    {
        bool isOK = true;

        //不能整除i，肯定不是Divisor
        if (n % i != 0 || m % i != 0)
            continue;

        //判断字符串的前i项是否Divisor
        for (int j = 0; j <= n - 1; ++j)
            if (s1[j] != s1[j % i])
            {
                isOK = false;
                break;
            }

        //不是s1的Divisor
        if (!isOK)
            continue;

        //判断字符串的前i项是否Divisor
        for (int j = 0; j <= m - 1; ++j)
            if (s2[j] != s2[j % i])
            {
                isOK = false;
                break;
            }
        
        //不是s2的Divisor
        if (!isOK)
            continue;

        //判断s1的前i项和s2的前i项是否相同
        for (int j = 0; j <= i - 1; ++j)
            if (s1[j] != s2[j])
            {
                isOK = false;
                break;
            }

        if (!isOK)
            continue;
        else 
            ++ans;
    }

    cout << ans << "\n";

    return 0;
}
