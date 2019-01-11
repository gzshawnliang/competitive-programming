/***********************************************************
 * @名称:		10170 - The Hotel with Infinite Rooms
 * @作者:	    Shawn 
 * @创建时间: 2018-03-11 09:07:05 
 * @修改人:   Shawn 
 * @修改时间: 2018-03-11 09:07:05 
 * @备注:		等差数列求和
 * @题目来源： https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1111&mosmsg=Submission+received+with+ID+20912255
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

ifstream fin("hotel.in");
ofstream fout("hotel.out");

int main()
{
    long long s, d;
    while (fin >> s >> d)
    {
        long long n = sqrt(2 * d + s * s) - 1;
        while (true)
        {
            long long temp = n * n - s * s + n + s;
            if (temp >= 2 * d)
            {
                fout << n << '\n';
                break;
            }
            ++n;
        }
    }

    return 0;
}