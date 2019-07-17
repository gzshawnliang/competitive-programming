#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

int main()
{
    const int FileCount = 1; //note:文件数量
    ofstream fout;           //note:文件流
    random rdNum;            //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open(to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************
        int T = 5;
        while (T--)
        {
            int N = rdNum.GetRand(500, 500);
            int M = rdNum.GetRand(500, 500);
            fout << N << " " << M << "\n";
            int start = rdNum.GetRand(100, 300);
            vector<vector<int>> data(500, vector<int>(500, 0));
            for (int i = 0; i <= N - 1; ++i)
            {
                int start2 = start + rdNum.GetRand(1, 300);
                for (int j = 0; j <= M - 1; ++j)
                {
                    start2 += rdNum.GetRand(1, 100);
                    if (i == 0)
                    {
                        data[i][j] = start2;
                    }
                    else if (i > 0)
                    {
                        while (start2 < data[i - 1][j])
                        {
                            start2 = data[i - 1][j] + rdNum.GetRand(1, 100);
                        }
                        data[i][j] = start2;
                    }

                    //fout << start << " ";
                }
                //fout << "\n";
            }

            for (int i = 0; i <= 500 - 1; ++i)
            {
                for (int j = 0; j <= 500 - 1; ++j)
                {
                    fout << data[i][j] << " ";
                }
                fout << "\n";
            }

            int Q = rdNum.GetRand(1, 1000);
            fout << Q << "\n";
            for (int i = 0; i <= Q - 1; ++i)
            {
                int L = rdNum.GetRand(1, 10000);
                int U = Q + rdNum.GetRand(1, 10000);
                fout << L << " " << U << "\n";
            }
        }

        fout << "0 0\n";
        fout.close();
    }

    return 0;
}
