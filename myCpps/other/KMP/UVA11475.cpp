/*
===========================================================
 * @名称:       UVA-11475 - Extend to Palindrome
 * @作者:       Shawn 
 * @创建时间:    2019-08-30 22:13:18 
 * @修改人:      Shawn
 * @修改时间:     2019-08-30 22:13:18 
 * @备注:        KMP next数组的应用 （学习kmp入门题）
 * 
 * s:ebeb
 * p:bebe 
 *              012345678
 * p1:p+'-'+s = bebe-ebeb
 * 
 * 使用next数组得知p1最长前后缀长度是3（beb），next的最后一项的值len
 * ans = s + p去掉最长公共前后缀 = p.substr(len, p.length() - 1) 
 * @题目来源：    https://uva.onlinejudge.org/external/114/11475.pdf
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("UVA11475.in");
ofstream fout("UVA11475.out");

class KMP
{
  public:
    int build(const string & P)
    {
        //调用kmpSearch()之前调用此函数

        vector<int> next; //next[j]表示当P[j] != T[i] 时候，j要回到那个位置

        //初始化变量
        int m = P.length();
        next.assign(m + 1, 0);

        int j = 0;
        int k = -1;

        next[0] = -1; // 起始值，-1代表移动i
        while (j <= m - 1)
        {
            //使用字符串P预处理数组next
            while (k >= 0 && P[j] != P[k])
                k = next[k]; // 如果不同，使用next数组重设k值,直到相同或-1（开始指针的位置）

            ++j;
            ++k; //如果一样，两个指针都往右移动next[j+1]==k+1
            next[j] = k;
        }
        return next[m];
    }
};

int main()
{
    string s;
    while (fin >> s)
    {
        string p = s;
        reverse(p.begin(), p.end());
        string p1 = p + "-" + s;
        KMP kmp;
        int len = kmp.build(p1);
        fout << s << p.substr(len, p.length() - 1) << '\n';
    };

    return 0;
}
