#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
   
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("Email.in");

    //***************************
    //在此处写入测试数据
    //***************************
    //int N = rdNum.GetRand(1, 10);
    int N = 10;
    fout << N << "\n";
    for (int i = 0; i <= N - 1; ++i)
    {
        int n=rdNum.GetRand(2, 20000);   
        int m=rdNum.GetRand(0, 50000);   
        int S=rdNum.GetRand(0, n-1);
        int T=rdNum.GetRand(0, n-1);
        while (T==S)
        {
            S=rdNum.GetRand(0, n-1);
            T=rdNum.GetRand(0, n-1);
        }
        fout << n << " " << m << " " << S << " " << T << '\n';
        for (int j = 0; j <= m - 1; ++j)
        {
            fout << rdNum.GetRand(0, n-1) << " " << rdNum.GetRand(0, n-1) << " " << rdNum.GetRand(0, 10000) <<'\n';
        }
        
    }

    fout.close();
    

    return 0;
}
