/***********************************************************
 * @名称:		创建质数
 * @作者:		Shawn 
 * @创建时间: 2018-01-08 19:48:54 
 * @修改人:   Shawn 
 * @修改时间: 2018-01-08 19:48:54 
 * @备注:		
 * @题目来源： 
***********************************************************/
#include <cstdio>
#include <cstdlib>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ofstream fout("prime.out");

int main()
{
    long long length = 1, nowNum = 3;
    vector<long long> prime;
    prime.push_back(2);
    while (length < 1e6)
    {
        bool ok = true;
        for (long long i = 1; i <= length - 1; ++i)
        {
            long long temp = prime[i];
            if (temp > nowNum / 2)
            {
                ok = true;
                break;
            }
            else if (nowNum % temp == 0)
            {
                ok = false;
                break;
            }
        }

        if (ok == true)
        {
            prime.push_back(nowNum);
            ++length;
        }

        nowNum += 2;
    }

    for (long long i = 0; i <= length - 1; ++i)
    {
        fout << prime[i] << '\n';
    }

    return 0;
}