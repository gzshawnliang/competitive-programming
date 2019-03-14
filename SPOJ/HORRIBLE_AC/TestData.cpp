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
        fout << caseCount << "\n";
        for(int currCase=1;currCase<=caseCount;++currCase)
        {
            //***************************
            //在此处写入测试数据
            //***************************
            int N = rdNum.GetRand(1, 1e4*3);
            int C = rdNum.GetRand(1, 1e4*3);

            // int N = rdNum.GetRand(1, 100);
            // int C = rdNum.GetRand(1, 100);

            fout << N << " " << C << "\n";
            for (int i = 1; i <= C; ++i)
            {
                int A=rdNum.GetRand(1,N);
                int B=rdNum.GetRand(1,N);

                while(A==B){
                    B=rdNum.GetRand(1,N);
                }

                if(A>B)
                {
                    swap(A,B);
                }
                if(i==C)
                {
                    fout << "1 " << A << " " << B <<"\n";
                }
                else
                {
                    if(rdNum.GetBoolRand())
                    {
                        fout << "0 " << A << " " << B << " "<< rdNum.GetRand(1,1e7) << "\n";
                    }
                    else 
                    {
                        fout << "1 " << A << " " << B <<"\n";
                    }
                }

            }
        }

        fout.close();
    }

    return 0;
}
