#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 10; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open(to_string(fileId) + ".in");


        int N = rdNum.GetRand(2, 20);      //顶点的数量

        fout << N << "\n";
        vector<set<int>> edges1(N+1);
        for (int i = 1; i <= N; ++i)
        {
            int m=rdNum.GetRand(1, N);
            for (int j = 0; j <= m - 1; ++j)
            {
                int node = rdNum.GetRand(1, N);
                if(node !=i)
                    edges1[i].insert(node);
            }
        }
        for (int i = 1; i <= N; ++i)
        {
            for (auto j:edges1[i])
            {
                fout << i  << " " << j << "\n";
            }
        }

        fout.close();
    }

    return 0;
}
