#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{

    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    fout.open("UVa11806_Cheerleaders.in");
    int T = 1000;
    fout << T<< "\n";
    while (T--)
    {
        //***************************
        //在此处写入测试数据
        //***************************
        int m = rdNum.GetRand(2, 20);
        int n = rdNum.GetRand(2, 20);
        int k = rdNum.GetRand(0, 500);
        fout << m << " " << n << " " << k << "\n";
    }

    fout.close();

    return 0;
}
