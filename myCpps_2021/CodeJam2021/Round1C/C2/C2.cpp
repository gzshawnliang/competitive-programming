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

    void _double(string &s, int times)
    {
        if (s == "0") return;
        for (int c = 1; c <= times; ++c) s += '0';
    }

    bool isPreF(string pre, string s)
    {
        return (s.substr(0, pre.size()) == pre);
    }

    vector<int> getGroup(string s)
    {
        int mcnt = 1;
        vector<int> ans;
        for (int i = 1, siz = s.size(); i <= siz; ++i)
        {
            if (i == siz) ans.push_back(mcnt);
            else if (s[i] == s[i - 1]) ++mcnt;
            else
            {
                ans.push_back(mcnt);
                mcnt = 1;
            }
        }
        return ans;
    }

    int getAns(bool execNot, string suf, string ss, string se, int tcc)
    {
        vector<int> vsuf = getGroup(suf);

        int sttPos = 0, res = 0, sizVsuf = vsuf.size();
        if (execNot)
        {
            _not(ss); ++res;
        }
        else if (sizVsuf > 0)
        {
            int tmpT = vsuf[sttPos++];
            _double(ss, tmpT);
            res += tmpT;
        }

        for (int i = sttPos; i <= sizVsuf - 1; ++i)
        {
            if (i > 0)
            {
                _not(ss); ++res;
            }

            _double(ss, vsuf[i]);
            res += vsuf[i];
        }

        while (ss.size() > se.size()) 
        {
            _not(ss); ++res;
        }

        if (ss == se) return res;
        else           return inf;
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            string ss, se; cin >> ss >> se;
            vector<int> vs = getGroup(ss), ve = getGroup(se);

            int ans = inf;
            if (ss == se) 
            {
                ans = 0;
            }
            else if (se == "0")
            {
                ans = vs.size();
            }
            else if (ss == "0" && se == "1")
            {
                ans = 1;
            }
            else if (ss == "0" && ve.size() > 2)
            {
                ans = inf;
            }
            else
            {
                string tmp = ss;
                for (int c = 0, sizVs = vs.size(); c <= sizVs + 1; ++c)
                {
                    if (isPreF(tmp, se))
                    {
                        string suf = se.substr(tmp.length(), se.length() - tmp.length());
                        ans = min(ans, getAns(true, suf, ss, se, tcc));
                        ans = min(ans, getAns(false, suf, ss, se, tcc));
                    }
                    else if (tmp == "0")
                    {
                        string suf = se;
                        ans = min(ans, getAns(true, suf, ss, se, tcc));
                        ans = min(ans, getAns(false, suf, ss, se, tcc));
                    }
                    _not(tmp);
                }
            }

            cout << "Case #" << tcc << ": " << ((ans == inf) ? "IMPOSSIBLE" : to_string(ans)) << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C2.in", "r", stdin);
    freopen("C2.out", "w", stdout);
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