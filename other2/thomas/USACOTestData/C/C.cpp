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
    const int inf = INT_MAX / 2;

    void solve()
    {
        int n; cin >> n;
        //vector<int> allX, allY;
        vector<pair<int, int>> p(n);
        for (auto &[x, y] : p)
        {
            cin >> x >> y;
            //allX.push_back(x); allY.push_back(y);
        }
        //sort(allX.begin(), allX.end());
        //sort(allY.begin(), allY.end());

        int ans = 1;
        for (int xn = 1; xn <= (1 << n) - 1; ++xn)
        {
            bitset<21> b(xn);

            int maxX = 0, minX = inf, maxY = 0, minY = inf;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (b[i] == 1)
                {
                    maxX = max(maxX, p[i].first); minX = min(minX, p[i].first);
                    maxY = max(maxY, p[i].second); minY = min(minY, p[i].second);
                }
            }

            if (xn == 3)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            bool flg = true;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (b[i] == 0)
                {
                    int x = p[i].first, y = p[i].second;
                    if (minX < x && x < maxX && minY < y && y < maxY)
                    {
                        flg = false;
                        break;
                    }
                }
            }
            if (flg == false) continue;
            
            if (maxX - minX >= maxY - minY)
            {
                int NMaxY = 0, NMinY = inf;
                for (int i = 0; i <= n - 1; ++i)
                {
                    if (b[i] == 0)
                    {
                        int x = p[i].first, y = p[i].second;
                        if (minX < x && x < maxX)
                        {
                            NMaxY = max(NMaxY, y); NMinY = min(NMinY, y);
                        }
                    }
                }

                if (maxX - minX >= NMaxY - NMinY && NMinY < minY && maxY < NMaxY) flg = false;
            }
            else
            {
                int NMaxX = 0, NMinX = inf;
                for (int i = 0; i <= n - 1; ++i)
                {
                    if (b[i] == 0)
                    {
                        int x = p[i].first, y = p[i].second;
                        if (minY < y && y < maxY)
                        {
                            NMaxX = max(NMaxX, x); NMinX = min(NMinX, x);
                        }
                    }
                }

                if (maxY - minY >= NMaxX - NMinX && NMinX < minX && maxX < NMaxX) flg = false;
            }

            if (flg)
            {
                for (int i = 0; i <= n - 1; ++i)
                {
                    if (b[i] == 1)
                    {
                        int x = p[i].first, y = p[i].second;
                        cout << "(" << x << ", " << y << ") ";
                    }
                }
                cout << '\n';
                ++ans;
            }
        }
        cout << ans << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}