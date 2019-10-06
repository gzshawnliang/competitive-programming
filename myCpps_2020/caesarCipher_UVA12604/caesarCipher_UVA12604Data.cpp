#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{

    ofstream fout; //note:文件流
    random rdNum;  //note:随机数

    fout.open("caesarCipher_UVA12604.in");

    //***************************
    //在此处写入测试数据
    //***************************
    int N = 10;
    fout << N << "\n";
    string Atable="abcdefghijklmnopqrstuvwxyz";
    while (N--)
    {
        string A= Atable.substr(1,rdNum.GetRand(2,5));
        fout << A << "\n";

        string W = Atable.substr(1,rdNum.GetRand(2,10));
        fout << W << "\n";

        string S= Atable.substr(1,rdNum.GetRand(2,26));
        fout << S << "\n";        
    }
    

    fout.close();

    return 0;
}
