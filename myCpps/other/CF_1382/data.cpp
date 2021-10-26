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

    //int len = to_string(FileCount).length();


        stringstream ss;
        ss << "test.in";

        fout.open(ss.str());
        int t=10;
        fout << t << "\n";
        while (t--)
        {
            int N = rdNum.GetRand(1, 10);
            fout << N << "\n";
            for (int i = 1; i <= N ; ++i)
            {
                fout <<rdNum.GetBoolRand() ;
            }
            fout << "\n";
            for (int i = 1; i <= N ; ++i)
            {
                fout <<rdNum.GetBoolRand() ;
            }
            fout << "\n";            
        }
        

        fout.close();
    

    return 0;
}
