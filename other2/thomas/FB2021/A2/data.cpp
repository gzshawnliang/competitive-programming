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
        int T = rdNum.GetRand(1, 40);
        

        fout << T << "\n";
        while (T--)
        {
            int sLen = rdNum.GetRand(1, 100);
            string s="";
            for (int i = 1; i <= sLen; ++i)
            {
                s.push_back((char)rdNum.GetRand(65, 90));
            }
            fout << s << "\n";
            int K = rdNum.GetRand(1, 300);
            fout << K << "\n";
            set<string> sSet;
            while (sSet.size()<K)
            {
                char s1=(char)rdNum.GetRand(65, 90);
                char s2=(char)rdNum.GetRand(65, 90);
                while (s1==s2)
                {
                    s2=(char)rdNum.GetRand(65, 90);
                }
                string r;
                r.push_back(s1);
                r.push_back(s2);
                sSet.insert(r);
            }

            for(auto s11:sSet)
            {
                fout << s11 << "\n";
            }
        }

        fout.close();
    }

    return 0;
}
