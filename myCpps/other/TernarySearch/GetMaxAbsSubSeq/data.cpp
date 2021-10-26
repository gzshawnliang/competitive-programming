#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;


int main()
{
    ofstream fout;             //note:文件流
    random rdNum;              //note:随机数

    stringstream ss;
    ss << "GetMaxAbsSubSeq.in";

    fout.open(ss.str());

    //***************************
    //在此处写入测试数据
    //***************************
    int N = 5e4;
    fout << N << "\n";
    int maxValue = (int)5e1;
    for (int i = 1; i <= N ; ++i)
    {
        fout << (int)rdNum.GetRand(0, maxValue*2) - maxValue <<" ";
    }

    fout.close();

    return 0;
}
