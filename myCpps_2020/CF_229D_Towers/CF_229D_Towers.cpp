/*
===========================================================
* @Name:           229D Towers
* @Author:         Shawn
* @create Time:    2020/1/21 20:36:50
* @url:            https://codeforces.com/contest/229/problem/D
* @Description:    
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = INT_MAX / 2;

void solve()
{
    int n; cin >> n;

    vector<int> a(n + 1, 0), sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];

        sum[i] = sum[i - 1] + a[i];
    }

    vector<int> f(n + 1, inf), cff(n + 1, 0);
    f[0] = 0; cff[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= i - 1; ++j)
        {
            if (cff[j] <= sum[i] - sum[j])
            {
                f[i] = min(f[i], f[j] + (i - j - 1));
                cff[i] = sum[i] - sum[j];
            }
        }
    }

    cout << f[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_229D_Towers.in", "r", stdin);
        freopen("CF_229D_Towers.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}