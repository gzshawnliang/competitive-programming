# 1043F Make It One
***
https://codeforces.com/contest/1043/problem/F

设：$f[i][j]$表示长度是$i,gcd=j$ 的组合数
$m[j]$表示 $j$ 的倍数的数量
$f[i][j]=C_{m[j]}^i-f[i][2\times j]-f[i][3\times j]...-f[i][n\times j]$
可以证明$i$的范围是$1\leq i \leq7$,循环$1$到$7$,当$f[i][1] \gt 0,ans=i$

~~~c++
for (int i = 1; i <= 7; ++i)
{
    for (int j = mx; j >= 1; --j)
    {
        f[i][j] = 1ll * CMMI.C(m[j],i) % MOD;
        for (int k = j + j; k <= mx; k += j)
        {
            f[i][j] -= f[i][k];
            if (f[i][j] < 0)
                f[i][j] += MOD;
        }
    }

    if (f[i][1] > 0)
    {
        cout << i << '\n';
        return;
    }
}
~~~
