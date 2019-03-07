#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 50; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open(to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************
        int N = rdNum.GetRand(1, 200000);
        int M = rdNum.GetRand(1, 5000-1);
        fout << N << " " << M+1 << "\n";
        for (int i = 1; i <= N; ++i)
        {
            fout << rdNum.GetRand(1, 30) << " ";
        }
        fout << "\n";

        for (int i = 1; i <= M; ++i)
        {
            int A=rdNum.GetRand(1, N);
            int B=rdNum.GetRand(1, N);
            while(A==B){
                B=rdNum.GetRand(1, N);
            }

            if(A>B)
            {
                swap(A,B);
            }
            
            //fout << "Q " << A << " " << B <<"\n";
            
            if(rdNum.GetBoolRand())
            {
                fout << "Q " << A << " " << B <<"\n";
            }
            else
            {
                fout << "U " << A << " " << B <<"\n";
            }
        }


        int A=rdNum.GetRand(1, N);
        int B=rdNum.GetRand(1, N);
        while(A==B){
            B=rdNum.GetRand(1, N);
        }
        if(A>B)
        {
            swap(A,B);
        }
        fout << "Q " << A << " " << B <<"\n";                                    
        


        fout.close();
    }

    return 0;
}
