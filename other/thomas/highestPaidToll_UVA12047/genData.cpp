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
        int T = rdNum.GetRand(1, 50);
        fout << T << "\n";
        while (T--)
        {
            int N=rdNum.GetRand(2, 10);
            int M=rdNum.GetRand(1, 30);
            int s=rdNum.GetRand(1, N);
            int t=rdNum.GetRand(1, N);
            int p=rdNum.GetRand(1, 50);
            fout << N << " " << M << " " << s << " " << t << " " << p << "\n";
            while (M--)
            {
                int u=rdNum.GetRand(1, N);
                int v=rdNum.GetRand(1, N);
                while (u==v)
                {
                    v=rdNum.GetRand(1, N);
                }
                int c=rdNum.GetRand(0, 100000);
                fout << u << " " << v << " " << c << "\n";
            }
            
        }
        

        fout.close();
    }

    return 0;
}
