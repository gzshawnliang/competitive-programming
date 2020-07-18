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
    const int FileCount = 1000;  //note:文件数量
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
        //int t = rdNum.GetRand(1, 400);
        int t = 400;
        fout << t << "\n";
        while (t--)
        {
            int N = rdNum.GetRand(1, 50);
            fout << N << "\n";
            vector<int> v1(N),v2(2*N);
            for (int i = 0; i <= N-1; ++i) 
                v1[i]= i+1;
            
            // obtain a time-based seed:
            unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
            std::shuffle (v1.begin (), v1.end (), std::default_random_engine (seed));

            int beginId=rdNum.GetRand(1, N);
            
            int j=0;
            for (int i = 0; i <= 2*N - 1; i+=2)
            {
                v2[i]=v1[j];
                v2[i+1]=v1[j];
                ++j;
            }

            for(auto i:v2)
                fout << i << " ";
            
            fout << "\n";
        }
        fout << "\n";
        

        fout.close();
    }

    return 0;
}
