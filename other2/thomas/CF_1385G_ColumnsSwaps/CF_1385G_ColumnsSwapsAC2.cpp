#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;


class solution
{
    int cnt0, cnt1;
    vector<int> col, comp;
    vector<vector<pair<int, int>>> g;

    void dfs(int v, int c, int cmp)
    {
        col[v] = c;
        if (col[v] == 0)
            ++cnt0;
        else
            ++cnt1;
        comp[v] = cmp;
        for (auto [to, change] : g[v])
        {
            if (col[to] == -1)
            {
                dfs(to, c ^ change, cmp);
            }
        }
    }

  public:
    void solve()
    {

        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n));
        vector<vector<int>> pos(n);
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> a[i][j];
                --a[i][j];
                pos[a[i][j]].push_back(j);
            }
        }
        bool bad = false;
        g = vector<vector<pair<int, int>>>(n);
        for (int i = 0; i < n; ++i)
        {
            if (pos[i].size() != 2)
            {
                bad = true;
                break;
            }
            int c1 = pos[i][0], c2 = pos[i][1];
            if (c1 == c2)
                continue;
            int r1 = a[0][c1] != i, r2 = a[0][c2] != i;
            g[c1].push_back({c2, r1 == r2});
            g[c2].push_back({c1, r1 == r2});
        }
        col = vector<int>(n, -1);
        comp = vector<int>(n, -1);
        int cnt = 0;
        vector<pair<int, int>> colcnt;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (col[i] == -1)
            {
                cnt0 = cnt1 = 0;
                dfs(i, 0, cnt);
                ++cnt;
                colcnt.push_back({cnt0, cnt1});
                ans += min(cnt0, cnt1);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (auto [j, diff] : g[i])
            {
                if ((col[i] ^ col[j]) != diff)
                {
                    bad = true;
                }
            }
        }
        if (bad)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << ans << '\n';
            for (int i = 0; i < n; ++i)
            {
                int changeZero = colcnt[comp[i]].first < colcnt[comp[i]].second;
                if (col[i] ^ changeZero)
                {
                    cout << i + 1 << " ";
                }
            }
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385G_ColumnsSwaps.in", "r", stdin);
    //freopen("ac2.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solution sln1;
        sln1.solve();
        cout.flush();
    }



    return 0;
}
