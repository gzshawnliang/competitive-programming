#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 100; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open(to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************
        int N = rdNum.GetRand(1, 10);
        
        
        unordered_set<int> x;
        int maxX=0;
        while (x.size()<N)
        {
            int xi=rdNum.GetRand(1, 10);
            x.insert(xi);
            maxX=max(maxX,xi);
        }
        int L = maxX + rdNum.GetRand(1, 10);
        fout << N << " " << L <<"\n";

        for(auto it:x)
        {
            int w=1;
            int d = rdNum.GetBoolRand() ? 1 : -1;
            fout << w << " " << it << " " << d <<"\n";
        }
        
        fout.close();
    }

    return 0;
}
