#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 1; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数
    int Tcase =8000;
    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open("Boggle.in");

        //***************************
        //在此处写入测试数据
        //***************************
        while (Tcase--)
        {
            for (int i = 1; i <= 4 ; ++i)
            {
                for (int j = 1; j <= 4 ; ++j)
                {
                    char a = 'A' + rdNum.GetRand(0, 25);
                    fout << a << " ";
                }
                fout << "   ";
                for (int j = 1; j <= 4 ; ++j)
                {
                    char a = 'A' + rdNum.GetRand(0, 25);
                    fout << a << " ";
                }                
                fout << "\n";
            }
            fout << "\n";
        }
        
        fout << "#";
        fout.close();
    }

    return 0;
}
