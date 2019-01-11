#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include <random>

#ifdef _WIN32
#include <windows.h>
#endif
#include <chrono>

using namespace std;

struct random
{
  private:
    default_random_engine generator;
    std::uniform_int_distribution<unsigned long long> distr;

    //note:注意：高精度种子(微秒级别，仅windows)
    unsigned long long GetPerformanceSeed()
    {
#ifdef _WIN32
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        return (unsigned long long)li.LowPart;
#else
        return std::chrono::system_clock::now().time_since_epoch().count();
#endif
    }

  public:
    random()
    {
        generator.seed(GetPerformanceSeed());
    }

    random(unsigned long long a, unsigned long long b)
    {
        generator.seed(GetPerformanceSeed());
        distr.param(std::uniform_int_distribution<unsigned long long>::param_type(a, b));
    }

    //note取得[a,b]的随机整数,a,b可以很大在long long范围
    unsigned long long GetRand(unsigned long long a, unsigned long long b)
    {
        distr.param(std::uniform_int_distribution<unsigned long long>::param_type(a, b));
        return distr(generator);
    }
    unsigned long long GetRand()
    {
        return distr(generator);
    }

    //产生[a,b]之间不重复的随机数,缺点：如数据量比较大占内存
    vector<int> GetUniqueRand(int a, int b)
    {
        vector<int> vi;
        /*现在向量包含了 b-a 个 a-b 之间的整数并且按升序排列*/
        for (int i = a; i <= b; ++i)
        {
            vi.push_back(i);
        }
        generator.seed(GetPerformanceSeed());
        std::shuffle(vi.begin(), vi.end(), std::default_random_engine(generator));

        return vi;
    }
};

int main()
{
    const int FileCount = 100; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open(to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************

        vector<int> temp = rdNum.GetUniqueRand(1, 100);

        for (int c = 0; c <= 20 - 1; ++c)
        {
            fout << temp[c] << '\n';
        }

        fout.close();
    }

    return 0;
}
