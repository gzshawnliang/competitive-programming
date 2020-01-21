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
    int N = rdNum.GetRand(1, 5000);
    int Q = (int)1e5;
    fout << N << " " << Q << "\n";
    int minV=-(int)1e5;
    int maxV=(int)1e5;
    for (int i = 1; i <= N; ++i)
    {
        int a=(int)rdNum.GetRand(0, maxV)-2*(int)rdNum.GetRand(0, maxV);
        int b=2*(int)rdNum.GetRand(0, maxV)-(int)rdNum.GetRand(0, maxV);
        if(a>b)
            swap(a,b);
        fout << a << " " << b << "\n";
    }

    for (int i = 1; i <= Q; ++i)
    {
        int a=(int)rdNum.GetRand(0, maxV)-2*(int)rdNum.GetRand(0, maxV);
        int b=2*(int)rdNum.GetRand(0, maxV)-(int)rdNum.GetRand(0, maxV);
        if(a>b)
            swap(a,b);
        fout << a << " " << b << "\n";
    }


    fout.close();
    

    return 0;
}
