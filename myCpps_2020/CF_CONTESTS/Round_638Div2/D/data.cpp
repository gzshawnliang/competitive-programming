#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

        fout.open("CF_1348D_PhoenixandScience.in");

        //***************************
        //在此处写入测试数据
        //***************************
        //int N = rdNum.GetRand(1, 1e5);
        int N = 1e5 - 1;
        fout << N << "\n";
        for (int i = 2; i <= N ; ++i)
        {
            fout << i << "\n";
        }

        fout.close();

    return 0;
}
