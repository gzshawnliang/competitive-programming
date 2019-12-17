#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{

    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
#endif

    unordered_map<string, ll> f;
    ll n;
    string s;

    cin >> n;
    ll totalAns = n * (n - 1) / 2; //总共对数

    for (ll i = 1; i <= n; i++)
    {
        vector<string> a(6);
        for (ll j = 1; j <= 5; j++)
            cin >> a[j];

        sort(a.begin() + 1, a.end()); //从小到大排序

        ll ans = 0;
        for (ll i = 1; i < 32; ++i)
        {
            /*二进制枚举出所有情况
            1~32的二进制正好是00000~11111范围内:
            00001 00010 00011 00100 00101 00110 
            00111 01000 01001 01010 01011 01100 
            01101 01110 01111 10000 10001 10010 
            10011 10100 10101 10110 10111 11000 
            11001 11010 11011 11100 11101 11110 
            11111 
            */
            bitset<5> b(i);

            ll cnt = 0;
            string s = "";
            for (ll j = 1; j <= 5; ++j)
            {
                if (b[j - 1] == 1)
                {
                    ++cnt;
                    s += a[j] + "|";
                } //将选出的口味用“？”连接出来
            }

            if (cnt % 2 == 0)
                ans -= f[s]; //偶数个则减去
            else
                ans += f[s]; //奇数个则累加

            ++f[s];
        }
        totalAns -= ans; //减去和谐的，容斥
    }

    // Debug
    // for (auto it : f)
    //     cout << std::left << setw(15) << it.first << " " << it.second << "\n";

    cout << totalAns;
    
    cout.flush();
    return 0;
}

int test()
{
    for (ll i = 1; i < 32; ++i)
    {
        //二进制枚举出所有情况
        //1~32的二进制正好是00000~11111范围内
        bitset<5> b(i);
        cout << b.to_string() << " ";

    }    
    return 0;
}