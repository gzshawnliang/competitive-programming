/*
===========================================================
 * @名称:		
 * @作者:		Shawn 
 * @创建时间: 2021-09-12 21:06:14 
 * @修改人:   Shawn 
 * @修改时间: 2021-09-12 21:06:14 
 * @备注:		
 * @题目来源： 
===========================================================
*/
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

    ill sum(string & s)
    {
        int n=s.length();

        char nowCh = '-'; ill ans = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            if (s[i] != nowCh)
            {
                if (s[i] != 'F')
                {
                    if (nowCh == '-') nowCh = s[i];
                    else
                    {
                        nowCh = s[i];
                        ++ans;
                    }
                }
            }
        }       
        return ans; 
    }

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; string s; cin >> n >> s;
            ill totalAns=0;

            for (int i = 0; i <= n - 1; ++i)
            {
                for (int j = i; j <= n - 1; ++j)
                {
                    string tmp = s.substr(i, j - i + 1);
                    totalAns = (totalAns + sum(tmp) % (ill)(1e9 + 7)) % (ill)(1e9 + 7);
                }
            }
            cout << "Case #" << tcc << ": " << totalAns % (ill)(1e9 + 7)  << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("A2.in", "r", stdin);
    freopen("A2.ok", "w", stdout);
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