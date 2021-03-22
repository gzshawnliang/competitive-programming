# Count the Cows 题解
USACO 2021 February Contest, Gold
Problem 3. Count the Cows

根据题目生成数据，发现在$3^i$长度的正方形内，称为$i$-维正方形A，奶牛位于正对角线和反对角线上的格子，如下红色和黄色部分。蓝色格子代表有奶牛，白色代表无奶牛。

<img src="images/0.png"/>

$i$-维正方形作为整体一个正方形，又拓展为$i+1$维正方形B。B的对角线和反对角线分别是A。每个$i$-维正方形的对角线上的小正方形是$i-1$-维正方形。这样可以无限拓展下去。例如：

## 1维正方形
$ {3\times3 \rightarrow 1\times1} \Rightarrow {3^1\times3^1 \rightarrow 3^0\times3^0}$


<img src="images/1.png"/>

## 2维正方形
$9\times9 \rightarrow 3\times3 \Rightarrow 3^2\times3^2 \rightarrow 3^1\times3^1$
<img src="images/2.png"/>

## 3维正方形
$27\times27 \rightarrow 9\times9 \Rightarrow 3^3\times3^3 \rightarrow 3^2\times3^2$

$\Rightarrow 3^i \times 3^i \Rightarrow 3^{i-1} \times 3^{i-1}$

<img src="images/3.png"/>

## 基础正方形 $3\times3 $

<img src="images/4.png"/>

以下是以$(x,y)$为终点，在基础正方形$3\times3 $内，对角线经过蓝色格子的数量

<img src="images/5.png"/>

## 对称性

对角线$(x,y,d)$表示线段$(x,y) \rightarrow (x+d,y+d) $，进观察发现：对角线蓝色格子数：$(x,y,d)=(y,x,d)$,如下图：

<img src="images/6.png"/>

因此集中考虑黄色的区域，另外一半的区域可以转化成黄色区域的对角线
<img src="images/7.png"/>

## 可叠加

如下图，对角线经过蓝色格子数量： 绿色$=$橙色$+$红色，因此
$ans_{x,y,d}=F_{x+d,y+d} - F_{x-1,y-1}$
$F_{x,y}$ 代表线段$A(0,y-x) \rightarrow B(x,y)$ 经过蓝色格子的数量

<img src="images/8.png"/>

此时问题转换成：任意点(x,y)往对角线走，到左上边缘，经过蓝色格子的数量，如下图：
<img src="images/9.png"/>


<img src="images/11.png"/>
