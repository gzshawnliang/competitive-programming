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
             1:00001  2:00010  3:00011  4:00100  5:00101  
             6:00110  7:00111  8:01000  9:01001 10:01010 
            11:01011 12:01100 13:01101 14:01110 15:01111 
            16:10000 17:10001 18:10010 19:10011 20:10100 
            21:10101 22:10110 23:10111 24:11000 25:11001 
            26:11010 27:11011 28:11100 29:11101 30:11110 
            31:11111 
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
