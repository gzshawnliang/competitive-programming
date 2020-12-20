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
        //int N = rdNum.GetRand(1, 1e5);
        int N = 1000;
        int D = rdNum.GetRand(1, 1e9);
        int sNum = 800000;   //rdNum.GetRand(1, N*N);
        vector<pair<int,int>> S;
        for (int i = 1; i <= sNum; ++i)
        {
            S.push_back({rdNum.GetRand(2, N-1),rdNum.GetRand(2, N-1)});
        }

        fout << N << " " << D <<"\n";
        int icout=0;
        //first and last row and first and last column are '#'.
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if(i==1 || j==1 || i==N || j==N)
                {
                    fout << "#";    
                }
                else if(rdNum.GetRand(1, N*N)<i*j && icout<=sNum)
                {
                    fout << "S";
                    ++icout;
                }
                else 
                {
                    fout << ".";  

                    // bool hasS=false;
                    // for (auto k:S)
                    // {
                    //     if(i==k.first && j == k.second)
                    //     {
                    //         hasS=true;
                    //         break;
                    //     }
                    // }
                    // if(hasS==true)                    
                    //     fout << "S";
                    // else 
                    //     fout << ".";    
                }
            }
            fout << "\n";
        }
            

        fout << "\n";

        fout.close();
    }

    return 0;
}
