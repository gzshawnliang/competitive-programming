#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


        fout.open("CF_514C_WattoandMechanism.in");

        //***************************
        //在此处写入测试数据
        //***************************
        fout <<"1 1\n";
        int N = 1e5;
        
        string abc="abc";
        string s;
        for (int i = 0; i <= N - 1; ++i)
        {
            s.push_back(abc[rdNum.GetRand(0, 2)]);
        }
        fout <<s<<"\n";

        int pos = rdNum.GetRand(0, 10);
        while (s[pos]==abc[rdNum.GetRand(0, 2)])
        {
            pos = rdNum.GetRand(0, N);
        }
        
        s[pos]=abc[rdNum.GetRand(0, 2)];

        fout <<s<<"\n";

        fout.close();
    

    return 0;
}
