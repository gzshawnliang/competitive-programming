# Count the Cows 题解
USACO 2021 February Contest, Gold
Problem 3. Count the Cows
$ {3\times3 \rightarrow 1\times1} \Rightarrow {3^1\times3^1 \rightarrow 3^0\times3^0}$


<img src="images/1.png"/>

$9\times9 \rightarrow 3\times3 \Rightarrow 3^2\times3^2 \rightarrow 3^1\times3^1$
<img src="images/2.png"/>

$27\times27 \rightarrow 9\times9 \Rightarrow 3^3\times3^3 \rightarrow 3^2\times3^2$

$\Rightarrow 3^i \times 3^i \Rightarrow 3^{i-1} \times 3^{i-1}$

<img src="images/3.png"/>

<img src="images/4.png"/>


<img src="images/5.png"/>

## 对称性

对角线x,y,d=对角线y,x,d,如下图

<img src="images/6.png"/>

因此集中考虑黄色的区域，另外一半的区域可以转化成黄色区域的对角线
<img src="images/7.png"/>

## 可叠加

如下图，对角线经过蓝色格子数量： $ans绿色=ans橙色+ans红色$，因此
$ans_{x,y,d}=F_{x+d,y+d} - F_{x-1,y-1}$
$F_{x,y}$ 代表线段$A(0,y-x) \rightarrow B(x,y)$ 经过蓝色格子的数量

<img src="images/8.png"/>