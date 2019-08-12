#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{
    const int FileCount = 1; //note:文件数量
    ofstream fout;           //note:文件流
    random rdNum;            //note:随机数

    fout.open("stringDistanceAndTransformProcess_UVA526.in");

    //***************************
    //在此处写入测试数据
    //***************************
    int N = 10000;
    for (int i = 0; i <= N - 1; ++i)
    {
        string strA = "";
        int n1 = rdNum.GetRand(1, 5);
        for (int i = 0; i <= n1 - 1; ++i)
        {
            char ascii = rdNum.GetRand(32, 95);
            strA.push_back(ascii);
        }

        string strB = "";
        int n2 = rdNum.GetRand(1, 5);
        for (int i = 0; i <= n2 - 1; ++i)
        {
            char ascii = rdNum.GetRand(32, 95);
            strB.push_back(ascii);
        }
        if (strA.length() > 0 || strB.length() > 0)
        {
            fout << strA << "\n";
            fout << strB << "\n";
        }
    }

    fout.close();

    return 0;
}
