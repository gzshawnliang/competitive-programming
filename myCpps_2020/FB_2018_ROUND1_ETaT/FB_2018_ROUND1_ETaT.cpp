/*
-------------------------------------------------------------------
* @Name:           Problem B: Ethan Traverses a Tree
* @Author:         Shawn
* @Create Time:    2020/8/3 23:07:39  (UTC+08:00)
* @Url:            https://www.facebook.com/codingcompetitions/hacker-cup/2018/round-1/problems/B
* @Description:    dfs
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/

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
    vector<int> pre, post, L, R, f;

    void dfsPre(int u)
    {
        if (u == 0) return;

        pre.push_back(u);
        dfsPre(L[u]);
        dfsPre(R[u]);
    }

    void dfsPost(int u)
    {
        if (u == 0) return;

        dfsPost(L[u]);
        dfsPost(R[u]);
        post.push_back(u);
    }

    int fndF(int u)
    {
        if (f[u] == u) return u;
        else              return f[u] = fndF(f[u]);
    }

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, k; cin >> n >> k;

            vector<int> isRoot(n + 1, 1);
            L = vector<int>(n + 1, 0);
            R = vector<int>(n + 1, 0);
            for (int u = 1; u <= n; ++u)
            {
                cin >> L[u] >> R[u];
                isRoot[L[u]] = 0; isRoot[R[u]] = 0;
            }

            int root = 0;
            for (int u = 1; u <= n && root == 0; ++u)
                if (isRoot[u]) root = u;

            pre.clear();
            dfsPre(root);
            post.clear();
            dfsPost(root);

            f = vector<int>(n + 1, 0);
            for (int u = 1; u <= n; ++u) f[u] = u;

            int tolF = 0;
            vector<int> isFree(n + 1, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                if (pre[i] == post[i])
                {
                    isFree[pre[i]] = 1;
                    ++tolF;
                }
                else f[fndF(pre[i])] = fndF(post[i]);
            }

            int nowC = 1;
            vector<int> col(n + 1, -1);
            //vector<vector<int>> a;
            for (int u = 1; u <= n; ++u)
            {
                if (isFree[u] == 1)
                {
                    col[u] = 0;
                    continue;
                }

                int Fnu = fndF(u);

                //bool flg = false;
                if (col[Fnu] == -1)
                {
                    col[Fnu] = nowC;
                    ++nowC;

                    //flg = true;
                }
                col[u] = col[Fnu];

                // if (flg)
                // {
                //     vector<int> tmp = {u};
                //     a.push_back(tmp);
                // }
                // else
                // {
                //     a[col[u]].push_back(u);
                // }
            }

            // vector<int> vis(k + 1, 0);
            // for (int u = 1; u <= n; ++u)
            //     if (isFree[u] == 0) vis[col[u]] = 1;

            cout << "Case #" << tcc << ':';
            if (nowC - 1 + tolF < k)
            {
                cout << " Impossible\n";
            }
            else
            {
                int i = nowC;
                for (int u = 1; u <= n; ++u)
                {
                    int out = 0;
                    if (isFree[u])
                    {
                        if (i > k) out = 1;
                        else       out = i++;
                    }
                    else
                    {
                        out = min(col[u], k);
                    }

                    cout << ' ' << out;
                }
                cout << '\n';
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("FB_2018_ROUND1_ETaT.in", "r", stdin);
    freopen("FB_2018_ROUND1_ETaT.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}