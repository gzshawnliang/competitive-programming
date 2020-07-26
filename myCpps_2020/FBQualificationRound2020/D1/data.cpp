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
    const int FileCount = 10;  //note:文件数量
    ofstream fout;             //note:文件流
    random rdNum;              //note:随机数

    string currTime = getCurrTime();

    int len = to_string(FileCount).length();

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        stringstream ss;
        
        ss << "test_" << currTime << "_" << setw(len) << setfill('0') << fileId << ".in";
        string fileName = ss.str();
        fout.open(fileName);

        //***************************
        //在此处写入测试数据
        //***************************
        int T = rdNum.GetRand(1, 85);
        //int T =  4;
        fout << T << "\n";
        int icout=0;
        while (T--)
        {
            int N = rdNum.GetRand(1e3, 1e4);
            int M = rdNum.GetRand(2, N);
            //int N = 1e6;
            
            
            fout << N << " " << M << "\n";
            
            for (int i = 1; i <= N; ++i)
            {
                fout << rdNum.GetRand(1, 1e9) << "\n";
            }
            icout +=N;
            fout << "\n";
        }
        cerr << fileName << ":" << icout << "\n" ;
        fout.close();
    }

    return 0;
}
