#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll maxA = 1e18;

void solve()
{
    int n, m;
    string s;
    cin >> n >> m >> s;

    //cnt[x,y]表示字母x,y有多少次相邻,也就是说字符x到字符y移动了多少次
    //a-0,b-1,c-3...
    vector<vector<int>> cnt(m, vector<int>(m, 0));        
    
    for (int i = 1; i <= n-1; ++i)
    {
        ++cnt[s[i] - 'a'][s[i - 1] - 'a'];
        ++cnt[s[i - 1] - 'a'][s[i] - 'a'];
    }
    ll dpMax = 1 << m;
    vector<ll> dp(dpMax, maxA);

    dp[0] = 0;
    for (int i = 0; i <= dpMax-1; ++i)
    {
        vector<int> d, f;
        for (int j = 0; j <= m-1; ++j)
            if (i >> j & 1)
                d.push_back(j);
            else
                f.push_back(j);

        ll tmp = 0;
        for (int k = 0; k < d.size(); ++k)
            for (int g = 0; g < f.size(); ++g)
                tmp += cnt[d[k]][f[g]];

        bitset<10> bi(i);
        cout << bi.to_string() << " ";
        for (int j = 0; j <= m-1; ++j)
        {
            if (i >> j & 1)
                continue;
            bitset<10> bj(i | 1 << j);
            cout << bj.to_string() << " ";

            dp[i | 1 << j] = min(dp[i | 1 << j], dp[i] + tmp);
        }
        cout << "\n";
    }
    cout << dp[dpMax - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("1238E.in", "r", stdin);
    //freopen("1238E.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}
