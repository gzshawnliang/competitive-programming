#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 10; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("fcolor.in");

    //***************************
    //在此处写入测试数据
    //***************************
    int N =2e5;
    int M =2e5;
    fout << N << " " << M << "\n";

    for (int i = 1; i <= M ; ++i)
    {
        fout << rdNum.GetRand(1, N) << " " <<  rdNum.GetRand(1, N) << "\n";
    }

    fout.close();
    

    return 0;
}


