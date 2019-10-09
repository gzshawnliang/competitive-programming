#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{

    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("Round#166(Div.2)D.GoodSubstrings.in");

    //***************************
    //在此处写入测试数据
    //***************************
    string s="";
    for (int i = 0; i <= 1500 - 1; ++i)
    {
        int c= rdNum.GetRand(0, 25);
        s.push_back('a'+c);
    }
    fout << s << "\n";

    fout << "10001111101011111101101001" << '\n';
    fout << 25 << "\n";


    fout.close();
    

    return 0;
}
