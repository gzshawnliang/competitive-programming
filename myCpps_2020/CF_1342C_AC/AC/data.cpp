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
    const int FileCount = 50;  //note:文件数量
    ofstream fout;             //note:文件流
    ofstream fout2;             //note:文件流
    random rdNum;              //note:随机数

    string currTime = getCurrTime();
    int len = to_string(FileCount).length();
    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        stringstream ss;
        ss << "test_" << setw(len) << setfill('0') << fileId << ".in";
        fout.open(ss.str());

        int t=1;
        fout << t << "\n";
        int c=0;
        while (t--)
        {
            ++c;
            int a = rdNum.GetRand(1, 20);
            int b = rdNum.GetRand(1, 20);
            int q = rdNum.GetRand(1, 50);
            fout << a << " " << b << " " << q << '\n';
            while (q--)
            {
                int l=rdNum.GetRand(1, 50);
                int r=l+ rdNum.GetRand(0, 10);
                fout << l << " " << r << '\n';
            }
        }

        fout.close();

    }

    return 0;
}


