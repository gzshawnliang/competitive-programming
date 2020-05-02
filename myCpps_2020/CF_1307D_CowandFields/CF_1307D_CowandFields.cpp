/*
===========================================================
* @Name:           1307D Cow and Fields
* @Author:         Shawn
* @create Time:    2020/5/1 21:18:55
* @url:            https://codeforces.com/contest/1307/problem/D
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    int n, m, k; cin >> n >> m >> k;

        vector<int> kp(k);
    for (int i = 0; i <= k - 1; ++i) cin >> kp[i];

    vector<vector<int>> g(n + 1);
    for (int c = 1; c <= m; ++c)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

        vector<int> dis1(n + 1, n + 1);
            dis1[1] = 0;
        set<pair<int, int>> q1;
            q1.insert({0, 1});
    while (q1.empty() == false)
    {
        pair<int, int> now = *q1.begin(); q1.erase(q1.begin());
        
        for (auto v:g[now.second])
        {
            if (dis1[v] > dis1[now.second] + 1)
            {
                dis1[v] = dis1[now.second] + 1;
                q1.insert({dis1[now.second] + 1, v});
            }
        }
    }

    vector<int> disN(n + 1, n + 1);
            disN[n] = 0;
        set<pair<int, int>> q2;
            q2.insert({0, n});
    while (q2.empty() == false)
    {
        pair<int, int> now = *q2.begin(); q2.erase(q2.begin());
        
        for (auto v:g[now.second])
        {
            if (disN[v] > disN[now.second] + 1)
            {
                disN[v] = disN[now.second] + 1;
                q2.insert({disN[now.second] + 1, v});
            }
        }
    }

        vector<pair<int, int>> b(k);
    for (int i = 0; i <= k - 1; ++i)
    {
        b[i] = {dis1[kp[i]] - disN[kp[i]], kp[i]};
    }
    sort(b.begin(), b.end());

        int maxF = dis1[b[0].second], ans = 0;
    for (int i = 1; i <= k - 1; ++i)
    {
        ans = max(ans, maxF + 1 + disN[b[i].second]);
        maxF = max(maxF, dis1[b[i].second]);
    }

    cout << min(ans, dis1[n]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1307D_CowandFields.in", "r", stdin);
        freopen("CF_1307D_CowandFields.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}