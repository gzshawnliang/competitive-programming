/***********************************************************
 * @名称:		3n + 1 problem (AC)
 * @作者:		Shawn 
 * @创建时间: 2017-11-14 20:38:17 
 * @修改人:   Shawn 
 * @修改时间: 2017-11-14 20:38:17 
 * @备注:		derp
 * @题目来源： https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
***********************************************************/
//#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    #ifdef ONLINE_JUDGE
        // online submission, running on online judge
    #else
        // local submission, running on local
        ifstream cin("numberLoop.in");
        ofstream cout("numberLoop.out");
    #endif

    vector<vector<int> > totalAns(0, vector<int>(3));
    while(true)
    {
        int minB, maxB, ans = 0, in1=-1,in2=-1 ;
        cin >> in1 >> in2;
        if (in1 == -1 || in2 == -1)
        {
            break;
        }
        minB = min(in1, in2);
        maxB = max(in1, in2);
        //cout << minB << " " << maxB << " ";

        for (int i = minB; i <= maxB; ++i)
        {
            int n = i, length = 1;
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
            ans = max(ans, length);
        }

        vector<int> temp;
        temp.push_back(in1);
        temp.push_back(in2);
        temp.push_back(ans);
        totalAns.push_back(temp);
        if (cin.eof())
        {
            break;
        }
    }

    int size = totalAns.size();
    for (int i = 0; i <= size - 1; ++i)
    {
        cout << totalAns[i][0] << " " << totalAns[i][1] << " " << totalAns[i][2] << endl;
    }

    //system("pause");

    return 0;
}
