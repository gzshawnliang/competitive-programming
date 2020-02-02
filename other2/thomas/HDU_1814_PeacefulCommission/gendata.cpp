#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{
    const int FileCount = 5000; //note:文件数量
    ofstream fout;           //note:文件流
    random rdNum;            //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open( "Z" + to_string(fileId) + ".in");
        //fout.open("SPO.IN");

        //***************************
        //在此处写入测试数据
        //***************************
        // int N = rdNum.GetRand(1, 8000);
        // int M = rdNum.GetRand(1, 20000);
        int N =8000;
        int M = 20000;

        set<pair<int, int>> K;
        for (int i = 0; i <= M - 1; ++i)
        {
            int a = rdNum.GetRand(1, N);
            int b = rdNum.GetRand(1, N);
            while (a == b)
            {
                a = rdNum.GetRand(1, 2*N);
                b = rdNum.GetRand(1, 2*N);
            }
            if(a>b)
                swap(a,b);
            K.insert(make_pair(a, b));            
        }

        fout << N << " " << K.size() << "\n";

        for (auto it = K.begin(); it != K.end(); ++it)
        {
            fout << it->first << " " << it->second << "\n";
        }

        fout.close();
    }

    return 0;
}
