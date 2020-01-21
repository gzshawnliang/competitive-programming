#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{

    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("testmappair.in");

    //***************************
    //在此处写入测试数据
    //***************************
    // int N = rdNum.GetRand(1, 5000);
    // int Q = (int)1e5;

    int N = 1000;
    int Q = (int)1e5;
    int maxV=1e6;

    fout << N << " " << Q << "\n";

    for (int i = 1; i <= N; ++i)
    {
        int a=0;
        int b=0;
        while (abs(a-b)<3)
        {
            a=(int)rdNum.GetRand(0, maxV)-maxV;
            b=(int)rdNum.GetRand(0, maxV);
        }
        if(a>b)
            swap(a,b);
        fout << a << " " << b << "\n";
    }

    for (int i = 1; i <= Q; ++i)
    {
        int a=(int)rdNum.GetRand(0, maxV)-maxV;
        int b=(int)rdNum.GetRand(0, maxV);
        if(a>b)
            swap(a,b);
        fout << a << " " << b << "\n";
    }


    fout.close();
    

    return 0;
}
