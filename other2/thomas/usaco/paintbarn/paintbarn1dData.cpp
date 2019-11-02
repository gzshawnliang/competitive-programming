#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{

    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("paintbarn1d.in");


    int n = (int)1e6;
    int k = 2;
    fout << n << " " << k << "\n";
    while (n--)
    {
        int x1=rdNum.GetRand(1, 1e5);
        int x2=rdNum.GetRand(1, 1e5);

        int x3=min(x1,x2);
        int x4=max(x1,x2);
        
        fout << x3 << " " << x4 << "\n";
    }
    
    fout.close();
    
    return 0;
}
