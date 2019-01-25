#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 1; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open("RMQWithShifts_UVA12299.in");

        //***************************
        //在此处写入测试数据
        //***************************
        int N = 10;
        //int q = rdNum.GetRand(2, 300);
        int q = 7;
        fout << N << " " <<q << "\n";
        for (int i = 0; i <= N - 1; ++i)
        {
            fout << rdNum.GetRand(1, 1e1) <<  " ";
        }
        fout << "\n" ;
        int q2=q-1;
        while(q2--)
        {
            // if(rdNum.GetRand(1, 10) %2==0)
            // {
                int shift1=rdNum.GetRand(1, N);
                int shift2=rdNum.GetRand(1, N);
                while(shift1>=shift2)
                {
                    shift1=rdNum.GetRand(1, N);
                    shift2=rdNum.GetRand(1, N);
                }
                
                fout << "shift(" << shift1 << "," << shift2;
                while(shift2<N)
                {
                    shift2+=rdNum.GetRand(1, N);
                    if(shift2>=N)
                    {
                        break;
                    }
                    fout <<  ","<< shift2;
                }
                fout << ")\n";
            //}
            //else 
            //{
                // int query_i=rdNum.GetRand(1, N);
                // int query_j=rdNum.GetRand(1, N);
                // while(query_i>=query_j)
                // {
                //     query_i=rdNum.GetRand(1, N);
                //     query_j=rdNum.GetRand(1, N);
                // }
                
                // fout << "query(" << query_i << "," << query_j << ")\n";            
            //}
        }
        
        int query_i=rdNum.GetRand(1, N);
        int query_j=rdNum.GetRand(1, N);
        while(query_i>=query_j)
        {
            query_i=rdNum.GetRand(1, N);
            query_j=rdNum.GetRand(1, N);
        }
        
        fout << "query(" << query_i << "," << query_j << ")\n";            
        fout.close();
    }

    return 0;
}
