#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

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

void testData(int itemCount)
{
    //int itemCount = (int)1e9;
    vector<int> v1;
    cout << "filling " << itemCount << " items in vector:";

    for (size_t i = 0; i <= itemCount - 1; ++i)
    {
        v1.push_back(i);
    }
}

int main()
{
    Timer t; //开始计时
    testData((int)1e7); //一千万
    cout << "seconds:" << t.elapsed() << endl; //打印秒
    // cout << "milliseconds:" << t.elapsed() << endl;                  //打印fun函数耗时多少秒（浮点）
    // cout << "microseconds:" << t.elapsed_milli() << endl;            //打印毫秒
    // cout << "microseconds:" << t.elapsed_micro() << endl;            //打印微秒
    // cout << "nanoseconds:" << t.elapsed_nano() << endl;              //打印纳秒
    // cout << "seconds:" << t.elapsed_seconds() << endl;               //打印秒
    // cout << "minutes:" << t.elapsed_minutes() << endl;               //打印分钟
    // cout << "hours:" << t.elapsed_hours() << endl;                   //打印小时
    
    t.reset();
    testData((int)1e8); //一亿
    cout << "seconds:" << t.elapsed() << endl; //打印秒

    t.reset();
    testData((int)1e9); //十亿
    cout << "seconds:" << t.elapsed() << endl; //打印秒

    return 0;
}