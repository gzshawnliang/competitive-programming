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
        int caseCount = 10;
        
        fout.open(to_string(fileId) + ".in");

        for(int kk=1;kk<=caseCount;++kk)
        {
            //cout << kk << "\n";
            //***************************
            //在此处写入测试数据
            //***************************
            int N = rdNum.GetRand(5, 20);
            int M = rdNum.GetRand(1, 10-1);
            fout << N << " " << M+1 << "\n";
            for (int i = 1; i <= N; ++i)
            {
                fout << rdNum.GetRand(1, 30) << " ";
            }
            fout << "\n";

            for (int i = 1; i <= M; ++i)
            {
                vector<int> rd = rdNum.GetUniqueRand(1,N);
                int A=rd.front();
                int B=rd.back();

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

            vector<int> rd = rdNum.GetUniqueRand(1,N);
            int A2=rd.front();
            int B2=rd.back();
            if(A2>B2)
            {
                swap(A2,B2);
            }
            fout << "Q " << A2 << " " << B2 <<"\n";
            
        }
        //

        fout.close();
    }

    return 0;
}
