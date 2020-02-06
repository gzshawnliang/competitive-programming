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
        fout.open("CF_1215F_RadioStations.in");

        //***************************
        //在此处写入测试数据
        //***************************
        //int N = rdNum.GetRand(1, 1e5);
        int n=1e4;
        int p=n, M=n ,m=n;
        fout << n << " " << p << " " << " " << M << " " << m << "\n";
        for (int i = 1; i <= n ; ++i)
        {
            int x, y;
            x=rdNum.GetRand(1, p);
            y=rdNum.GetRand(1, p);
            while (x==y)
            {
                x=rdNum.GetRand(1, p);
                y=rdNum.GetRand(1, p);
            }
            if(x>y)
                swap(x,y);
            
            fout<< x << " " << y << "\n";
        }

        for (int i = 1; i <= n; ++i)
        {
            int l, r;
            l = rdNum.GetRand(1, M);
            r = rdNum.GetRand(1, M);
            if (l > r)
                swap(l, r);

            fout << l << " " << r << "\n";
        }

        for (int i = 1; i <= n; ++i)
        {
            int u, v;
            u = rdNum.GetRand(1, p);
            v = rdNum.GetRand(1, p);
            if (u > v)
                swap(u, v);

            fout << u << " " << v << "\n";
        }        

        fout.close();
    }

    return 0;
}
