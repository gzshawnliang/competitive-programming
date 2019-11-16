/*
===========================================================
* @Name:           Problem 1
* @Author:         Thomas
* @create Time:    2019/11/12 18:10:00
* @url:            https://www.quora.com/q/threadsiiithyderabad/String-Hashing-for-competitive-programming
* @Description:    
运算规则
模运算与基本四则运算有些相似，但是除法例外。其规则如下：
(1)     (a + b) % p = (a % p + b % p) % p 
        (p + b) % p = (p % p + b % p) % p = (0 + b % p) % p = b % p % p = b % p
        (a + b + c) % p = (a % p + b % p + c % p) % p
        (a + b + c + d) % p = (a % p + b % p + c % p+ d % p) % p
(2)     (a - b) % p = (a % p - b % p + p) % p [Correct]
        (a - b) % p = (a % p - b % p) % p  [Wrong] 可能负数
(3)     (a * b) % p = (a % p * b % p) % p 
        (a * b * c) % p = ((a * b) % p * c % p) % p
        (a * b * c * d) % p = ((((a * b) % p * c) % p) * d) % p
(4)     (a ^ b) % p = ((a % p)^b) % p 
结合律：
(5）    ((a+b) % p + c) % p = (a + (b+c) % p) % p 
(6）    ((a*b) % p * c) % p = (a * (b*c) % p) % p 
        (a * x + b * y + c) % p = ( (a * x) % p +(b * y) % p+ c % p ) % p
交换律：
(7)     (a + b) % p = (b+a) % p 
(8)     (a * b) % p = (b * a) % p
分配律：
(9)     ((a +b) % p * c) % p = ((a * c) % p + (b * c) % p) % p
重要定理
(10)    若a≡b (% p)，则对于任意的c，都有(a + c) ≡ (b + c) (%p)；
(11)    若a≡b (% p)，则对于任意的c，都有(a * c) ≡ (b * c) (%p)；
(12)    若a≡b (% p)，c≡d (% p)，则 (a + c) ≡ (b + d) (%p)，(a - c) ≡ (b - d) ，
        (a * c) ≡ (b * d) (%p)，(a / c) ≡ (b / d) (%p)；
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ull P1 = 101;      //质数
const ull MOD = 1e9 + 7; //质数

// A function to check if a string str is palindrome
// in the ranfe L to R
bool isPalindrome(const string & str, int L, int R)
{
    // Keep comparing characters while they are same
    while (R > L)
    {
        if (str[L] != str[R])
            return false;

        ++L;
        --R;
    }
    return true;
}

// A Function to find pow (base, exponent) % MOD
// in log (exponent) time
ull modPow(ull base, ull exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    ull temp = modPow(base, exponent / 2);

    if (exponent % 2 == 0)
        return (temp % MOD * temp % MOD) % MOD;
    else
        return (((temp % MOD * temp % MOD) % MOD) * base % MOD) % MOD;
}

// A Function to calculate Modulo Multiplicative Inverse of 'n'
ull findMMI(ull n)
{
    return modPow(n, MOD - 2);
}

// A Function to calculate the prefix hash
void computePrefixHash(const string & str, int n, vector<ull> & prefix, vector<ull> & power)
{
    prefix[0] = 0;
    prefix[1] = str[0];

    for (int i = 2; i <= n; i++)
        prefix[i] = (prefix[i - 1] % MOD + (str[i - 1] % MOD * power[i - 1] % MOD) % MOD) % MOD;
}

// A Function to calculate the suffix hash
// Suffix hash is nothing but the prefix hash of
// the reversed string
void computeSuffixHash(const string & str, int n, vector<ull> & suffix, vector<ull> & power)
{
    suffix[0] = 0;
    suffix[1] = str[n - 1];

    for (int i = n - 2, j = 2; i >= 0 && j <= n; i--, j++)
        suffix[j] = (suffix[j - 1] % MOD + (str[i] % MOD * power[j - 1] % MOD) % MOD) % MOD;
}

void solve()
{
    int n;
    string str;

    cin >> n >> str;

    //存储 101 幂的结果，先计算存储，以后使用
    //power[0]=101^0，power[1]=101^1，power[2]=101^2
    vector<ull> power(n + 1);

    power[0] = 1;           // 101^0 = 1
    for (int i = 1; i <= n; ++i)
        power[i] = (power[i - 1] % MOD * P1 % MOD) % MOD;
    
    /*  prefix[i]存储第i个字符之前字符的累计哈希值
        -----------------------------------------------------------
        prefix[0] = 0
        prefix[i] = str[0] + str[1] * 101 + str[2]   * 101^2 + 
                                    ..... + str[i-1] * 101^(i-1)

                                       012345678910 
        For example, take the string-  abaaabxyaba

        prefix[0] = 0
        prefix[1] = 97  (ASCII Value of ‘a’ is 97)
        prefix[2] = 97 + 98 * 101
        prefix[3] = 97 + 98 * 101 + 97 * 101^2
        ...........................
        ...........................
        prefix[11] = 97 + 98 * 101 + 97 * 101^2 +
                                ........+ 97 * 101^10
        -----------------------------------------------------------
        
        L~R子串的哈希值
        hash(L, R) = prefix[R+1] – prefix[L]
        For example, 
        hash (1, 5) = hash ("baaab") = prefix[6] – prefix[1] = 98 * 101 + 97 * 101^2 + 97 * 101^3 + 97 * 101^4 + 98 * 101^5 = 1040184646587 
    */
    vector<ull> prefix(n + 1);


    /*  suffix[i]存储第i个字符之后的字符累计哈希值
        -----------------------------------------------------------
        suffix[0] = 0
        prefix[i] = str[n-1] + str[n-2] * 101 + str[n-3] * 101^2 +
                                       ...... + str[n-i] * 101^(i-1)

        For example, take the string- "abaaabxyaba"

        suffix[0] = 0
        suffix[1] = 97  (ASCII Value of ‘a’ is 97)
        suffix[2] = 97 + 98 * 101
        suffix[3] = 97 + 98 * 101 + 97 * 101^2
        ...........................
        ...........................
        suffix[11] = 97 + 98 * 101 + 97 * 101^2 + ........+ 97 * 101^10
        -----------------------------------------------------------
        
        L~R子串的反向哈希值
        reverse_hash(L, R) = hash (R, L) = suffix[n-L] – suffix[n-R-1] 
        reverse_hash(1,5) = reverse_hash("baaab") = hash("baaab") [Reversing "baaab" gives "baaab"]
        hash("baaab") = suffix[11-1] – suffix[11-5-1] = suffix[10] – suffix[5] = 98 * 101^5 + 97 * 101^6 + 97 * 101^7 + 97 * 101^8 + 98 * 101^9 = 108242031437886501387

        1040184646587 * 101^4 = 108242031437886501387

        (prefix[R + 1]  – prefix[L]) / (101^L)  = 
        (suffix [n - L] – suffix [n – R- 1] ) / (101^(n – R - 1))
    */
    vector<ull> suffix(n + 1);

    // Compute Prefix Hash and Suffix Hash Arrays
    computePrefixHash(str, n, prefix, power);
    computeSuffixHash(str, n, suffix, power);

    int Q;
    cin >> Q;

    while (Q--)
    {

        int L;
        int R;
        cin >> L >> R;
        --L;
        --R;

        // Hash Value of Substring [L,R]
        ull hash_LR         = ((prefix[R + 1] - prefix[L] + MOD) % MOD * findMMI(power[L]) % MOD) % MOD;

        // Reverse Hash Value of Substring [L,R]
        ull reverse_hash_LR = ((suffix[n - L] - suffix[n - R - 1] + MOD) % MOD * findMMI(power[n - R - 1]) % MOD) % MOD;

        // If both are equal then the substring is a palindrome
        if (hash_LR == reverse_hash_LR)
        {
            if (isPalindrome(str, L, R) == true)
                cout << "yes:" << L+1 << "-" << R+1 << ":" << str.substr(L, R - L + 1) << "\n";
            else
                cout << "no\n";
        }

        else
            cout << "no\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("Problem1.in", "r", stdin);
    //freopen("Problem1.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}