/*
===========================================================
* @Name:           1133E K Balanced Teams
* @Author:         Shawn
* @create Time:    2020/3/28 22:03:52
* @url:            https://codeforces.com/contest/1133/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = INT_MAX / 2;

void solve()
{
    int n, k; cin >> n >> k;
        vector<int> a(n, 0);
    for (int i = 0; i <= n - 1; ++i) cin >> a[i];
    
    sort(a.begin(), a.end());

    vector<int> maxShift(n, 0);
    for (int i = 0; i <= n - 1; ++i)
    {
        int maxN = 0, minN = inf;
        for (int j = i; j <= n - 1; ++j)
        {
            maxN = max(maxN, a[j]); minN = min(minN, a[j]);
            if (maxN - minN > 5) continue;

            maxShift[i] = (j - i);
        }
    }

    vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
            if (j + 1 <= k)
                f[i + maxShift[i] + 1][j + 1] = max(f[i + maxShift[i] + 1][j + 1], f[i][j] + maxShift[i] + 1);
        }
    }

    cout << f[n][k] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1133E_KBalancedTeams.in", "r", stdin);
        freopen("CF_1133E_KBalancedTeams.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}