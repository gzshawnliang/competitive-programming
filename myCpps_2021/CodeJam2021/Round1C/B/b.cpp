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

    void add1(string &s)
    {
        int siz = s.size();
        bool flg = true;
        for (int i = siz - 1; i >= 0; --i)
        {
            if (flg == true)
            {
                if (s[i] == '9')
                {
                    s[i] = '0';
                }
                else
                {
                    ++s[i];
                    return;
                }
            }
        }

        if (flg) s = "1" + s;
    }

    bool isSmaller(const string & x, const string & y)
    {
        if(x.length() > y.length())
        {
            return false;
        }
        else if(x.length() == y.length())
        {
            for (int len = 0, siz = x.length(); len <= siz - 1; ++len){
                if(x[len] > y[len])
                    return false;
                else if (x[len] < y[len])
                    return true;
            }
            return false;
        }
        else
        {
            return true;
        }
    }

    string getRY(string &s)
    {
        if (stoll(s) <= 12)
        {
            return "12";
        }

        ill sizS = s.size();
        string ans = "9999999999999999999999999999";
        for (ill ns = 1; ns <= sizS / 2 + 1; ++ns)
        {
            string tmp = s.substr(0, ns);
            string res = "";
            while (isSmaller(res, s))
            {
                res += tmp;
                add1(tmp);
            }
            if (isSmaller(res, ans))
                ans = res;

            tmp = s.substr(0, ns);
            add1(tmp);
            res = "";
            while (isSmaller(res, s))
            {
                res += tmp;
                add1(tmp);
            }
            if (isSmaller(res, ans))
                ans = res;

            tmp = "1";
            for (int c = 1; c <= ns - 1; ++c) tmp += "0";
            res = "";
            while (isSmaller(res, s))
            {
                res += tmp;
                add1(tmp);
            }
            if (isSmaller(res, ans))
                ans = res;
        }

        return ans;
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            string s; cin >> s;

            add1(s);
            string ans = getRY(s); 

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
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