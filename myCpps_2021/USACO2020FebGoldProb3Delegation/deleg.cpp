#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
  public:
  
    const int root = 1;
    int n;

    vector<vector<int>> g;
    vector<vector<int>> cntTre;

    int dfs(int u, int las)
    {
        int ans = 0;
        for (int v:g[u])
        {
            if (v == las) continue;

            int tmp = dfs(v, u);
            ans += (tmp + 1);
            cntTre[u].push_back(tmp + 1);
        }

        cntTre[u].push_back(n - 1 - ans);

        return ans;
    }

    void solve()
    {
        cin >> n;

        g = vector<vector<int>>(n + 1);
        for (int c = 1; c <= n - 1; ++c)
        {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        cntTre = vector<vector<int>>(n + 1);
        dfs(root, 0);

        for (int k = 1; k <= n - 1; ++k)
        {
            if ((n - 1) % k > 0)
            {
                cout << 0;
                continue;
            }
            else if (k == 1)
            {
                cout << 1;
                continue;
            }

            int ind = -1;
            bool flg = true;
            vector<int> cntF(k, 0);
            for (auto &tre : cntTre)
            {
                ++ind;

                set<int> allPos;
                for (auto x:tre)
                {
                    ++cntF[x % k];
                    allPos.insert(x % k);
                }

                for (auto x:allPos)
                {
                    if (x == 0) continue;
                    if (cntF[x] != cntF[k - x])
                    {
                        flg = false;
                        cntF[x] = 0; cntF[k - x] = 0;
                        //break;
                    }
                }
                if (flg == false) break;
            }
            cout << flg;
        }

        cout << '\n';
    }
};

signed main()
{
    FastIO;

//#ifdef LOCAL_DEBUG
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    //auto startTime = chrono::high_resolution_clock::now();
//#endif

    solution sln1;
    sln1.solve();
    cout.flush();

// #ifdef LOCAL_DEBUG
//     cerr << "Execution time: "
//          << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
//          << " ms\n";
// #endif

    return 0;
}