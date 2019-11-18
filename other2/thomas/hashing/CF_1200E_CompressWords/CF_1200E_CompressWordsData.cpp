#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


        fout.open("CF_1200E_CompressWords.in");

        //***************************
        //在此处写入测试数据
        //***************************
        //int N = rdNum.GetRand(1, 1e5);
        int N=316;

        fout << N << "\n";
        string s;
        while (true)
        {
            int total=rdNum.GetRand(1, N);
            for (int i = 1; i <= total; ++i)
            {
                s.push_back('9');
            }
            --N;
            if(N>0)
                s.push_back(' ');
            if(N==0)                
                break;
        }
        fout << s << "\n";

        fout.close();
    

    return 0;
}
