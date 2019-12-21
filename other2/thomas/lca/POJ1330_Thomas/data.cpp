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
        fout.open("z-"+to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************
        int T=10;
        int maxNodes=10000;
        fout << T << "\n";
        while (T--)
        {
            vector<int> nodes = rdNum.GetUniqueRand(1, maxNodes);
            int a= rdNum.GetRand(1, maxNodes);
            int b= rdNum.GetRand(1, maxNodes);
            while (a==b)
            {
                a= rdNum.GetRand(1, maxNodes);
                b= rdNum.GetRand(1, maxNodes);
            }

            int n=nodes.size();
            fout << n << "\n";
            int root=nodes.front();
            vector<int> level;
            level.push_back(0);
            int leTotal=0;
            while (leTotal<=maxNodes)
            {
                int curr=rdNum.GetRand(2, 50);
                leTotal +=curr;
                level.push_back(curr);
            }
            
            int currLevel=1;
            while(nodes.size()>1)
            {
                
                fout << root << " " << *(nodes.begin()+1) << "\n";

                nodes.erase(nodes.begin());
                if(nodes.size()>0)
                {
                    --level[currLevel];
                    if(level[currLevel]==0)
                    {
                        root=nodes.front();
                        ++currLevel;

                    }
                }
            }
            fout << a << " " << b << "\n";            
        }

        fout.close();
    }

    return 0;
}
