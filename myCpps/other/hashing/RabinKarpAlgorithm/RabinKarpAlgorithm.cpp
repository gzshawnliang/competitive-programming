/*
======================================================================
 * @名称:      Rabin–Karp算法
 * @作者:      Shawn 
 * @创建时间:   2019-10-07 13:17:39 
 * @修改人:     Shawn 
 * @修改时间:   2019-10-07 13:17:39 
 * @备注:      Rabin-Karp算法的关键思想是 某一子串的hash值可以根据上一子串
 *            的hash在常数时间内计算出来，这样比对的时间复杂度可以降为O(n-k)。
 *            此算法在是go语言内置包strings的查找算法  
 * @参考：  
 * https://juejin.im/entry/5b4b2cebf265da0f8b2fa52d
 * https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
======================================================================
*/
#include <bits/stdc++.h>

using namespace std;

const int R = 256;              //进制,大于等于字符集的数量。如果仅仅匹配数字字符串，那么R大于10皆可，若包括各种字符，我们则需要为每个字符设定一个R进制的值（可以使用ASCII码），这时要求R要大于字符总数（否则有冲突）
const int PRIME = 10007;        //质数，产生哈希碰撞的概率为 1/PRIME，根据情况设置。蒙特卡洛方法是选取很大的质数值，使得散列冲突极小，这样可以保证散列值相同就是匹配成功；
    

/**
 * 计算哈希值,使用进制思想
 * https://zh.wikipedia.org/wiki/进位制
 * @param  {string} s : 【输入】字符串
 * @return {int}      : 【返回】哈希值
 */
int hashCode(const string & s)
{

        // int j=len-1;
        // for (int i = 0; i <=len-1; ++i)
        // {
        //     hash += s[i] * pow(R,j);
        //     j--;
        // }
    /*
        霍纳规则(Horner Rule)，最少的乘法运算策略
        用进制的算法计算哈希值
        hash(abc)=a*R^2 + b*R^1 + c*R^0 = ((a*R + b) * R) + c

        参考：
        https://en.wikipedia.org/wiki/Horner's_method
        https://zh.wikipedia.org/wiki/秦九韶算法
    */

    int len = s.length();
    int hashValue = 0;
    for (int i = 0; i <= len-1; ++i)
    {
        //此值太大，需要取模
        //hashValue = R * hashValue + s[i];

        hashValue = (R * hashValue + s[i]) % PRIME;
    }    
    return hashValue;
}


/**
 * RabinKarp字符串匹配查找
 * @param  {string} t : 【输入】源字符串
 * @param  {string} p : 【输入】模式字符串
 */
void RabinKarp(const string & t, const string & p)
{
    int t_len = t.length();
    int p_len = p.length();
    
    // 哈希滚动之用
    int maxH = 1;
    for (int i = 0; i <= p_len - 2; ++i)
        maxH = (maxH * R) % PRIME;

    int t_hash = hashCode(t.substr(0,p_len));
    int p_hash = hashCode(p);


    /*  常见模运算
        注意，在减法中，由于a%n 可能小于b%n，需要在结果上加上n。对于以上规则，a和b不需要同时%n，可以随意选取一方%n性质也成立。
        1： (a+b)%n = (a%n + b%n) %n;
        2： (a-b)%n = (a%n - b%n + n) %n;
        3： (a*b)%n = (a%n * b%n) %n;    
    */

    int i = 0;
    while (i <= t_len - p_len)
    {
         // 哈希值相同则字符串相同
        if (t_hash == p_hash)
            if(p==t.substr(i,p_len))    //考虑到哈希碰撞的可能性，还需要用暴力再比对一下。拉斯维加斯方法则是散列值相同后再去比较字符，效率不如上一种方法，但可以保证正确性。
                cout << p << " is found at index " << i << '\n';
        /*
            哈希滚动(按整数进制解析再求模)
            用到的数学公式为：t(s+1) = (d(t(s)-T[s+1]h)+T[s+m+1]) mod q
            t(s+1)为目标字符串的子字符串T[s+1,s+m+1]的哈希值，因为用到了上一次的结果t(s)，
            所以可以节省计算时间。
        */
        t_hash = (R * (t_hash - t[i] * maxH) + t[i + p_len]) % PRIME;

        // 防止出现负数
        if (t_hash < 0)
            t_hash += PRIME;

        ++i;
    }
}


int main()
{
    string t = "aeminsajid";
    string p = "emi";
    
    RabinKarp(t, p);
    
    return 0;
}