#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{
    ofstream fout; //note:文件流
    random rdNum;  //note:随机数

    fout.open("howBigIsIt_UVA10012.in");

    //***************************
    //在此处写入测试数据
    //***************************
    int testCase = 10000;
    fout << testCase << "\n";
    while (testCase--)
    {
        int N = 3;
        fout << N << " ";
        fout << std::fixed << setprecision(1);
        while (N--)
        {
            fout << (double)rdNum.GetRand(1, 10) << " ";
        }
        fout << setprecision(0);
        fout << "\n";
    }

    fout.close();

    return 0;
}
