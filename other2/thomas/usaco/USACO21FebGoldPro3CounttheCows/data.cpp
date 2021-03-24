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

    stringstream ss;
    ss << "counttheCows.in";

    fout.open(ss.str());

    //***************************
    //在此处写入测试数据
    //***************************
    int Q = 100;
    
    fout << Q << "\n";
    while(Q--)
    {
        while (true)
        {
            int d = rdNum.GetRand(0, 8);
            int x = rdNum.GetRand(0, 8);
            int y = rdNum.GetRand(0, 8);                
            //int y=0;
            if(x>y)
                swap(x,y);
            if(y+d<=8)
            {
                fout << d << " "<<x << " " << y << "\n";
                break;
            }
        }
        
    }

    fout.close();
    

    return 0;
}
