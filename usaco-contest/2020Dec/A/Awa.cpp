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
    const int inf = INT_MAX / 2;
    int n;
    vector<vector<int>> a;
    vector<vector<int>> fa;

    bool good(int y, int x)
    {
        return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
    }

    bool check(int y, int x, int re)
    {
        if (re == 0)
        {
            return a[y][x] != -1;
        }
        else
        {
            for (int c = 0; c <= re; ++c)
            {
                if (!good(y + c, x - re + c)) return false;
                if (!good(y - c, x - re + c)) return false;
                if (a[y + c][x - re + c] == -1) return false;
                if (a[y - c][x - re + c] == -1) return false;
            }

            for (int c = re - 1; c >= 0; --c)
            {
                if (!good(y + c, x + re - c)) return false;
                if (!good(y - c, x + re - c)) return false;
                if (a[y + c][x + re - c] == -1) return false;
                if (a[y - c][x + re - c] == -1) return false;
            }

            return check(y, x, re - 1);
        }
    }

    void fill(int y, int x, int re)
    {
        if (re == 0)
        {
            fa[y][x] = 1;
        }
        else
        {
            for (int c = 0; c <= re; ++c)
            {
                if (!good(y + c, x - re + c)) return;
                if (!good(y - c, x - re + c)) return;
                fa[y + c][x - re + c] = 1;
                fa[y - c][x - re + c] = 1;
            }

            for (int c = re - 1; c >= 0; --c)
            {
                if (!good(y + c, x + re - c)) return;
                if (!good(y - c, x + re - c)) return;
                fa[y + c][x + re - c] = 1;
                fa[y - c][x + re - c] = 1;
            }

            return fill(y, x, re - 1);
        }
    }

  public:
    void solve()
    {
        vector<int> dy = {0, -1, 0, 1},
                    dx = {1, 0, -1, 0};

        int k; cin >> n >> k;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        a = vector<vector<int>>(n, vector<int>(n, 0));
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                char ch; cin >> ch;

                if (ch == 'S')
                {
                    q.push({0, {y, x}});
                    a[y][x] = 0;
                }
                else if (ch == '.')
                    a[y][x] = inf;
                else
                    a[y][x] = -1;
            }
        }

        while (!q.empty())
        {
            pair<int, pair<int, int>> now = q.top(); q.pop();
            int y = now.second.first, x = now.second.second;

            //if (a[y][x] < now.first) continue;

            for (int p = 0; p <= 3; ++p)
            {
                int ty = y + dy[p], tx = x + dx[p];
                if (a[ty][tx] != -1 && a[ty][tx] > now.first + 1)
                {
                    a[ty][tx] = now.first + 1;
                    q.push({now.first + 1, {ty, tx}});
                }
            }
        }

        fa = vector<vector<int>>(n, vector<int>(n, 0));
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                if (a[y][x] != -1 && a[y][x] != inf)
                {
                    if (check(y, x, max(0, a[y][x] - 1) / k))
                    {
                        fill(y, x, max(0, a[y][x] - 1) / k);
                    }

                    if (a[y][x] % k == 0)
                    {
                        if (check(y, x, a[y][x] / k))
                        {
                            fill(y, x, a[y][x] / k);
                        }
                    }
                }
            }
        }

        // for (int y = 0; y <= n - 1; ++y)
        // {
        //     for (int x = 0; x <= n - 1; ++x)
        //     {
        //         if (a[y][x] == -1)
        //             cout << '#';
        //         else if (a[y][x] == inf)
        //             cout << "x";
        //         else
        //             cout << a[y][x];
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for (int y = 0; y <= n - 1; ++y)
        // {
        //     for (int x = 0; x <= n - 1; ++x)
        //     {
        //         if (a[y][x] == -1)
        //             cout << '#';
        //         else if (fa[y][x] == 1)
        //             cout << "x";
        //         else
        //             cout << ' ';
        //     }
        //     cout << '\n';
        // }

        int ans = 0;
        for (int y = 0; y <= n - 1; ++y)
            for (int x = 0; x <= n - 1; ++x)
                ans += fa[y][x];
        cout << ans << '\n';

    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
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