/***********************************************************
 * @名称:   UVA 10940 	Throwing cards away II		
 * @作者:		Shawn 
 * @创建时间: 2018-03-10 21:07:44 
 * @修改人:   Shawn 
 * @修改时间: 2018-03-10 21:07:44 
 * @备注:	  解法：测试数据从1到50万，暴力求解之后找规律。
 * 或者研究约瑟夫问题《具体数学》,一下是约瑟夫解法
 * int main()  
{  
    int n, tmp, cnt, ans;  
    while (scanf("%d", &n), n)  
    {  
        cnt = 0;  
        for (tmp = n; tmp; tmp >>= 1) 
            ++cnt;  
            
        ans = (n - (1 << (cnt - 1))) << 1;  
        printf("%d\n", ans ? ans : n);  
    }  
    return 0;  
}  
 * @题目来源： http://uva.onlinejudge.org/external/109/10940.pdf
***********************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

ifstream fin("throwingCards.in");
ofstream fout("throwingCards.out");

int main()
{
    vector<int> times;
    int temp = 1;
    for (int i = 0; i <= 19; ++i)
    {
        times.push_back(temp);
        temp *= 2;
    }

    while (true)
    {
        int n;
        fin >> n;

        if (n == 0)
        {
            break;
        }

        for (int i = 19; i >= 0; --i)
        {
            if (n > times[i])
            {
                fout << (n - times[i]) * 2 << '\n';
                break;
            }
            else if (n == times[i])
            {
                fout << n << '\n';
                break;
            }
        }
    }

    return 0;
}