#ifndef LOCAL_DEBUG
#define NDEBUG // ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ll = long long;
const ll INF = 1e18;

class solution
{
    ll step1;
    void convert(ll x, ll y)
    {
        if (x > y)
        {
            step1 = INF;
            return;
        }

        if (x * 2 > y)
        {
            step1 += (y - x);
            return;
        }

        if (y % 2 == 1)
        {
            ++step1;
            convert(x, y - 1);
        }
        else
        {
            ++step1;
            convert(x, y / 2);
        }
    }

    ll sum(ll a, ll b)
    {
        if (a == b)
            return 0;
        
        ll ans = 1e12, step2 = 0;

        if (a == 1) //处理a==1的情况
        {
            a = a * 2;
            ++step2;
        }
        if (a == b)
            return step2;

        while (a > 1)
        {
            step1 = 0;
            convert(a, b); //当a<b时，a->b需要的最小步骤数

            ans = min(ans, step1 + step2);

            if (a % 2 == 1)
                ++a;
            else
                a = a / 2;

            ++step2; //缩小a的步骤数
        }
        return ans;
    }

  public:
    void solve()
    {
        int t;
        cin >> t;
        while (t--)
        {
            ll a, b;
            cin >> a >> b;
            cout << sum(a, b) << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("SearchingforSoulmates.in", "r", stdin);
    // freopen("SearchingforSoulmates2.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}