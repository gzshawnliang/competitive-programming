#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 1; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open("Fire_UVA11624Data.in");

        //***************************
        //在此处写入测试数据
        //***************************
        int N = rdNum.GetRand(1, 1);
        fout << N << "\n";

        int R = 1e3;
        int C = 1e3;
        fout << R << " " << C << "\n";
        vector<char> data = {'#', '.'};
        vector<vector<char>> a(R,vector<char>(R,'.'));

        int fireCount=4;
        for (int i = 0; i <= fireCount - 1; ++i)
        {
            a[rdNum.GetRand(0, R-1)][rdNum.GetRand(0, C-1)]='F';
        }

        a[rdNum.GetRand(0, R-1)][rdNum.GetRand(0, C-1)]='J';


        int sharpCount=1000;

        do 
        {
            int i=rdNum.GetRand(0, R-1);
            int j=rdNum.GetRand(0, C-1);
            if (a[i][j]=='.')
            {
                a[i][j]='#';
            }
            --sharpCount;
        }
        while (sharpCount>0);

        for (int i = 0; i <= R - 1; ++i)
        {
            for (int j = 0; j <= C - 1; ++j)
            {
                fout << a[i][j];
            }
            fout << '\n';
        }
        

        fout << "\n";
        fout.close();
    }

    return 0;
}
