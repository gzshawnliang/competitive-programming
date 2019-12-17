#include <bits/stdc++.h>
using namespace std;

using ll=long long ;

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("cowpatibility.in", "r", stdin);
//     freopen("cowpatibility.out", "w", stdout);
// #endif

    ofstream cout("cowpatibility.out");
    ifstream cin("cowpatibility.in");

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
            //二进制枚举出所有情况
            ll cnt = 0;
            string s = "";
            for (ll j = 1; j <= 5; ++j)
            {
                if (i & (1 << (j - 1)))
                {
                    ++cnt;
                    s += "?" + a[j];
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

    // for (auto it : f)
    // {
    //     cout << std::left << setw(15) << it.first << " " << it.second << "\n";
    // }

    cout << totalAns;
    return 0;
}

// ll main3()
// {

//     for (ll j = 1; j <= 5 ; ++j)
//     {
//         ll r=(1<<(j-1));
//         cout << "1<<("<< j <<"-1)=1<<("<< j-1 <<") "  << r << "\n";
//     }
//     cout << "\n";
//     for (ll i = 1; i <= 32-1 ; ++i)
//     {
//         for (ll j = 1; j <= 5 ; ++j)
//         {
//             ll r=(1<<(j-1));
//             //cout << "1<<(j-1) " << r <<
//             cout << setw(2) << i << " & "<< setw(2) << r << setw(8) << (i & r) <<  "\n";
//         }
//     }

//     return 0;
// }

ll main4()
{

    for (ll i = 1; i <= 32 - 1; ++i)
    {
        bitset<5> b(i);
        cout << setw(2) << i << setw(6) << b.to_string() << "\n";
        cout << "---------"
             << "\n";
        for (ll j = 1; j <= 5; ++j)
        {
            ll r = (1 << (j - 1));
            bitset<5> c(r);
            cout << setw(2) << j << setw(6) << c.to_string() << "\n";
        }
        cout << "\n";
    }

    return 0;
}

ll main33()
{
    vector<ll> a = {1, 2, 3, 4, 5};

    for (ll i = 0; i <= 5 - 1; ++i)
    {
        cout << a[i] << "-\n";

        for (ll k = 0; k <= 5 - 1; ++k)
        {
            if (k != i)
            {
                cout << a[k] << "-";
            }
        }
        cout << "\n";
    }

    for (ll i = 0; i <= 5 - 1; ++i)
    {
        for (ll j = i + 1; j <= 5 - 1; ++j)
        {
            cout << a[i] << "-" << a[j] << "-\n";
            for (ll k = 0; k <= 5 - 1; ++k)
            {
                if (k != i && k != j)
                {
                    cout << a[k] << "-";
                }
            }
            cout << "\n";
        }
    }

    for (ll k = 0; k <= 5 - 1; ++k)
    {
        cout << a[k] << "-";
    }
    cout << "\n";

    cout << "-----------------\n";

    for (ll i = 1; i < 32; ++i)
    {
        //二进制枚举出所有情况
        string s = "";
        for (ll k = 1; k <= 5; ++k)
        {
            if (i & (1 << (k - 1)))
            {
                cout << a[k - 1] << "-";
            }
        }
        cout << "\n";
    }

    return 0;
}