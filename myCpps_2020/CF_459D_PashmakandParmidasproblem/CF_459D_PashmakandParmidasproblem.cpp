/*
===========================================================
* @Name:           459D Pashmak and Parmida's problem
* @Author:         Shawn
* @create Time:    2020/3/22 15:20:19
* @url:            https://codeforces.com/contest/459/problem/D
* @Description:    树状数组
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class fenwickTree
{
    private:

    ill lowbit(ill x)
    {
        return x & (-x);
    }

    public:

    vector<ill> a;
    vector<ill> s;

    fenwickTree(vector<ill> & in)
    {
        ill n = in.size();

        a.assign(n, 0);
        s.assign(n, 0);
    }

    void update(ill k, ill delta)
    {
        ill n = s.size() - 1;

        a[k] += delta;

        for (ill i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    ill query(ill k)
    {
        ill n = s.size() - 1;
        ill ans = 0;

        for (ill i = k; i >= 1; i -= lowbit(i))
        {
            ans += s[i];
        }

        return ans;
    }

    ill sum(ill i, ill j)
    {
        return query(j) - query(i - 1);
    }
};

void solve()
{
    ill n; cin >> n;

    vector<ill> a(n);
    for (ill i = 0; i <= n - 1; ++i) cin >> a[i];
    
    vector<ill> f1(n);
        map<ill, ill> tmp1;
    for (ill i = 0; i <= n - 1; ++i)
    {
        ++tmp1[a[i]];
        f1[i] = tmp1[a[i]];
    }

    vector<ill> f2(n);
        map<ill, ill> tmp2;
    for (ill i = n - 1; i >= 0; --i)
    {
        ++tmp2[a[i]];
        f2[i] = tmp2[a[i]];
    }

    
    ill ans = 0;
        vector<ill> intMap(n + 1, 0);
        fenwickTree tre(intMap);
    for (ill i = n - 2; i >= 0; --i)
    {
        ill j = i + 1;

        tre.update(f2[j], 1);
        ans += tre.query(f1[i] - 1);
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_459D_PashmakandParmidasproblem.in", "r", stdin);
        freopen("CF_459D_PashmakandParmidasproblem.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}