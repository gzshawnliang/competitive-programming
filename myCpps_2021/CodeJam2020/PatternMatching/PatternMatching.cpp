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
    bool contain(string &a, string &b)
    {
        if (b == "") return true;

        int sizA = a.size(), sizB = b.size();
        if (sizA < sizB) return false;

        int i = 0;
        while (i <= sizA - 1)
        {
            int p = 0;
            while (p <= sizB - 1)
            {
                if (a[i + p] != b[p])
                {
                    break;
                }
                ++p;
            }

            if (p == sizB) return true;

            i += max(p, 1);
        }
        return false;
    }

    bool containF(string &a, string &b)
    {
        if (b == "") return true;

        int sizA = a.size(), sizB = b.size();
        if (sizA < sizB) return false;

        for (int i = 0; i <= sizB - 1; ++i)
        {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool containL(string &a, string &b)
    {
        if (b == "") return true;

        int sizA = a.size(), sizB = b.size();
        if (sizA < sizB) return false;

        for (int i = 0; i <= sizB - 1; ++i)
        {
            if (a[sizA - i - 1] != b[sizB - i - 1]) return false;
        }
        return true;
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            string pre = "", suf = "";
            vector<string> allS(n);
            bool flg = true;
            for (int j = 0; j <= n - 1; ++j)
            {
                string s; cin >> s;
                int siz = s.size(), posP = siz - 1;
                string tmpP = "";
                for (int i = 0; i <= siz - 1; ++i)
                {
                    if (s[i] == '*')
                    {
                        posP = i; break;
                    }
                    tmpP += s[i];
                }

                int posS = 0;
                string tmpS = "";
                for (int i = siz - 1; i >= 0; --i)
                {
                    if (s[i] == '*')
                    {
                        posS = i; break;
                    }
                    tmpS = s[i] + tmpS;
                }

                string tmpB = "";
                for (int i = posP; i <= posS; ++i)
                    if (s[i] != '*') tmpB += s[i];
                allS[j] = tmpB;
                
                if (tmpP.size() > pre.size())
                {
                    if (containF(tmpP, pre)) pre = tmpP;
                    else                    flg = false;
                }
                else
                {
                    if (containF(pre, tmpP) == false) flg = false;
                }

                if (tmpS.size() > suf.size())
                {
                    if (containL(tmpS, suf)) suf = tmpS;
                    else                    flg = false;
                }
                else
                {
                    if (containL(suf, tmpS) == false) flg = false;
                }
            }

            cout << "Case #" << tcc << ": ";
            if (flg)
            {
                cout << pre;
                for (string s:allS) cout << s;
                cout << suf << '\n';
            }
            else
            {
                cout << "*\n";
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PatternMatching.in", "r", stdin);
    freopen("PatternMatching.out", "w", stdout);
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