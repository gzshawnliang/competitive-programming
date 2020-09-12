#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

string getCurrTime()
{
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    time_t raw_time = std::chrono::system_clock::to_time_t(tp);

    // tm*使用完后不用delete，因为tm*是由localtime创建的，并且每个线程中会有一个
    struct tm * timeinfo = std::localtime(&raw_time);
    std::stringstream ss;
    //ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    ss << std::put_time(timeinfo, "%H%M%S");
    return ss.str();
}

int main()
{
    const int FileCount = 1;  //note:文件数量
    ofstream fout;             //note:文件流
    random rdNum;              //note:随机数

    string currTime = getCurrTime();

    int len = to_string(FileCount).length();

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        stringstream ss;
        ss << "test_" << currTime << "_" << setw(len) << setfill('0') << fileId << ".in";

        fout.open(ss.str());
        int T=1;
        fout << T << "\n";

        //***************************
        //在此处写入测试数据
        //***************************
        int N = rdNum.GetRand(2, 10);
        int M = rdNum.GetRand(1, 15);
        int S = rdNum.GetRand(2, 10);
        int R = rdNum.GetRand(1, 10);
        
        fout << N << " " << M << " " << S << " " << R  << "\n";
        set<pair<int,int>> map;
        while (true)
        {
            int u=rdNum.GetRand(1, N);
            int v=rdNum.GetRand(1, N);
            while(u==v)
            {
                u=rdNum.GetRand(1, N);
                v=rdNum.GetRand(1, N);
            }
            map.insert({u,v});
            if(map.size()==M)
                break;
        }

        for(auto s:map)
        {
            fout << s.first << " " << s.second << "\n";
        }

        for (int i = 1; i <= N; ++i)
        {
            int c=rdNum.GetRand(0, S-1);
            fout << c << " ";
            if(c>0)
            {
                set<int> cSet;
                while (true)
                {
                    cSet.insert(rdNum.GetRand(2, S));
                    if(cSet.size()==c)
                        break;
                }
                for(auto s:cSet)
                {
                    fout << s << " ";
                }
                fout <<  "\n";
            }
            else
            {
                fout <<  "\n";
            }
            
        }

        for (int i = 1; i <= R; ++i)
        {
            int k=rdNum.GetRand(1, 3);
            fout << k << " ";
            for (int i = 1; i <= k; ++i)
            {
                fout << rdNum.GetRand(2, S) << " ";
            }
            fout << rdNum.GetRand(1, S) << "\n";
        }        
        
        fout.close();
    }

    return 0;
}
