/*
===========================================================
 * @名称：      514C Watto and Mechanism
 * @作者：      Thomas 
 * @创建时间：   2019-11-03 20:10:40 
 * @修改人：     Thomas 
 * @修改时间：   2019-11-03 20:10:40 
 * @备注：      哈希算法，需要大质数，根据变换之后的字符反推哈希值,注意需
 *             要模运算，否则unsigned long long都会溢出
 *             模运算规则 

运算规则
模运算与基本四则运算有些相似，但是除法例外。其规则如下：
(1)     (a + b) % p = (a % p + b % p) % p 
(2)     (a - b) % p = (a % p - b % p) % p 
(3)     (a * b) % p = (a % p * b % p) % p 
(4)     (a ^ b) % p = ((a % p)^b) % p 
结合律：
(5）    ((a+b) % p + c) % p = (a + (b+c) % p) % p 
(6）    ((a*b) % p * c)% p = (a * (b*c) % p) % p 
交换律：
(7)     (a + b) % p = (b+a) % p 
(8)     (a * b) % p = (b * a) % p
分配律：
(9)     ((a +b)% p * c) % p = ((a * c) % p + (b * c) % p) % p
重要定理
(10)    若a≡b (% p)，则对于任意的c，都有(a + c) ≡ (b + c) (%p)；
(11)    若a≡b (% p)，则对于任意的c，都有(a * c) ≡ (b * c) (%p)；
(12)    若a≡b (% p)，c≡d (% p)，则 (a + c) ≡ (b + d) (%p)，(a - c) ≡ (b - d) ，
        (a * c) ≡ (b * d) (%p)，(a / c) ≡ (b / d) (%p)；
 * 
 * @题目来源：   https://codeforces.com/problemset/problem/514/C
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
const ull R1 = 3;                       //质数

//大质数1e9+7不够大
const ull PRIME = 100000000743856857ull; 

ull hashCode(const string & s)
{
    // for (int i = 0; i <= len - 1; ++i)
    // {
    //     //hashValue = R1 * hashValue + (s[i] - 'a'+1);
    //     hashValue = (R1 * hashValue + (s[i] - 'a' + 1)) % PRIME;
    // }

    int len = s.length();
    ull hashValue = 0;
    for (int i = 0; i <= len - 1; ++i)
        hashValue = (R1 * hashValue + (s[i] - 'a' + 1)) % PRIME;

    return hashValue;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_514C_WattoandMechanism.in", "r", stdin);
        //freopen("CF_631D_Messenger.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    unordered_set<ull> data;

    while (n--)
    {
        string s;
        cin >> s;

        ull sHash = hashCode(s);
        data.insert(sHash);
    }

    while (m--)
    {
        string s;
        cin >> s;

        ull sHash = hashCode(s);
        int len = s.length();
        bool found = false;
        ull p = 1;
        for (int i = len - 1; i >= 0 && !found; --i)
        {
            for (ull k = 1; k <= 3; ++k)
            {
                if (k == (ull)s[i] - 'a' + 1)
                {
                    continue;
                }

                ull iHash = ((s[i] - 'a' + 1) * p);
                ull kHash = (k * p);

                //反向推导更换字符的后的哈希值，再加一次PRIME确保无负数
                ull nowHash = (PRIME + sHash - iHash % PRIME + kHash % PRIME) % PRIME;

                if (data.count(nowHash) == 1)
                {
                    found = true;
                    break;
                }
            }
            p = (p * R1) % PRIME;
        }

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
