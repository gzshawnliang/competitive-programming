/*
===========================================================
* @Name:           1355E Restorer Distance
* @Author:         Shawn
* @create Time:    2020/5/25 15:01:25
* @url:            https://codeforces.com/contest/1355/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, A, R, M;
ll f(ll x, vector<ll> & h)
{
    ll dn = 0; //需要减少dn次
    ll up = 0; //需要增加up次
    for (ll i = 0; i <= N - 1; ++i)
        if (h[i] < x)
            up += (x - h[i]);
        else if (h[i] > x)
            dn += (h[i] - x);

    ll cost = 0;
    
    if (A + R >= M)                 //移动的代价小，优先移动
    {
        ll maxMov = min(up, dn);    //最大移动次数
        cost += maxMov * M;         //移动代价

        dn -= maxMov;               //移动之后减少dn次数
        up -= maxMov;               //移动之后减少up次数

        cost += up * A + dn * R;    //加上up down的代价
    }
    else                            //移动的代价太大，不移动，直接up和down
    {
        cost = up * A + dn * R;
    }

    return cost;
}

ll ternary_search2(ll left, ll right, vector<ll> & h)
{
    ll midL, midR, ans = 0;
    while (right - left >= 1)
    {
        midL = left + (right - left) / 3;
        midR = right - (right - left) / 3;

        ll fL = f(midL, h);
        ll fR = f(midR, h);
        ans = min(fL, fR);

        //如果是求最大值的话这里判>=即可
        //如果是求最小值的话这里判<=即可
        if (fL <= fR)
            right = midR - 1;
        else
            left = midL + 1;

        cerr << left << " " << right << endl;
    }
    return ans;
}

void solve()
{

    cin >> N >> A >> R >> M;
    //assert(N > 0);
    vector<ll> h(N, 0);
    for (ll i = 0; i <= N - 1; ++i)
        cin >> h[i];

    sort(h.begin(), h.end());
    ll left = h.front();
    ll right = h.back();

    ll ans = ternary_search2(left, right, h);

    cout << ans;

    assert(N > 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1355E_RestorerDistance.in", "r", stdin);
    //freopen("CF_1355E_RestorerDistance.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}