#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const double eps = 1e-6;

bool cmp(double x, double y)
{
    return x > y;
}

// 判断是否能够获得大于mid的准确率
bool check(double mid, vector<pair<ll, ll>> & a, ll n, ll k)
{
    ll s = 0;
    vector<double> c(n);
    for (ll i = 0; i <= n - 1; ++i)
        c[i] = a[i].first - mid * a[i].second;

    sort(c.begin(), c.end(), [](const double x, const double y) {
        return x > y;
    });

    for (ll i = 1; i <= n - k + 1; ++i)
        s += c[i];

    return s > 0;
}

void solve()
{
    while (true)
    {
        ll n = 0;
        ll k = 0;
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;

        vector<pair<ll, ll>> a(n);
        for (ll i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].first;
        }
        for (ll i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].second;
        }

        double L = 0, R = 1;
        while (R - L > eps)
        {
            double mid = (L + R) / 2;
            if (check(mid, a, n, k))    //mid 可行，答案比 mid 大
                L = mid;
            else                        //mid 不可行，答案比 mid 小
                R = mid;
        }
        cout << L << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("POJ_2976_Droppingtests.in", "r", stdin);
    //freopen("POJ_2976_Droppingtests.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}