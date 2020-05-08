/*
===========================================================
* @Name:           100735H Words from cubes
* @Author:         Shawn
* @create Time:    2020/5/7 22:30:04
* @url:            https://codeforces.com/problemset/gymProblem/100735/H?mobile=false&locale=en
* @Description:    二分图|匈牙利算法
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const int totS = 6;

bool dfs(int i, vector<int> &match, vector<int> &icp, vector<vector<int>> &g)
{
    for (auto j:g[i])
    {
        if (icp[j] == false)
        {
            icp[j] = true;
            if (match[j] == -1 || dfs(match[j], match, icp, g) == true)
            {
                match[j] = i;
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    string s; int m;
    cin >> s >> m;
    int n = s.size();

    vector<vector<int>> g(n);
    for (int u = 0; u <= n - 1; ++u)
    {
        for (int c = 1; c <= totS; ++c)
        {
            char ch; cin >> ch;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (s[i] == ch)
                {
                    g[i].push_back(u);
                }
            }
        }
    }

        int ans = 0;
        vector<int> match(n + m + 1, -1);
    for (int i = 0; i <= n - 1; ++i)
    {
            vector<int> icp(n + m + 1, 0);
        if (dfs(i, match, icp, g) == true)
        {
            ++ans;
        }
    }

    if (ans == n) cout << "YES\n";
    else          cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_100735H_Wordsfromcubes.in", "r", stdin);
        freopen("CF_100735H_Wordsfromcubes.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}