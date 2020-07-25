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
    int col;
    string I, O;
    //vector<int> vis;
    vector<vector<int>> arr;
    
    void dfs(int u, int org)
    {
        int n = I.size();
        arr[org][u] = 1;

        if (O[u] == 'N') return;

        for (int v = u - 1; v <= u + 1; v += 2)
        {
            if (v >= 0 && v <= n - 1)
            {
                if (!arr[org][v] && I[v] == 'Y')
                {
                    dfs(v, org);
                }
            }
        }
    }

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            cin >> I >> O;

            arr.assign(n, vector<int>(n, 0));
            for (int u = 0; u <= n - 1; ++u)
            {
                //vis.assign(n, 0);
                dfs(u, u);
            }

            cout << "Case #" << tcc << ":\n";
            for (int u = 0; u <= n - 1; ++u)
            {
                for (int v = 0; v <= n - 1; ++v)
                    cout << ((arr[u][v]) ? 'Y':'N');
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
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
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