#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"
#include "Windows.h"

using namespace std;

int main()
{
    const int FileCount = 10; //note:文件数量
    ofstream fout;
    random rdNum;
    
    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        //note:每个文件案例的个数
        int caseCount = 1;
        
        fout.open(to_string(fileId) + ".in");

        for(int kk=1;kk<=caseCount;++kk)
        {
            //***************************
            //在此处写入测试数据
            //***************************
            int N = rdNum.GetRand(50000, 50000);
            
            fout << N << "\n";
            for (int i = 1; i <= N; ++i)
            {
                
                fout << (long long)rdNum.GetRand(0, 15007)-(long long)rdNum.GetRand(0, 15007)*2 << " ";
            }
            fout << "\n";
            int M = rdNum.GetRand(8000, 20000);
            fout << M << "\n";
            for (int i = 1; i <= M; ++i)
            {
                vector<int> rd = rdNum.GetUniqueRand(1,N);
                int A=rd.front();
                int B=rd.back();

                if(A>B)
                {
                    swap(A,B);
                }
                
                fout << A << " " << B <<"\n";
            }
        }

        fout.close();
    }

    return 0;
}
