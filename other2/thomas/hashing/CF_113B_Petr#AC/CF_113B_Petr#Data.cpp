#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{
    const int FileCount = 5000; //note:文件数量
    ofstream fout;             //note:文件流
    random rdNum;              //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open("D-"+to_string(fileId) + ".in");

        //fout.open("CF_113B_Petr#.in");

        //***************************
        //在此处写入测试数据
        //***************************
        int N;

        N = rdNum.GetRand(1, 20);
        char a = 'a';
        string s;
        while (N--)
        {
            if (rdNum.GetBoolRand())
                s.push_back(a + 1);
            else
                s.push_back(a);
        }
        fout << s << "\n";
        N = rdNum.GetRand(1, 20);
        s.clear();
        while (N--)
        {
            if (rdNum.GetBoolRand())
                s.push_back(a + 1);
            else
                s.push_back(a);
        }
        fout << s << "\n";

        N = rdNum.GetRand(1, 20);
        s.clear();
        while (N--)
        {
            if (rdNum.GetBoolRand())
                s.push_back(a + 1);
            else
                s.push_back(a);
        }
        fout << s << "\n";
        //N = rdNum.GetRand(1000, 2000);

        fout.close();
    }

    return 0;
}
