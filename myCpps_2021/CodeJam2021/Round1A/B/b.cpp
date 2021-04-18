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
    const int N = 500;

    void solve()
    {
        vector<bool> isPrime(500, true);
        isPrime[0] = false, isPrime[1] = false;
        vector<int> allPrimes;
        
        for (int i = 2; i <= N; ++i)
        {
            if (isPrime[i] == true)
            {
                allPrimes.push_back(i);

                for (int j = i * i; j <= N; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            if (tcc == 6)
            {
                for(int _s_=0;_s_==0;++_s_);
            }

            int n; cin >> n;
            ill tolS = 0;
            vector<pair<ill, ill>> a(n);
            unordered_map<ill, ill> ump;
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i].first >> a[i].second;
                ump[a[i].first] = a[i].second;
                tolS += (a[i].first * a[i].second);
            }

            ill ans = 0;
            for (ill score = tolS; score >= max(tolS - 60LL * 499LL, 0LL); --score)
            {
                if (score == 40223)
                {
                    for(int _s_=0;_s_==0;++_s_);
                }

                bool flg = true;
                ill ts = score, nowS = 0;
                for (int i = 0, siz = allPrimes.size(); i <= siz - 1 && flg == true && ts > 1; ++i)
                {
                    ill tmpCnt = 0;
                    while (ts % allPrimes[i] == 0)
                    {
                        ts /= allPrimes[i];
                        nowS += allPrimes[i];
                        ++tmpCnt;

                        if (ump[allPrimes[i]] < tmpCnt)
                        {
                            flg = false;
                            break;
                        }
                    }
                }

                if (flg == true && ts == 1 && tolS - nowS == score)
                {
                    ans = score;
                    break;
                }
            }

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