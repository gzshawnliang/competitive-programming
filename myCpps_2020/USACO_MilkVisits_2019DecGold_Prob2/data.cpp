#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{
    const int FileCount = 10; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open("z-" + to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************

        int maxNodes = 20;
        fout << maxNodes << " ";
        int m = 20;
        fout << m << "\n";

        for (int i = 1; i <= maxNodes; ++i)
        {
            fout << rdNum.GetRand(1, 5) << " ";
        }
        fout << "\n";

        vector<int> nodes = rdNum.GetUniqueRand(1, maxNodes);
        int a = rdNum.GetRand(1, maxNodes);
        int b = rdNum.GetRand(1, maxNodes);
        while (a == b)
        {
            a = rdNum.GetRand(1, maxNodes);
            b = rdNum.GetRand(1, maxNodes);
        }
        

        fout.close();
    }

    return 0;
}
