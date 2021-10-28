/*
===========================================================
 * @名称:    Problem 2. Dishwashing
 * @作者:    Shawn 
 * @创建时间: 2020-01-02 22:21:24 
 * @修改人:   Shawn 
 * @修改时间: 2020-01-02 22:21:24 
 * @备注:    USACO 2019 February Contest, Gold
 * @题目来源： http://www.usaco.org/index.php?page=viewproblem2&cpid=922
===========================================================
*/
#include <bits/stdc++.h>
using namespace std;

class solution
{
    public:

    int n;
    vector<int> a;
    vector<int> bot;
    vector<stack<int>> s;

    solution(int n)
    {
        this->n=n;
        a.assign(n + 1,0);
        bot.assign(n + 1,0);
        s.assign(n + 1,stack<int>());
    }
    void clearStack(int x)
    {
        for (int i = 1; i <= x; i++)
            while (!s[i].empty())
                s[i].pop();
    }
    bool check(int x)
    {
        clearStack(x);
        s[1].push(a[1]);
        int l = 1, r = 1, mx = 0;
        bot[1] = a[1];
        for (int i = 2; i <= x; i++)
        {
            if (a[i] < mx)
                return false;

            int p = upper_bound(bot.begin() + l, bot.begin() + r + 1, a[i]) - bot.begin();
            if (p == r + 1)
            {
                ++r;
                s[r].push(a[i]);
                bot[r] = a[i];
            }
            while (s[p].top() < a[i])
            {
                mx = s[p].top();
                s[p].pop();
            }
            s[p].push(a[i]);
        }

        return true;
    }
};




int main()
{
#ifndef ONLINE_JUDGE
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
#endif

    int n;
    cin >> n;
    solution solution1(n);
    
    for (int i = 1; i <= n; i++)
        cin >> solution1.a[i];

    int l = 1;
    int r = n;
    int mid;
    int ans = n;
    while (r >= l)
    {
        mid = (l + r) / 2;
        if (solution1.check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
}