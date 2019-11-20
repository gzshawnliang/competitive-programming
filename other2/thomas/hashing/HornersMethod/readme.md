# Horner's method 减少乘法运算
***

## 概述
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

乘法运算明显减少, 而加法运算次数不变。

当$n=1000$情况如何？

|计算式                              |乘法运算（次数）                    |加法运算（次数）|
|:--------------------------------- |:--------------------------------|:------------|
| $p^{1000}+p^{999}+ \cdots +p^{2}+p$ |$$\begin{align} \nonumber & =999+998+997+\cdots +1 \\\\ \nonumber &= \frac{(999+1)\times999}2 \\\\ \nonumber &= 499500 \end{align}$$   | $1000$         |
| $p \times \Bigg( p \times \bigg(p \times \big( p \times \cdots \times (p+1) + \cdots +1 \big)+1\bigg)+1 \Bigg)$  | $1000$ | $1000$ |

## 时间复杂度
|计算式                              |乘法运算                    |加法运算|
|:--------------------------------- |:--------------------------------|:------------|
| $p^{1000}+p^{999}+ \cdots +p^{2}+p$ |$\Large \frac{n \times(n-1)}2$ <br> 时间复杂度：$O(n^2)$   | $O(n)$         |
| $p \times \Bigg( p \times \bigg(p \times \big( p \times \cdots \times (p+1) + \cdots +1 \big)+1\bigg)+1 \Bigg)$  | $O(n)$ | $O(n)$ |

## MATLAB的Horner's method函数为horner 测试

$$
hash[i] =s[0] \times p^{i} + s[1] \times p^{i-1} + s[2] \times p^{i-2}+ s[3] \times p^{i-3} + \cdots +s[i]
$$



## 参考
https://www.quora.com/q/threadsiiithyderabad/String-Hashing-for-competitive-programming
http://codeforces.com/blog/entry/4898
https://www.geeksforgeeks.org/palindrome-substring-queries/
https://www.zybuluo.com/moyujiang/note/1612931
https://www.cnblogs.com/henry-1202/p/10324966.html
https://ngunauj.github.io/2017/08/02/字符串哈希算法/
https://blog.csdn.net/zsc2014030403015/article/details/51274118