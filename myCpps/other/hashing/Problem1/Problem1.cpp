/*
===========================================================
* @Name:           Problem 1
* @Author:         Shawn
* @create Time:    2019/11/12 18:10:00
* @url:            https://www.quora.com/q/threadsiiithyderabad/String-Hashing-for-competitive-programming
* @Description:    
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ull P1 = 131; //质数
const ull MOD = 100000000743856857ull;

int charAt(char a)
{
    return a - 'a' + 1;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string s2 = s;
    reverse(s2.begin(), s2.end());

    vector<ull> a(n, 0);
    vector<ull> b(n, 0);
    vector<ull> p(n, 0);

    // //s计算哈希
    // ull hashValue1 = 0;
    // for (int i = 0; i <= n - 1; ++i)
    // {
    //     hashValue1 = P1 * hashValue1 + charAt(s[i]);
    //     a[i]=hashValue1;
    //

    //s计算哈希
    ull hashValue1 = 0;
    ull r = 1;
    for (int i = 0; i <= n - 1; ++i)
    {
        p[i] = r;

        // hashValue1 += ((r % MOD) * (charAt(s[i]) % MOD)) % MOD;
        // r = r * P1 % MOD;

        hashValue1 += r * charAt(s[i]);
        r *= P1;

        a[i] = hashValue1;
    }

    hashValue1 = 0;
    r = 1;
    for (int i = 0; i <= n - 1; ++i)
    {
        // hashValue1 += ((r % MOD) * (charAt(s2[i]) % MOD)) % MOD;
        // r = r * P1 % MOD;
        // b[i] = hashValue1 % MOD;

        hashValue1 += r * charAt(s2[i]);
        r *= P1;

        b[i] = hashValue1;
    }

    int q;
    cin >> q;
    //vector<pair<int,int>> Q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int ra = r - 1;
        ull hashA = a[ra];
        int la = l - 1;
        if (la - 1 >= 0)
            hashA -= a[la - 1];

        //hashA /= p[la];

        int lb = n - r;
        int rb = lb + r - l;
        ull hashB = b[rb];

        if (lb - 1 >= 0)
            hashB -= b[lb - 1];

        //hashB /= p[lb];

        if (lb > la)
        {
            hashA *= p[lb - la];
        }

        if (hashA == hashB)
            cout << "yes\n";
        else
            cout << "no\n";

        cout << hashA << "-" << hashB << "\n";
        //Q.push_back(make_pair(l,r));
    }

    cout << "";
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