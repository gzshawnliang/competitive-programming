#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{
    const int FileCount = 10; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open(to_string(fileId) + ".in");
        int caseCout = 10;
        while (caseCout--)
        {

            //***************************
            //在此处写入测试数据
            //***************************
            int N = 1000;      //rdNum.GetRand(1, 1e3);
            int M =rdNum.GetRand(1, N-1)*rdNum.GetRand(1, N-1);
            fout << N;
            set<pair<int, int>> set1;
            for (int i = 0; i <= M - 1; ++i)
            {
                int a, b;
                do
                {
                    a = rdNum.GetRand(0, N - 1);
                    b = rdNum.GetRand(0, N - 1);
                } while (a == b);

                if (a > b)
                    swap(a, b);

                set1.insert(make_pair(a, b));
            }
            fout << " " << set1.size() << "\n";

            for (auto it : set1)
            {
                fout << it.first << " " << it.second << " " << rdNum.GetBoolRand() << " " << rdNum.GetBoolRand() << "\n";
            }
        }

        fout.close();
    }

    return 0;
}
