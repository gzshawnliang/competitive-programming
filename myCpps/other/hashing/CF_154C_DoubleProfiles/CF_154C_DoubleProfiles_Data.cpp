#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ
using namespace std;
using namespace std::chrono;

struct Timer
{

  private:
    time_point<high_resolution_clock> m_begin;
        
  public:
    Timer() : m_begin(high_resolution_clock::now()) {}

    
    void reset() 
    { 
        m_begin = high_resolution_clock::now(); 
    }

    //默认输出秒(浮点数)
    double elapsed() const
    {
        return elapsed_seconds_double();
    }

    //毫秒
    long long elapsed_milli() const
    {
        return duration_cast<chrono::milliseconds>(high_resolution_clock::now() - m_begin).count();
    }

    //微秒
    long long elapsed_micro() const
    {
        return duration_cast<chrono::microseconds>(high_resolution_clock::now() - m_begin).count();
    }
    //纳秒
    long long elapsed_nano() const
    {
        return duration_cast<chrono::nanoseconds>(high_resolution_clock::now() - m_begin).count();
    }
    //秒
    long long elapsed_seconds() const
    {
        return duration_cast<chrono::seconds>(high_resolution_clock::now() - m_begin).count();
    }

    //默认输出秒(浮点数)
    double elapsed_seconds_double() const
    {
        return (double)elapsed_milli() / 1000.0;
    }

    //分
    long long elapsed_minutes() const
    {
        return duration_cast<chrono::minutes>(high_resolution_clock::now() - m_begin).count();
    }
    //时
    long long elapsed_hours() const
    {
        return duration_cast<chrono::hours>(high_resolution_clock::now() - m_begin).count();
    }
};

int main()
{
    ofstream fout; //note:文件流
    random rdNum;  //note:随机数
    Timer t; //开始计时

    fout.open("CF_154C_DoubleProfiles.in");

    //***************************
    //在此处写入测试数据
    //***************************
    //1000000
    int n = 1e6;
    int m = 1e6;
    fout << n << " " << m << "\n";
    set<pair<int, int>> data;

    while (data.size() < m)
    {
        int u = rdNum.GetRand(1, n);
        int v = 0;
        do
        {
            v = rdNum.GetRand(1, n);
        } while (v == u);
        data.insert(make_pair(min(u,v), max(u,v)));
        //fout << u << " " << v << "\n";
        if((data.size() % 10000)==0)
            cout << data.size() << " of " << m << " --  " << t.elapsed_minutes() << ":" << setfill('0') << setw(2) << t.elapsed_seconds() % 60 << endl;
    }

    for (auto it = data.begin(); it != data.end(); ++it)
    {
        fout << it->first << " " << it->second << "\n";
    }

    fout.close();

    return 0;
}
