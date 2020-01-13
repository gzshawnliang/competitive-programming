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
        int N = rdNum.GetRand(1, 1e2);
        int M = rdNum.GetRand(1, 1e2);
        fout << N << " " << M << "\n";

        for (int i = 1; i <= M ; ++i)
        {
            int mun = rdNum.GetRand(1, N);
            unordered_set<int> ord;
            int k=0;
            while(true)
            {
                ++k;
                ord.insert(rdNum.GetRand(1, N));
                if(k==mun)
                    break;
            }
            fout << ord.size() << " ";
            for(auto it:ord)
                fout << it << " ";
            
            fout << "\n";
        }

        fout.close();
    }

    return 0;
}
