#include <algorithm>    //random_shuffle
#include <iostream>     //cin,cout
#include <cstdlib>      //rand,cstdio
#include <ctime>        //time
#include <cmath>        //数学库
#include <vector>


using namespace std;

//要取得[a,b]的随机整数
int getRand(int a,int b)
{
    int c=b-a+1;
    return rand() % c + a;
}

//要取得[a,b)的随机整数
int getRand1(int a,int b)
{
    int c=b-a;
    return rand() % c + a;
}

//要取得(a,b]的随机
int getRand2(int a,int b)
{
    int c=b-a;
    return rand() % c + a+1;
}

//要取得0~RAND_MAX(32767)之间的随机数程序
int getRand3()
{
    return rand();
}

const int MAX_RAND = (int)1e9;

//获取大于RAND_MAX的随机数
long long getRand4()
{
    return (long long)((double)rand()/RAND_MAX * MAX_RAND); // 注：RAND_MAX值为32767
}

//获取0~1随机数浮点数
double randf() 
{ 
    return (double)(rand()/(double)RAND_MAX); 
} 

//产生[a,b]之间不重复的随机数,缺点：如数据量比较大占内存
vector<int> getRand5(int a,int b)
{
    vector<int> vi;
    /*现在向量包含了 1000 个 0-9999 之间的整数并且按升序排列*/
    for (int i = a; i <= b; ++i)
    {
        vi.push_back(i);
    }
    
    //http://www.cplusplus.com/reference/algorithm/random_shuffle/?kw=random_shuffle
    random_shuffle(vi.begin(), vi.end()); /* 打乱元素 */

    return vi;
    
}

//输出vector
void coutVector(const vector<int> & vi)
{
    for (auto it=vi.begin(); it!=vi.end(); ++it)
        std::cout << ' ' << *it;
}


int main()
{
    //初始化随机数发生器
    srand(time(NULL));

    int caseCount=10;

    // while(caseCount--)
    // {
    //     double i = randf();

    //     cout << i << " ";
    //     if(caseCount % 50 ==0)
    //     {
    //         cout << "\n";
    //     }
    // }
    
    // while(caseCount--)
    // {
    //     cout<<2<<'^'<< caseCount <<'=' <<(int)pow(2,caseCount) << endl;
    // }
    while(caseCount--)
    {
        vector<int> v = getRand5(5,100);
        coutVector(v);
        auto i=v.end() - v.begin();
        cout <<"\ni=" << i << "\n";
        cout<<"\n----------------"<<"\n";
    }

    // while(caseCount--)
    // {
    //     cout << getRand4() << " ";
    // }

    return 0;
}