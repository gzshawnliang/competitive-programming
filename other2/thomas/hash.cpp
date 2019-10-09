#include <bits/stdc++.h>

using namespace std;

//ifstream fin("hash.in");
//ofstream fout("hash.out");

int hashCode(int x) {return x % 5;}

int hashCode2(const string & x, int prime)
{
    int hashValue = 0;
    for (auto i : x)
        hashValue += i;
    return hashValue % prime;
}



unsigned long long hashCode3(const string & x)
{
    int len = x.length();
    unsigned long long ans = 0, p = 1;
    for (int i = 0; i <= len - 1; ++i)
    {
        ans = ans * p + x[i];
        p *= 13331;
    }
    return ans;
}

/**
 * 
 * @param  {string} x  : 
 * @param  {int} M     : 
 * @return {unsigned}  : 
 */
unsigned long long hashCode4(const string & x,int M)
{
    unsigned long long hash=0;
    int len = x.length();
    int R = 101;    //进制

    // int j=len-1;
    // for (int i = 0; i <=len-1; ++i)
    // {
    //     hash += x[i] * pow(R,j);
    //     j--;
    // }
    /*
        霍纳规则(Horner Rule)，最少的乘法运算策略
        hash(abc)=a*R^2 + b*R^1 + c*R^0 = ((a*R + b) * R) + c

        参考：
        https://en.wikipedia.org/wiki/Horner's_method
        https://zh.wikipedia.org/wiki/秦九韶算法
    */

    hash=0;
    for (int i = 0; i <=len-1; ++i)
    {
        hash = R * hash + x[i];
        //如果过大造成溢出，可以将行换成：
        //hash = (R * hash + x[i]) % M;
    }
    return hash % M;
}

/*
哈希攻击
当R=31的时候
Aa和BB的哈希值相同
*/
unsigned long long hashCode5(const string & x)
{
    unsigned long long hash=0;
    int len = x.length();
    int R = 31;    //进制

    hash=0;
    for (int i = 0; i <=len-1; ++i)
    {
        hash = R * hash + x[i];
    }
    return hash ;
}

int main()
{
    // cout << hashCode(13) << '\n';
    // cout << hashCode(7) << '\n';
    // cout << hashCode(14) << '\n';
    // cout << hashCode(11) << '\n';

    // cout << "----------------" << "\n";
    // cout << hashCode2("abc",11) << '\n';
    // cout << hashCode2("abe",11) << '\n';
    // cout << hashCode2("abg",11) << '\n';
    // cout << hashCode2("gbc",11) << '\n';
    // cout << "----------------" << "\n";
    
    // std::hash<string> h;
    // cout << h("abe") % 99923<<'\n';
    // cout << h("abc")  % 99923<<'\n';
    
    // cout << h("Meet the new boss...") %99923 <<'\n';
    // cout << "----------------" << "\n";

    // std::hash<int> h2;
    // cout << h2(100) %991 <<'\n';
    // cout << h2(99) <<'\n';
    
    // cout << h2(832487234) <<'\n';

    cout << "----------------" << "\n";
    // cout << hashCode4("a",1009) << '\n';
    // cout << hashCode4("b",1009) << '\n';
    // cout << hashCode4("ab",1009) << '\n';
    cout << hashCode5("Aa") << '\n';
    cout << hashCode5("BB") << '\n';
    cout << "----------------" << "\n";    

    return 0;
}
