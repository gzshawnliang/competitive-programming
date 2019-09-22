#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    ofstream fout;            //note:文件流
    ofstream fout2;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("storageKeepers_UVA10163.in");
    fout2.open("storageKeepers_UVA10163.in2");

    //***************************
    //在此处写入测试数据
    //***************************
    int caseNo=300;
    int caseId=0;
    while (caseNo--)
    {
        ++caseId;
        int N = rdNum.GetRand(1, 20);
        int M = rdNum.GetRand(1, 10);
        fout << N << " " << M << "\n";
        fout2 << caseId << ":" << N << " " << M << "\n";
        for (int i = 0; i <= M - 1; ++i)
        {
            int P = rdNum.GetRand(1, 100);
            fout << P << " ";
            fout2 << P << " ";
        }
        fout << "\n";
        fout2 << "\n";
    }
    fout << " 0 0\n";
    fout.close();
    fout2 << " 0 0\n";
    fout2.close();    
    return 0;
}
