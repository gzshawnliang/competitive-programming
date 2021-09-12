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
    const ill MOD = 1e9 + 7;

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; string s; cin >> n >> s;

            string tmpS = s;
            for (int i = n - 1; i >= 0; --i)
            {
                if (tmpS[i] == 'F' && i < n - 1)
                {
                    tmpS[i] = tmpS[i + 1];
                }
            }

            char lstTmpA = tmpS[0];
            vector<int> tmpA = {0};
            for (int i = 0; i <= n - 1; ++i)
            {
                if (lstTmpA == tmpS[i]) ++tmpA.back();
                else
                {
                    tmpA.push_back(1); lstTmpA = tmpS[i];
                }
            }

            ill ans = 0LL;
            int indexTmpA = 0;
            vector<int> a = {0};
            
            auto calRes=[&]()
            {
                ill res = 0;
                for (int j = 0, sizA = a.size(); j <= sizA - 1; ++j)
                    res = (res + ((ill)(sizA - 1 - j) * (ill)a[j]) % MOD) % MOD;
                return res % MOD;
            };

            ill lstCal = 0LL, nowCal = 0LL;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (a.back() < tmpA[indexTmpA]) ++a.back();
                else
                {
                    if (indexTmpA + 1 == (int)tmpA.size() - 1 && tmpS.back() == 'F')
                    {
                        //ans += ((ill)calRes() * (ill)tmpA.back()) % MOD;
                        ans = (ans + ((ill)calRes() * (ill)tmpA.back()) % MOD) % MOD;
                        break;
                    }
                    a.push_back(1); ++indexTmpA;
                    //nowCal = calRes();

                    nowCal = (lstCal + i) % MOD;
                }

                if (s[i] != 'F')
                {
                    ans = (ans + nowCal) % MOD;
                }
                else
                {
                    ans = (ans + lstCal) % MOD;
                }

                if (s[i] != 'F') lstCal = nowCal;
            }
            
            cout << "Case #" << tcc << ": " << ans % MOD << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("A2.in", "r", stdin);
    freopen("A2.txt", "w", stdout);
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