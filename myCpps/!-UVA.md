# 动态规划练习

## LIS 问题

 |       | 标题                         | 难度    | 说明                                                                                                                         |
 | ----: | ---------------------------- | ------- | ---------------------------------------------------------------------------------------------------------------------------- |
 | 111   | History Grading              | Lev 1 √ | 注意input数据,和常规理解不同："事件1在位置3"，"事件2在位置1"，"事件3在位置2"......"事件10在位置7"。                          |
 | 231   | Testing the CATCHER          | Lev 2 √ | 简单LIS                                                                                                                      |
 | 437   | The Tower of Babylon         | Lev 2 √ | 隐式LIS                                                                                                                      |
 | 10051 | Tower of Cubes               | Lev 3   | 一些重量递增而且各个面都有颜色的立方体，要将这些立方体堆成一个塔，要求两个接触面同色，而且下面的立方体更重。求塔的最大高度。 |
 | 481   | What Goes Up ★               | Lev 2 √ | 数据量比较大，需要O(n log k) 的LIS算法                                                                                       |
 | 497   | Strategic Defense Initiative | Lev 2   | 简单LIS                                                                                                                      |
 | 1196  | Tiling Up Blocks             | Lev 4   | 二维的LIS                                                                                                                    |
 | 10131 | Is Bigger Smarter?           | Lev 2   | LIS递增的条件不同，数据规模较小，O(n^2)可以过                                                                                |
 | 10534 | Wavio Sequence               | Lev 3 √ | 需要O(n log k) 的LIS算法                                                                                                     |
 | 11368 | Nested Dolls                 | Lev 4   | 俄罗斯套娃                                                                                                                   |
 | 11456 | Trainsorting ★               | Lev 3 √ | 将序列逆序储存，然后用o(n^2)方法分别求出最长上升子序列和最长下降子序列。                                                     |
 | 11790 | Murcia's Skyline ★           | Lev 3 √ | 带权LIS，翻译：http://m80126colin.github.io/blog/articles/翻譯/uva/uva11790/                                                 |

## 0-1背包问题

 |       | 标题                    | 难度    |说明
 | ----: | ----------------------- | ------- | ---------- |
 | 431   | Trial of the Millennium | Lev 5   |
 | 624   | CD                      | Lev 2 √ |
 | 562   | Dividing coins          | Lev 2   |
 | 990   | Diving for Gold         | Lev 3   |
 | 1213  | Sum of Different Primes | Lev 3 √ |
 | 10130 | SuperSale               | Lev 2 √ | 明显的 0-1背包 |
 | 10261 | Ferry Loading           | Lev 3 √ |
 | 10616 | Divisible Group Sums ★  | Lev 3  |
 | 10664 | Luggage                 | Lev 2 √ |
 | 10819 | Trouble of 13 ★         | Lev 3 √ | 明显的 0-1背包 |
 | 11003 | Boxes                   | Lev 3   |
 | 11341 | Term Strategy           | Lev 4   |
 | 11566 | Let's Yum Cha! ★        | Lev 4   |
 | 11658 | Best Coalitions         | Lev 4   |
 | 10980 | Lowest Price in Town    | Lev 4   |
 | 11450 | Wedding shopping        | Lev 2 √  |背包+滚动数组


<style>
    table td:nth-of-type(3) {
        white-space: nowrap; 
    }
    table td:nth-of-type(2) {
        white-space: nowrap; 
    }
</style>