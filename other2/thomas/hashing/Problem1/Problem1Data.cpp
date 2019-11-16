#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{

    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("Problem1.in");

    //***************************
    //在此处写入测试数据
    //***************************
    int N = rdNum.GetRand(1, 1e5);
    string s;
    for (int i = 0; i <= N - 1; ++i)
    {
        s.push_back('a'+ rdNum.GetRand(0,1));
    }
    fout << N <<"\n";
    fout << s <<"\n";

    int Q = rdNum.GetRand(1, 1e5);
    fout << Q <<"\n";
    while (Q--)
    {
        
        int a=rdNum.GetRand(1, N);
        int b=rdNum.GetRand(1, N);
        fout << min(a,b) << " " << max(a,b) <<"\n";
    }
    

    fout.close();
    

    return 0;
}

