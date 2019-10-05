#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

struct random
{
    private:
        default_random_engine generator;
        std::uniform_int_distribution<unsigned long long> distr; 
        std::bernoulli_distribution distrBool;

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
    
    
    random(unsigned long long  a,unsigned long long  b)
    {
        generator.seed(GetPerformanceSeed());
        distr.param(std::uniform_int_distribution<unsigned long long>::param_type(a, b));
    }

    
    /**取得[a,b]的随机整数,a,b可以很大在long long范围
     * 
     * @param  {unsigned} long : 【输入】较小的整数
     * @param  {unsigned} long : 【输入】较大的整数
     * @return {unsigned}      : 【返回】随机数
     */
    unsigned long long GetRand(unsigned long long  a,unsigned long long  b)
    {
        distr.param(std::uniform_int_distribution<unsigned long long>::param_type(a, b));   
        return distr(generator);
    }

    
    /**取得[a,b]的随机整数,a,b在构造函数设定
     * 
     * @return {unsigned}  : 【返回】随机数
     */
    unsigned long long GetRand()
    {
        return distr(generator);
    }

    /**获取随机布尔数
     * 
     * @return {bool}  : 随机布尔数
     */
    bool GetBoolRand()
    {
        return distrBool(generator);
    }    

    //note：如数据量比较大占内存
    /**产生[a,b]之间不重复的随机数
     * 
     * @param  {int} a        : 【输入】较小的整数
     * @param  {int} b        : 【输入】较大的整数
     * @return {vector<int>}  : 【返回】不重复的随机数的数组
     */
    vector<int> GetUniqueRand(int a,int b)
    {
        vector<int> vi;
        /*现在向量包含了 b-a 个 a-b 之间的整数并且按升序排列*/
        for (int i = a; i <= b; ++i)
        {
            vi.push_back(i);
        }

        generator.seed(GetPerformanceSeed());
        std::shuffle(vi.begin(), vi.end(), std::default_random_engine(generator));

        //http://www.cplusplus.com/reference/algorithm/random_shuffle/?kw=random_shuffle
        //random_shuffle(vi.begin(), vi.end()); /* 打乱元素 */

        return vi;
    }
};

int main()
{
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数


    fout.open("leapsTallBuildings_UVA10372.in");

    int testCase=100;
    while (testCase--)
    {
        //***************************
        //在此处写入测试数据
        //***************************
        int N = rdNum.GetRand(3, 100);
        fout << N << "\n";
        N--;
        fout << 0 << " " << rdNum.GetRand(10,1000)/10.0 << "\n";
        while (N--)
        {
            if(N<=0)
            {
                fout << 0 << " " << rdNum.GetRand(10,10000)/10.0 << "\n";                
            }
            else
            {
                fout << rdNum.GetRand(10,1000)/10.0 << " " << rdNum.GetRand(10,1000)/10.0 << "\n";            
            }
            
            
        }
    
    }
    fout.close();
    

    return 0;
}
