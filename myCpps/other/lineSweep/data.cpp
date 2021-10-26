#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{
    const int FileCount = 1; //note:文件数量
    ofstream fout;           //note:文件流
    random rdNum;            //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open("lineSweep.in");

        //***************************
        //在此处写入测试数据
        //***************************
        int testCase = 1;

        while (testCase--)
        {
            int N = rdNum.GetRand(1000, 1000);
            fout << N << "\n";
            for (int i = 0; i <= N - 1; ++i)
            {
                double x1, y1, x2, y2;
                x1 = rdNum.GetRand(0, 100000);
                x2 = rdNum.GetRand(1, 100000);
                while (x1>=x2)
                {
                    x2 = rdNum.GetRand(1, 100000);
                }
                
                y1 = rdNum.GetRand(0, 100000);
                y2 = rdNum.GetRand(1, 100000);
                while (y1>=y2)
                {
                    y2 = rdNum.GetRand(1, 100000);
                }                

                fout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
            }
        }
        fout << '0' << '\n';

        fout.close();
    }

    return 0;
}
