#include <iostream>
#include <random>
#include <windows.h>
#include <chrono>
using namespace std;

//几乎不可预测的随机数Unpredictable random numbers
struct StrongRandom
{
    private:
    std::seed_seq seed_seq{GetPerformanceSeed(),GetPerformanceSeed(),GetPerformanceSeed()};
    std::mt19937 engine {seed_seq};
    std::uniform_int_distribution<unsigned long long> distr; 

    //note:注意：高精度种子(微秒级别，仅windows)
    unsigned long long GetPerformanceSeed()
    {
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        return (unsigned long long)li.LowPart;
    } 

    public:
    StrongRandom(unsigned long long a,unsigned long long b)
    {
        //uniform_int_distribution<unsigned long long> u2(a,b);
        distr.param(std::uniform_int_distribution<unsigned long long>::param_type(a, b));
    }

    unsigned long long GetRand()
    {
        return distr(engine);
    }

};

int main()
{
    cout << "-------------\n";
    StrongRandom random2(1,100);
    int TestCase=11;
    while(TestCase--)
    {
        cout<< random2.GetRand() <<"\n";
    }    

    return 0;
}
