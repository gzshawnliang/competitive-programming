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



    for (int fileId = 1; fileId <= 1; ++fileId)
    {
        stringstream ss;
        ss << "CF_1490B_BalancedRemainders.in" ;

        fout.open(ss.str());

        //***************************
        //在此处写入测试数据
        //***************************
        int T = rdNum.GetRand(1, 3);
        fout<<T<<"\n";
        for (int t = 1; t <= T; ++t)
        {
            int N = rdNum.GetRand(1, 3);
            fout << N*3 << "\n";
            for (int i = 1; i <= N*3; ++i)
            {
                fout << rdNum.GetRand(0, 2) << " " << " ";
            }            
            fout <<"\n";
        }

        fout.close();
    }

    return 0;
}
