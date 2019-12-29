#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct cow
{
    int pos;
    int w;
};

bool check(int mid, int n, int sum, int L, vector<int> & x, vector<cow> & a, vector<int> & d)
{
    int S = 0;
    int to0Count = 0;
    int toLCount = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (x[i] + d[i] * mid <= 0)
            ++to0Count;
        else if (x[i] + d[i] * mid >= L)
            ++toLCount;
    }

    for (int i = 1; i <= to0Count; ++i)       //从右往左
        S += a[i].w;

    for (int i = 1; i <= toLCount; ++i)       //从左往右
        S += a[n - i + 1].w;

    return S * 2 >= sum;
}

void solve()
{
    int n = 0, L = 0, sum = 0;
    cin >> n >> L;

    vector<int> w(n + 1); //第i头牛的重量
    vector<int> x(n + 1); //第i头牛的坐标
    vector<int> d(n + 1); //第i头牛的方向,1或-1

    vector<int> toL;
    vector<int> to0;

    vector<cow> a(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> x[i] >> d[i];

        sum += w[i];
        if (d[i] == 1)
            toL.push_back(x[i]);
        else
            to0.push_back(x[i]);

        a[i] = (cow){x[i], w[i]};
    }

    sort(a.begin() + 1, a.end(),
         [](const cow & a, const cow & b) {
             return a.pos < b.pos;
         });

    sort(toL.begin(), toL.end());
    sort(to0.begin(), to0.end());

    int l = 0;
    int r = L;
    int T = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid, n, sum, L, x, a, d))     //假设1s钟移动一格，检查第T秒钟时，两端牛的重量
        {
            T = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    ll ans = 0;
    int c1 = toL.size();
    for (int i = 0; i <= c1 - 1; ++i)
    {
        l = lower_bound(to0.begin(), to0.end(), toL[i]) - to0.begin();
        r = upper_bound(to0.begin(), to0.end(), toL[i] + 2 * T) - to0.begin() - 1;
        ans += (ll)r - (ll)l + 1;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    //#endif

    solve();

    cout.flush();
    return 0;
}
