#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划——字符串的编辑距离
 * s1 = "abc", s2 = "def"
 * 计算公式：
 *          | 0                                           i = 0, j = 0
 *          | j                                           i = 0, j > 0
 * d[i,j] = | i                                           i > 0, j = 0
 *          | min(d[i,j-1]+1, d[i-1,j]+1, d[i-1,j-1])    s1(i) = s2(j)
 *          | min(d[i,j-1]+1, d[i-1,j]+1, d[i-1,j-1]+1)  s1(i) ≠ s2(j)
 * 定义二维数组[4][4]：
 *      d e f            d e f
 *   |x|x|x|x|        |0|1|2|3|
 * a |x|x|x|x|  =>  a |1|1|2|3|  => 编辑距离d = [3][3] = 3
 * b |x|x|x|x|      b |2|2|2|3|
 * c |x|x|x|x|      c |3|3|3|3|
 *
 */

//ifstream fin("EditDistance.in");
//ofstream fout("EditDistance.out");

int min_of_three(int a, int b, int c)
{
    return min(a, min(b, c));
}

int minDistanceRecursion(string & word1, string & word2, int i, int j)
{
    if (j == 0)
    {
        return i;
    }
    else if (i == 0)
    {
        return j;
        
    }
    else if (word1[i - 1] == word2[j - 1])
    {
        return minDistanceRecursion(word1, word2, i - 1, j - 1);
    }
    else
    {

        return min_of_three(minDistanceRecursion(word1, word2, i - 1, j) + 1,
                            minDistanceRecursion(word1, word2, i, j - 1) + 1,
                            minDistanceRecursion(word1, word2, i - 1, j - 1) + 1);
    }
}

int minDistanceDp(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // 初始化空字符串的情况
    for (int i = 1; i <= m; ++i)
    {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // 增加操作：str1a变成str2后再加上b，得到str2b
            int insertion = dp[i][j - 1] + 1;

            // 删除操作：str1a删除a后，再由str1变为str2b
            int deletion = dp[i - 1][j] + 1;

            // 替换操作：先由str1变为str2，然后str1a的a替换为b，得到str2b
            //int replace = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
            int replace = 0;
            if (word1[i - 1] == word2[j - 1])
            {
                replace = 0;
            }
            else
            {
                replace = 1;
            }
            replace += dp[i - 1][j - 1];

            // 三者取最小
            //dp[i][j] = min(replace, min(insertion, deletion));
            dp[i][j] = min_of_three(replace,insertion,deletion);
        }
    }
    return dp[m][n];
}

int main()
{
    string source = "sailn";
    string target = "failing";
    cout << source << "->" << target << '\n';
    cout << "edit distance Dp = " << minDistanceDp(source, target) << '\n';
    cout << "edit distance Recursion = " << minDistanceRecursion(source, target, source.length(), target.length()) << '\n';

    return 0;
}