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

const int inf = INT_MAX / 2;

class solution
{
  public:

    void _not(string &s)
    {
        for (auto &ch:s) ch = (ch == '0') ? '1' : '0';
        while (s.size() > 1)
        {
            if (s[0] == '0')
                s.erase(s.begin());
            else break;
        }
    }

    bool isPreF(string pre, string s)
    {
        return (s.substr(0, pre.size()) == pre);
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            string ss, se; cin >> ss >> se;

            if (se.size() == 1)
            {
                cout << '\n'; continue;
            }
            
            int iniCntNot = 0, ans = INT_MAX / 2;
            string tmp = ss;
            while (true)
            {
                bool flg = (tmp == "0");
                if (isPreF(tmp, se))
                {
                    int sizE = se.size(), cntGroup = (int)(sizE > tmp.size());
                    for (int i = tmp.size() + 1; i <= sizE - 1; ++i)
                        if (se[i] != se[i - 1]) ++cntGroup;
                    if (se.back() == '0') --cntGroup;

                    if (iniCntNot >= cntGroup)
                    {
                        ans = min(ans, iniCntNot + sizE - (int)tmp.size());
                        if (tmp == "1") break;
                    }
                }

                _not(tmp);
                ++iniCntNot;

                if (flg && se[1] == '0') break;
            }

            cout << "Case #" << tcc << ": ";
            if (ans == inf)
                cout << "IMPOSSIBLE\n";
            else
                cout << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C1.in", "r", stdin);
    freopen("C1.out", "w", stdout);
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