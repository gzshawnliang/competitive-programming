#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("KMP.in");
    int testCase=100;
    //***************************
    //在此处写入测试数据
    //***************************
    while (testCase--)
    {
        string T;
        for (int i = 0; i <= 15 - 1; ++i)
        {
            T.push_back('a'+rdNum.GetRand(0, 4));
        }
        fout << T << "\n";

        string P;
        for (int i = 0; i <= 3 - 1; ++i)
        {
            P.push_back('a'+rdNum.GetRand(0, 2));
        }
        fout << P << "\n";
    }
    fout.close();

    return 0;
}
