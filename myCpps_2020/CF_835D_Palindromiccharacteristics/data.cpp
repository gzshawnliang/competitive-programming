#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 8000; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open("d-"+to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************
        //int N = rdNum.GetRand(1, 1e5);
        int N = 50;
        string s;
        
        for (int i = 0; i <= N - 1; ++i)
        {
            char c='a'+rdNum.GetRand(0, 25);
            s.push_back(c);
        }
        fout << s << "\n";        
 
        fout.close();
    }

    return 0;
}
