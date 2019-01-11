/***********************************************************
 * @名称:		3n + 1 problem
 * @作者:		Shawn 
 * @创建时间: 2017-11-14 20:38:17 
 * @修改人:   Thomas 
 * @修改时间: 2017-11-14 21:05:17 
 * @备注:		derp
 * @题目来源： https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
***********************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long numberLoop(long long a, long long b)
{
    long long ans = 0;
    long long minNumber = min(a, b);
    long long maxNumber = max(a, b);
    for (long long i = minNumber; i <= maxNumber; ++i)
    {
        long long n = i, length = 1;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = 3 * n + 1;
            }

            ++length;
        }
        if (length > ans)
        {
            ans = length;
        }
    }

    return ans;
}

int main()
{
    ifstream fin("numberLoopThomas.in");
    ofstream fout("numberLoopThomas.out");

    //int minB, maxB, ans = 0, out;
    //fin >> minB >> maxB;
    //fout << minB << " " << maxB << " ";

    while (true)
    {
        long long minB = 0, maxB = 0, ans = 0;
        fin >> minB >> maxB;

        ans = numberLoop(minB, maxB);
        fout << minB << " " << maxB << " " << ans << endl;

        if (fin.eof())
        {
            break;
        }
    }

    

    return 0;
}
