#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("blobsInTheBoard_UVA11391.in");

    //***************************
    //在此处写入测试数据
    //***************************
    int testCase = 500;
    int R = 4;
    int C = 4;
    fout << testCase << "\n";
    while (testCase--)
    {
        int N = rdNum.GetRand(10, 4*4-2);
        fout << R << " " << C << " " << N << "\n";
        set<string> co;
        int n=N;
        while (n--)
        {
            string key ="";
            int x;
            int y;
            do
            {
                x=rdNum.GetRand(1, R);
                y=rdNum.GetRand(1, C);
                key = to_string(x) + "_" + to_string(y);
            } while (co.count(key)>0);

            co.insert(key);
            fout << x << " " << y << "\n";
        }
    }
    
    

    fout.close();
    

    return 0;
}
