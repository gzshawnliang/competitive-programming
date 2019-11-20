# Horner's method 霍纳法则
***

## 概述
Horner's method 霍纳法则可减少乘法运算,

此规则就是将多项式转换为嵌套形式，例如,当$n=5$
$$\begin{align}
p^5+p^4+p^3+p^2+p \nonumber &= p \times(p^4+p^3+p^2+p+1)\\\\ \nonumber
&=p \times \big( p \times (p^3+p^2+p^1+1)+1 \big) \\\\ \nonumber
&=p \times \Big( p \times \big(p \times (p^2+p^1+1)+1\big)+1 \Big)\\\\ \nonumber
&=p \times \Bigg( p \times \bigg(p \times \big( p \times (p+1) +1 \big)+1\bigg)+1 \Bigg) 
\end{align}
$$
转化后, 阅读起来还像更费力了, 因为有很多括号。但是这个形式有一个最大的优点: 计算效率高!



## 效率比较
|计算式                              |乘法运算（次数）                    |加法运算（次数）|
|:----------------------------------|:--------------------------------|:------------|
| $p^5+p^4+p^3+p^2+p$               |$4 + 3 + 2 + 1 = 10$             | $4$         |
| $p \times \Bigg( p \times \bigg(p \times \big( p \times (p+1) +1 \big)+1\bigg)+1 \Bigg)$  | $4$ | $4$ |

乘法运算明显减少, 而加法运算次数不变。当$n=1000$ 情况如何？

|计算式                              |乘法运算（次数）                    |加法运算（次数）|
|:--------------------------------- |:--------------------------------|:------------|
| $p^{1000}+p^{999}+ \cdots +p^{2}+p$ |$$\begin{align} \nonumber & =999+998+997+\cdots +1 \\\\ \nonumber &= \frac{(999+1)\times999}2 \\\\ \nonumber &= 499500 \end{align}$$   | $1000$         |
| $p \times \Bigg( p \times \bigg(p \times \big( p \times \cdots \times (p+1) + \cdots +1 \big)+1\bigg)+1 \Bigg)$  | $1000$ | $1000$ |

## 时间复杂度
|计算式                              |乘法运算                    |加法运算|
|:--------------------------------- |:--------------------------------|:------------|
| $p^{1000}+p^{999}+ \cdots +p^{2}+p$ |$\Large \frac{n \times(n-1)}2$ <br> 时间复杂度：$O(n^2)$   | $O(n)$         |
| $p \times \Bigg( p \times \bigg(p \times \big( p \times \cdots \times (p+1) + \cdots +1 \big)+1\bigg)+1 \Bigg)$  | $O(n)$ | $O(n)$ |

## MATLAB的Horner's method 函数为 horner 测试

$$
hash[i] =s[0] \times p^{i} + s[1] \times p^{i-1} + s[2] \times p^{i-2}+ s[3] \times p^{i-3} + \cdots +s[i]
$$

## 代码示例

$p^5+p^4+p^3+p^2+p$
```c++
ull pow = 1;
ull hashcode = 0;
for (int i = 1; i <= 5; ++i)
{
    hashcode += p * pow;
    pow *= p;
}
return hashcode;
```
$p \times \Bigg( p \times \bigg(p \times \big( p \times (p+1) +1 \big)+1\bigg)+1 \Bigg)$
```c++
ull hashcode = 0;
for (int i = 1; i <= 5; ++i)
    hashcode = p * (hashcode + 1);

return hashcode;
```

## 通用公式
$$\begin{align}
h(x) \nonumber &=a_0 + a_1\times p^1+a_2\times p^2+a_3\times p^3+ \cdots +a_n\times p^n\\ 
     \nonumber &=a_0 + p \times \bigg(a_1+ p\times \Big(a_2 + p \times \big( a_3 + \cdots + p \times (a_{n-1}+a_n \times x) \cdots \big) \Big) \bigg)
\end{align}
$$
## 字符串哈希应用
字符串$S$的长度$|S|=n,n \geq 0,S[0]=S_0,S[1]=S_1,\cdots\,S[i]=S_i$，哈希计算式：

$$\begin{align}
hash(S) \nonumber &=s_0 + s_1\times p^1+s_2\times p^2+s_3\times p^3+ \cdots +s_{n-1}\times p^{n-1}\\ 
     \nonumber &=s_0 + p \times \bigg(s_1+ p\times \Big(s_2 + p \times \big( s_3 + \cdots + p \times (s_{n-1}+s_n \times p) \cdots \big) \Big) \bigg)
\end{align}
$$

一般倒过来计算
$$\begin{align}
hash(S) \nonumber &=s_0 \times p^{n-1} + s_1\times p^{n-2}+s_2\times p^{n-3}+s_3 \times p^{n-4}+ \cdots +s_{n-1}\times p^0\\ 
     \nonumber &=s_{n-1} + p \times \bigg(s_{n-2}+ p\times \Big(s_{n-3} + p \times \big(s_{n-4} + \cdots + p \times (s_1+s_0 \times p) \cdots \big) \Big) \bigg)
\end{align}
$$

```c++
int len = s.length();
ull hashValue = 0;
for (int i = 0; i <= len-1; ++i)
    hashValue = p * hashValue + s[i];

return hashValue;
```
## 示例
$S=abcd,质数p=3$

ASCII
|字母|ASCII|
|---|-----|
| a | 97  |   
| b | 98  |   
| c | 99  |   
| d | 100 |   

普通方式
$hash(S) =97\times p^3+98\times p^2+99\times p^1 +100 = 3898$

霍纳法则:
$hash(S) =100+ p \times \big(99 + p \times (98 + 97 \times p)\big) = 3898$




## 参考
https://zh.wikipedia.org/zh-hans/秦九韶算法
https://en.wikipedia.org/wiki/Horner's_method