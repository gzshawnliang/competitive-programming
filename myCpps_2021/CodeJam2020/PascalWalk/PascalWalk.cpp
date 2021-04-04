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
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;

            int nowN = max(1, n - 32);
            bitset<32> b(nowN);
            vector<int> pos1;
            for (int i = 0; i <= 32 - 1; ++i)
                if (b[i] == 1)
                    pos1.push_back(i);

            int gap = 0;
            for (int i = 0, siz = pos1.size(); i <= siz - 1; ++i)
            {
                if (i == 0) gap += (pos1[i]);
                else        gap += (pos1[i] - pos1[i - 1] - 1);
            }

            int realN = nowN + gap;
            for (auto &x:pos1) ++x;

            cout << "Case #" << tcc << ":\n";
            int lasY = 0;
            bool leftSide = true;
            for (auto nowY:pos1)
            {
                if (leftSide)
                {
                    for (int y = lasY + 1; y <= nowY - 1; ++y)
                        cout << y << ' ' << 1 << '\n';
                    for (int x = 1; x <= nowY; ++x)
                        cout << nowY << ' ' << x << '\n';
                }
                else
                {
                    for (int y = lasY + 1; y <= nowY - 1; ++y)
                        cout << y << ' ' << y << '\n';
                    for (int x = nowY; x >= 1; --x)
                        cout << nowY << ' ' << x << '\n';
                }
                lasY = nowY;
                leftSide = !leftSide;
            }

            if (leftSide)
            {
                for (int c = 1; c <= n - realN; ++c)
                    cout << pos1.back() + c << ' ' << 1 << '\n';
            }
            else
            {
                for (int c = 1; c <= n - realN; ++c)
                    cout << pos1.back() + c << ' ' << pos1.back() + c << '\n';
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PascalWalk.in", "r", stdin);
    freopen("PascalWalk.out", "w", stdout);
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