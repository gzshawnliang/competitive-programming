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
    ss << "CF_1385G_ColumnsSwaps.in";
    fout.open(ss.str());
    int t=1;
    fout << t << "\n";

    auto genNO=[&]()
    {
        int N = rdNum.GetRand(1, 10);
        fout << N << "\n";
        for (int i = 1; i <= N; ++i)
        {
            fout << rdNum.GetRand(1, N) << " ";
        }
        fout << "\n";

        for (int i = 1; i <= N; ++i)
        {
            fout << rdNum.GetRand(1, N) << " ";
        }
        fout << "\n";
    };

    auto genYes=[&]()
    {
        //int N = rdNum.GetRand(5, 10);
        int N = 2e5;
        fout << N << "\n";
        vector<int> a =rdNum.GetUniqueRand(1,N);
        vector<int> b =rdNum.GetUniqueRand(1,N);

        int swapCount=rdNum.GetRand(1, N);
        while (swapCount--)
        {
           int i=rdNum.GetRand(0, N-1);
           swap(a[i],b[i]);
        }

        for (int i = 1; i <= N; ++i)
        {
            fout << a[i-1] << " ";
        }  
        fout << "\n";      
        
        for (int i = 1; i <= N; ++i)
        {
            fout << b[i-1] << " ";
        }  
        fout << "\n";        
    };    

    while (t--)
    {
        // if(rdNum.GetBoolRand())
        //     genNO();
        // else        
            genYes();     
    }
    fout.close();
    

    return 0;
}
