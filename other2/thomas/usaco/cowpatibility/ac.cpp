#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull PRIME = 998244353;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
#endif

    map<ull, int> cnt[2];

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        vector<int> a(5);
        for (int j = 0; j < 5; j++)
        {
            cin >> a[j];
        }
        sort(a.begin(), a.end());

        for (int i = 1; i < 32; ++i)
        {
            ull s = 0;
            int c = 0;
            for (int j = 0; j < 5; j++)
            {
                if ((i >> j ) % 2)
                {
                    s = s * PRIME + a[j];
                    ++c;
                }
            }

            ++cnt[c % 2][s];
        }
    }
    int ans = 0;
    for (auto p : cnt[1])
    {
        int i = p.second;
        ans += i * (i - 1) / 2;
    }
    for (auto p : cnt[0])
    {
        int i = p.second;
        ans -= i * (i - 1) / 2;
    }

    cout << n * (n - 1) / 2 - ans << "\n";
    return 0;
}