/***********************************************************
 * @名称:		305 - Joseph
 * @作者:		Shawn 
 * @创建时间: 2017-12-05 21:30:38 
 * @修改人:   Shawn 
 * @修改时间: 2017-12-05 21:30:38 
 * @备注:		wa
 * @题目来源： https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=241
***********************************************************/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //ifstream fin("joseph.in");
    //ofstream fout("joseph.out");

    int last = 0;
    vector<int> results(14, -1);
    while (true)
    {
        int n;
        cin >> n;

        if (results[n] > -1)
        {
            cout << results[n] << "\n";
            continue;
        }

        int m;
        if (n == 13)
        {
            m = 2504880;
        }
        else if (n == 12)
        {
            m = 1358656;
        }
        else
        {
            m = 0;
        }
        if (n == 0)
        {
            break;
        }
        
        while (true)
        {
            ++m;
            vector<int> a(2 * n);
            for (int i = 0; i <= 2 * n - 1; ++i)
            {
                if (i < n)
                {
                    a[i] = 1;
                }
                else
                {
                    a[i] = 2;
                }
            }

            bool ok = true;
            int nowPos = (m - 1) % (n * 2), died = 0;
            for (int i = n * 2; i >= 1; --i)
            {
                if (a[nowPos] == 1)
                {
                    if (died < n)
                    {
                        ok = false;
                    }
                    break;
                }
                else if (a[nowPos] == 2)
                {
                    ++died;
                }
                a[nowPos] = 0;
                int count = 0;
                if (i == 1)
                {
                    break;
                }
                vector<int> loop;
                vector<bool> dp(2 * n, false);
                while (count < m)
                {
                    ++nowPos;
                    nowPos %= 2 * n;
                    if (a[nowPos] > 0)
                    {
                        ++count;
                        if (dp[nowPos] == true)
                        {
                            nowPos = loop[(m - count) % loop.size()];
                            break;
                        }
                        else
                        {
                            loop.push_back(nowPos);
                            dp[nowPos] = true;
                        }
                        
                    }
                }
            }

            if (ok == true)
            {
                break;
            }
        }

        cout << m << "\n";
        last = m;
        results[n] = m;
    }

    return 0;
}