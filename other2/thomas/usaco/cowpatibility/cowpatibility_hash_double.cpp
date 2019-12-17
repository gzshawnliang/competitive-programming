#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll BASE = 131;
const ll PRIME = 1e9 + 7;

const ll BASE2 = 42139;
const ll PRIME2 = 100000000743856857ll;

int main()
{

    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
#endif

    unordered_map<ll, ll> f;
    ll n;
    string s;

    cin >> n;
    ll totalAns = n * (n - 1) / 2; //总共对数

    for (ll i = 1; i <= n; i++)
    {
        vector<ll> a(6);
        for (ll j = 1; j <= 5; j++)
            cin >> a[j];

        sort(a.begin() + 1, a.end()); //从小到大排序

        ll ans = 0;
        for (ll i = 1; i < 32; ++i)
        {
            //二进制枚举出所有情况
            bitset<5> b(i);

            ll cnt = 0;
            //string s = "";
            ll hashValue1=0;
            ll hashValue2=2;
            for (ll j = 1; j <= 5; ++j)
            {
                if (b[j - 1] == 1)
                {
                    ++cnt;
                    hashValue1 = (BASE * hashValue1 + a[j]) % PRIME;
                    hashValue2 = (BASE2 * hashValue2 + a[j]) % PRIME2;
                    //s += a[j] + "|";
                } //将选出的口味用“？”连接出来
            }
            hashValue1 = (hashValue1 * hashValue2) % PRIME2;

            if (cnt % 2 == 0)
                ans -= f[hashValue1]; //偶数个则减去
            else
                ans += f[hashValue1]; //奇数个则累加

            ++f[hashValue1];
        }
        totalAns -= ans; //减去和谐的，容斥
    }
    cout << totalAns;
    cout.flush();
    return 0;
}