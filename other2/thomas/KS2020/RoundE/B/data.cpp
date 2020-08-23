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

        //***************************
        //在此处写入测试数据
        //***************************
        //int N=5;
        
        for (int N = 1; N <= 5 ; ++N)
        {
            for (int C = 1; C <= N ; ++C)
            {
                int t=100;
                set<pair<int,int>> s;
                for (int A = 1; A <= C ; ++A)
                {
                    for (int B = 1; B <= C ; ++B)
                    {
                        fout << N << " " << A << " " << B << " " << C << "\n";                        
                    }
                }
            }   
        }     

        fout << "\n";

        fout.close();
    }

    return 0;
}
