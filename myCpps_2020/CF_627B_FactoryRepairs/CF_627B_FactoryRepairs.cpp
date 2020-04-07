/*
===========================================================
* @Name:           627B Factory Repairs
* @Author:         Shawn
* @create Time:    2020/4/7 0:08:50
* @url:            https://codeforces.com/contest/627/problem/B
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class fenwickTree
{
    private:

    int lowbit(int x)
    {
        return x & (-x);
    }

    public:

    vector<int> a;
    vector<int> s;

    fenwickTree(vector<int> & in)
    {
        int n = in.size();

        a.assign(n, 0);
        s.assign(n, 0);
    }

    void update(int k, int delta)
    {
        int n = s.size() - 1;

        a[k] += delta;

        for (int i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    int query(int k)
    {
        int n = s.size() - 1;
        int ans = 0;

        for (int i = k; i >= 1; i -= lowbit(i))
        {
            ans += s[i];
        }

        return ans;
    }

    int sum(int i, int j)
    {
        return query(j) - query(i - 1);
    }
};

void solve()
{
    int n, k, a, b, q; cin >> n >> k >> a >> b >> q;
    
        vector<int> tmp(n + 1, 0);
        fenwickTree tre1(tmp), tre2(tmp);
    for (int c = 1; c <= q; ++c)
    {
        int typ; cin >> typ;
        if (typ == 1)
        {
            int d, ai; cin >> d >> ai;
            tre1.update(d, min(b - tre1.a[d], ai));
            tre2.update(d, min(a - tre2.a[d], ai));
        }
        else
        {
            int d; cin >> d;

            int ans = 0;
            if (d > 1)      ans += tre1.sum(1, d - 1);
            if (d + k <= n) ans += tre2.sum(d + k, n);

            cout << ans <<'\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_627B_FactoryRepairs.in", "r", stdin);
        freopen("CF_627B_FactoryRepairs.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}