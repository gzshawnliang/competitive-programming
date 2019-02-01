#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

//ifstream fin("checkTime.in");
//ofstream fout("checkTime.out");

//note:计时器，可拥有测量模块的运行时间
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

double testTime(int itemCount)
{
    Timer t;

    vector<int> v1;

    for (size_t i = 0; i <= itemCount - 1; ++i)
    {
        v1.push_back(i);
    }

    return t.elapsed();
}

int testLoop(double _time)
{
    int l = 1, r = 2*1e8;
    while (r - l > 20000)
    {
        int m = (l + r) / 2;

        if (testTime(m) < _time)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    return (l + r) / 2;
}

int main()
{
     //开始计时

    cout << testTime(9000000) << endl; //打印秒

    return 0;
}
