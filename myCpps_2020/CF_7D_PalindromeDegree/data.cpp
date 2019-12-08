#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

        fout.open("CF_7D_PalindromeDegree.in");

        //***************************
        //在此处写入测试数据
        //***************************
        //int N = rdNum.GetRand(1, 1e5);
        int N=5*1e6;

        for (int i = 0; i <= N - 1; ++i)
        {
            fout << "E";            
        }
        fout << "\n";

        

        fout.close();

    return 0;
}
