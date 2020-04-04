/*
===========================================================
* @Name:           61E Enemy is weak
* @Author:         Shawn
* @create Time:    2020/4/4 21:47:04
* @url:            https://codeforces.com/contest/61/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const ill maxN = 1e6 + 1;

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

        vector<ill> inp(n, 0);
    for (ill i = 0; i <= n - 1; ++i)
    {
        cin >> inp[i];
    }

        vector<ill> tmpInp = inp, a;
        sort(tmpInp.begin(), tmpInp.end());
    for (ill i = 0; i <= n - 1; ++i)
    {
        a.push_back(lower_bound(tmpInp.begin(), tmpInp.end(), inp[i]) - tmpInp.begin() + 1);
    }

        vector<ill> larges(n, 0);
        vector<ill> nul(maxN + 1, 0);
            fenwickTree treT1(nul);
    for (ill i = 0; i <= n - 1; ++i)
    {
        treT1.update(a[i], 1);
        larges[i] = i + 1 - treT1.query(a[i]);
    }
    //larges.insert(larges.begin(), -1);

        ill total = 0, ans = 0;
        fenwickTree treT2(nul);
    for (ill i = 0; i <= n - 1; ++i)
    {
        ans += (total - treT2.query(a[i]));

        total += larges[i];
        treT2.update(a[i], larges[i]);
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_61E_Enemyisweak.in", "r", stdin);
        freopen("CF_61E_Enemyisweak.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}