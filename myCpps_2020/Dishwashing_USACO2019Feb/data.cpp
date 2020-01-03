#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 10; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open(to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************
        int N = rdNum.GetRand(10,20);
        fout << N << "\n";
        vector<int> a=rdNum.GetUniqueRand(1,N);
        for (int i = 1; i <= N-1 ; ++i)
        {
            fout <<a[i] << "\n";
        }

        fout.close();
    }

    return 0;
}
