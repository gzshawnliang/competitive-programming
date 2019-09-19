#include <bits/stdc++.h>

using namespace std;


int main()
{
    vector<string> v1={"abc","dbc","def",""};
    
    // NOTE,把数组的size()放在for循环的判断会导致死循环或溢出，例子如下：
    for (int i = 0; i <= v1.size() - 1; ++i)
    {
        string s=v1[i];
        for (int j = 0; j <= s.size() - 1; ++j)
        {
            cout << s[j];
        }
        cout << '\n';
    }
    

    // BUG:原因如下>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    /*      1、当s.size()==0的时候,s.size()-1 != -1 而是 =18446744073709551615,
            2、因为s.size()的数据类型是std::size_t 等于unsigned int 
            3、在unsigned int中，0 - 1 = 18446744073709551615，从在unsigned int的最大值
            4、因此j <= s.size() - 1 等于 j < 18446744073709551615,或导致死循环或溢出了
    */      
   
    // NOTE,>>规范正确的代码>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int v1Size=v1.size(); //<<<<<<<<<<<<<
    for (int i = 0; i <= v1Size - 1; ++i)
    {
        string s=v1[i];
        int sSize=s.size(); //<<<<<<<<<<<<<
        for (int j = 0; j <= sSize - 1; ++j)
        {
            cout << s[j] ;
        }
        cout << '\n';
    }
    //C++11可以这样
    for (auto i:v1)
    {
        for (auto j:i)
        {
            cout << j;
        }
        cout << '\n';
    }    
    // NOTE,<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    return 0;
}
