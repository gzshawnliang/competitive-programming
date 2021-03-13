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
            string s; cin >> s;

            int nowD = (s[0] - '0'), nowC = 1;
            vector<pair<int, int>> prs;
            for (int i = 1, sizS = s.size(); i <= sizS; ++i)
            {
                if (i == sizS)
                {
                    prs.push_back({nowD, nowC});
                    break;
                }

                int x = s[i] - '0';
                if (x == nowD)
                {
                    ++nowC;
                }
                else
                {
                    prs.push_back({nowD, nowC});
                    nowD = x; nowC = 1;
                }
            }

            string ans = "";
            for (auto [x, tol]:prs)
            {
                for (int c = 1; c <= x; ++c) ans += '(';
                ans += '_';
                for (int c = 1; c <= x; ++c) ans += ')';
            }

            for (int i = 0; i <= (int)ans.size() - 1; ++i)
            {
                if (i <= (int)ans.size() - 2)
                {
                    if (ans[i] == ')' && ans[i + 1] == '(')
                    {
                        ans.erase(ans.begin() + i); ans.erase(ans.begin() + i);
                        i -= 2;
                    }
                }
            }

            cout << "Case #" << tcc << ": ";
            int pos = 0;
            for (auto ch:ans)
            {
                if (ch == '_')
                {
                    for (int c = 1; c <= prs[pos].second; ++c)
                        cout << prs[pos].first;
                    ++pos;
                }
                else cout << ch;
            }
            cout << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("NestingDepth.in", "r", stdin);
    freopen("NestingDepth.out", "w", stdout);
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