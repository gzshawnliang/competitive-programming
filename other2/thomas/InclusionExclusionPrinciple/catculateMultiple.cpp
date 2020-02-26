#include <bits/stdc++.h>

using namespace std;

/* 
    计算100以内2倍数或3的倍数有多少个？
 */
void catculate1()
{
    int ans = 0;
    for (int i = 1; i <= 100; ++i)
    {
        if (i % 2 == 0 || i % 3 == 0)
        {
            ++ans;
        }
    }
    cout << ans << '\n';
}

/* 
    计算100以内2倍数或3的倍数you多少个？
 */
void catculate2()
{
    cout << 100 / 2 + 100 / 3 - 100 / 6 << '\n';
}

void catculate3()
{
    
}


/** 计算小于n，2、3、5、7、11的倍数多少个
 * 
 * @param  {int} n : < 1e9
 */
void catculateMultiple(int n)
{
    vector<int> a = {2,3,5,7,11};
    int k = a.size();
    int ans = 0;
    int total = (1 << k); //枚举2^k种状态

    //每个数都有2种状态 ，对应着取与不取。 
    //在本题中带的意思是2，3，5，7，11的倍数或不是，
    //一共有2^5种可能
    //枚举2^5-1 {00000}~{11111}种状态,第0{00000}个不需要
    for (int i = 1; i <= total - 1; ++i)
    {
        bitset<5> b(i);
        int lcm = 1;
        for (int j = 0; j <= k - 1; ++j)
        {
            //查看每一位的情况
            bitset<5> c((1 << j));
            
            //cout <<"i: "<< b.to_string() <<  " - j: "  << c.to_string() ;

            if ((1 << j) & i)  //是否选第j个
            {
                //cout << ":OK";                 
                cout << a[j] << " ";
                lcm *= a[j];
            }
        }
        cout << "\n";

        //1的数量
        if (b.count() % 2 == 1)
            ans += (n / lcm);       //1的个数是奇数则加 偶数则减
        else
            ans -= (n / lcm);
    }
    cout << ans << "\n";
}

int main()
{
    // catculate1();
    // catculate2();

    //catculateMultiple(1000);

    vector<string> a={"a","b","c","d","e"};

    int n=a.size();
    int total = 1<<n;

     for (int i = 0; i <= total - 1; ++i)
     {
         //bitset<5> b(i);
         for (int j = 0; j <= n - 1; ++j)
         {
            if((1<<j) & i)
            {
                cout << a[j] << " ";
            }
            //  if(b[j]==1)
            //  {
            //      cout << a[j] << " ";
            //  }            
             
         }
        cout << "\n";

         //cout << i << ": " << b.to_string() << "\n";
     }


    return 0;
}
