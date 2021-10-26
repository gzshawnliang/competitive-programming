# 803F Coprime Subsequences
***
https://codeforces.com/problemset/problem/803/F


## 分析

### 概述

类似839D

$Input={2,3,4,6}$

$f(i)$是满足$GCD=i$所有的集合数量，
例如$f(2)$的集合有：$\{2\},\{2,4\},\{2,6\},\{4,6\},\{2,4,6\}$
$f(2)=5$


$ans=f(1)$
或
$ans= 2^n - \sum_{i=2}^{10^6} f(i)$

### 如何求$f(i)?$

$f(2)$有集合：$\{2\},\{2,4\},\{2,6\},\{4,6\},\{2,4,6\}$  ~~{4},{6}~~
发现是2,4,6这3个数的全部的组合移除组合4,6，既：$C_3^1+C_3^2+ C_3^3 - f(4) - f(6)$ 
$f(2)=(7-1-1)=5$

假设$i$的倍数有$n$个，则
$$f(i)=(\sum_{i}^{n}C_n^i)-f(2\times i) - f(3\times i) ... - f(k\times i)$$
期中$k\times i <=$ 最大的数

考虑以下组合公式公式成立：
$$C_n^1 + C_n^2+ C_n^3+...+ C_n^n=2^n$$
则：
$$f(i)=2^n-f(2\times i) - f(3\times i) ... - f(k\times i)$$
期中$k\times i <=$ 最大的数

$$f(i)=2^n-\sum_{k=2}^{k*i\leq 最大的数}f(k\times i)$$
期中$n$的代表：$i$的倍数有$n$个

因为$f(i)$需要减去交大的$f(k\times i)$,因此需要从最大的$i$开始计算$f(i)$

```c++
for (int i = mx; i >= 1; --i)
{
    f[i] = (1ll * pow2[m[i]] - 1 +mod ) % mod;
    for (int j = i + i; j <= mx; j += i)
        f[i] = (1ll * f[i] - 1ll * f[j]+ 1ll * mod) % mod;
}
cout << f[1] << "\n";
```

## 参考

What is a Combination?
https://corporatefinanceinstitute.com/resources/knowledge/other/combination/

Combination
https://en.wikipedia.org/wiki/Combination
https://artofproblemsolving.com/wiki/index.php/Combination


### 组合公式
常用组合数计算公式
https://blog.csdn.net/shadandeajian/article/details/82084087?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task

### 容斥原理
Principle of Inclusion-Exclusion
https://artofproblemsolving.com/wiki/index.php/Principle_of_Inclusion-Exclusion


## 常用组合公式证明

### $C_n^m= \cfrac{n!}{m!\times (n-m)!}$

### $C_{n}^{m}=C_{n-1}^{m-1} + C_{n-1}^{m}$  (帕斯卡恒等式)
https://artofproblemsolving.com/wiki/index.php/Pascal%27s_Identity


### $m\times C_n^m=n\times C_{n-1}^{m-1}$

$$\begin{align}
m\times C_n^m &=m\times \cfrac{n!}{m!\times (n-m)!} \\\\ \nonumber 
&= \cfrac{n!}{(m-1)!\times (n-m)!} \\\\ \nonumber
&= n \times \cfrac{(n-1)!}{(m-1)!\times (n-m)!} \\\\ \nonumber
&= n \times C_{n-1}^{m-1} \\\\ \nonumber
\end{align}
$$

### $C_n^0+C_n^1+C_n^2+...+C_n^n=2^n$


### $1\times C_n^1+2\times C_n^2+ 3\times C_n^3 + ... + n\times C_n^n = n \times 2^{n-1}$

