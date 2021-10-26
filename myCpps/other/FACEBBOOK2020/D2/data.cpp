#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ
#include "treegenerator.h"

using namespace std;
using namespace tree_generator_by_ouuan;


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
    ofstream fout2;             //note:文件流
    random rdNum;              //note:随机数

    string currTime = getCurrTime();

    int len = to_string(FileCount).length();

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        stringstream ss;
        
        ss << "test_" << currTime << "_" << setw(len) << setfill('0') << fileId << ".in";
        string fileName = ss.str();
        fout.open(fileName);
        fout2.open(fileName + "tr");
        

        //***************************
        //在此处写入测试数据
        //***************************
        //int T = rdNum.GetRand(1, 85);
        int T =  rdNum.GetRand(1, 10);
        fout << T << "\n";
        int icout=0;
        while (T--)
        {
            int N = rdNum.GetRand(2, 10);
            int M = rdNum.GetRand(1, N);

            int A = rdNum.GetRand(1, N);
            int B = rdNum.GetRand(1, N);
            while (A==B)
            {
                A = rdNum.GetRand(1, N);
                B = rdNum.GetRand(1, N);
            }

            
            
            fout << N << " " << M << " " <<  A << " " << B << " " << "\n";
            fout << 0 << " " << rdNum.GetRand(0, 100) << "\n";
            set<pair<int,int>> set1;
            for (int i = 2; i <= N; ++i)
            {
                int p=rdNum.GetRand(1, N);
                
                while (p==i || set1.count({i,p})==1 || set1.count({p,i})==1)
                {
                    p=rdNum.GetRand(1, N);
                }
                set1.insert({p,i});

                
                fout << p << " " << rdNum.GetRand(0, 100) << "\n";
                //fout2 << p << " " << i << "\n";
            }
            icout +=N;
            //fout2 << "\n";
            Tree t(10);
            t.random(10,1);
            fout2 << t << '\n';
        }
        cerr << fileName << ":" << icout << "\n" ;
        fout.close();
        fout2.close();
    }

    return 0;
}
