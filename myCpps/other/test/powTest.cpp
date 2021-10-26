#include <bits/stdc++.h>

using namespace std;

//ifstream fin("powTest.in");
//ofstream fout("powTest.out");
using ull = unsigned long long;
using ull128 =  unsigned __int128;

const ull p = 137;

ull hashcode(const string & x)
{
    int len = x.length();
    ull hashValue1 = 0;
    for (int i = 0; i <= len - 1; ++i)
        //计算哈希
        hashValue1 = p * hashValue1 + x[i];
    return hashValue1;
}

int main()
{
    // int n = 20;
    // for (int i = 0; i <= n - 1; ++i)
    // {
    //     ull result = pow(p, i);
    //     cout << "pow(" << p << "," << i << "):" << result << "\n";
    // }

    // string s="aaaaaabaaaaaaaaaa";
    // int len = s.length();
    // ull hashValue1 = 0;
    // for (int i = 0; i <= len - 1; ++i)
    // {
    //     hashValue1 = p * hashValue1 + s[i];             //计算哈希
    //     cout << i <<":" << hashValue1 << "\n";
    // }

    //ull i=12126010230444899546ull;
    ull i=ULONG_LONG_MAX-2;
    ull j = i * i;
    ull128 j128 = (ull128)i * (ull128)i;

    //ull k = j % LONG_LONG_MAX;
    cout << j << "\n";
    //cout << j128 << "\n";

    return 0;
}
