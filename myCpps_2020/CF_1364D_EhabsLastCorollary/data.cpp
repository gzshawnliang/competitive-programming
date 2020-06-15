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
    
    ofstream fout;             //note:文件流
    random rdNum;              //note:随机数

    string currTime = getCurrTime();



    stringstream ss;
    ss << "CF_1364D_EhabsLastCorollary.in";

    fout.open(ss.str());

    //***************************
    //在此处写入测试数据
    //***************************
    //int n = rdNum.GetRand(1, 1e5);
    int n = 1e5;
    int m = 199997;
    fout << n << " " << m << " 3\n";
    // set<pair<int,int>> edgesSet;
    // while (edgesSet.size() <m)
    // {
    //     int u=rdNum.GetRand(1, n);
    //     int v=rdNum.GetRand(1, n);
    //     if(u !=v)
    //     {
    //         edgesSet.insert({u,v});
    //         fout << u << " " << v << "\n";
    //     }
    // }

    set<pair<int,int>> edgesSet;
    for (int i = 1; i <= n-1 ; ++i)
    {
        int u=i;
        int v=i+1;
        edgesSet.insert({u,v});
        fout << u << " " << v << "\n";
    }
    fout << n << " " << 1 << "\n";
    edgesSet.insert({n,1});
    //99998 99999 100000 
    //edgesSet.insert({99998,99999});
    //edgesSet.insert({99999,100000});
    edgesSet.insert({100000,99998});
    
     while (edgesSet.size() <m)
     {
        int u=rdNum.GetRand(1, n);
        int v=rdNum.GetRand(1, n);
        if(u !=v)
        {
            edgesSet.insert({u,v});
            fout << u << " " << v << "\n";
        }         
     }

    fout.close();
    

    return 0;
}
