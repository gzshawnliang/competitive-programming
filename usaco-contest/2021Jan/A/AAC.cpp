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
        string s; cin >> s;

        int siz = s.size(), ansF = siz;
        //vector<int> num(256, -1);
        for (int st = 0; st <= siz - 1; ++st)
        {
            if (st == 2)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            int cnt = 0, ans = 0;
            map<char, int> num;
            for (int i = st; i <= siz - 1; ++i)
            {
                if (num[s[i]] == 0)
                {
                    num[s[i]] = cnt++;
                }

                if (i > 0)
                {
                    if (num[s[i - 1]] >= num[s[i]])
                    {
                        ++ans;
                    }
                }
            }
            if (st < siz - 1) ++ans;
            for (int i = 0; i <= st - 1; ++i)
            {
                if (num.count(s[i]) == 0)
                {
                    num[s[i]] = cnt++;
                }

                if (i > 0)
                {
                    if (num[s[i - 1]] >= num[s[i]])
                    {
                        ++ans;
                    }
                }
            }
            if (st > 0) ++ans;

            ansF = min(ansF, ans);
        }

        cout << ansF << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
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