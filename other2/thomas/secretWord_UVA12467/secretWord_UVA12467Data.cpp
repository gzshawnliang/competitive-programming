#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 100; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    
    for (int fileId = 1; fileId <= FileCount ; ++fileId)
    {
        fout.open("T-"+to_string(fileId) + ".in");
        //***************************
        //在此处写入测试数据
        //***************************
        int T = rdNum.GetRand(150, 150);
        fout << T << "\n";
        while (T--)
        {
            int lenT = rdNum.GetRand(1, 1000000);
            string s="";
            for (int i = 0; i <= lenT - 1; ++i)
            {
                char a = 'a' + rdNum.GetRand(0,25);                        
                s.push_back(a);
            }
            fout << s << "\n";
        }
        fout.close();
    }

    return 0;
}
