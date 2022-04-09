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
        ill pw = 0;
        vector<ill> bb;
        for (ill x = 1; x <= 100; ++x)
        {
            if (x == (1LL << pw))
            {
                ++pw;
            }
            else bb.push_back(x);
        }

        vector<ill> b;
        for (int c = 0; c <= 36; ++c)
            b.push_back((ill)(1LL << c));

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;

            ill sum = 0LL;
            vector<ill> my;
            for (int c = 1; c <= n; ++c)
            {
                if (c > 1)   cout << ' ';
                if (c <= 30) my.push_back((ill)(1LL << (c - 1LL)));
                else         my.push_back((ill)bb[c - 31LL]);
                //else         my.push_back((ill)1e9 - (c - 31LL));
                cout << my.back();
                sum += my.back();
            }
            //cout << '\n';
            cout.flush();

            vector<ill> tmy = my;
            vector<ill> a(n);
            for (auto &x:a)
            {
                cin >> x;
                sum += x;
                tmy.push_back(x);
            }

            ill iniSum = sum;

            sum /= 2;

            vector<ill> _tmp;
            bool first = true;
            int __i = tmy.size() - 1;
            sort(tmy.begin(), tmy.end());

            
            while (sum > (ill)(1LL << 30LL) - 1LL && __i >= 0)
            {
                bool flg = true;
                for (auto x:b)
                {
                    if (tmy[__i] == x)
                    {
                        flg = false;
                        break;
                    }
                }

                if (flg == true)
                {
                    if (first) first = false;
                    else       cout << ' ';
                    cout << tmy[__i];
                    sum -= tmy[__i];
                    _tmp.push_back(tmy[__i]);
                }
                --__i;
            }

            
            int cnt1 = 0, i = 0;
            bitset<37> bs(sum);
            while (cnt1 < bs.count())
            {
                if (bs[i] == 1)
                {
                    if (first) first = false;
                    else       cout << ' ';
                    cout << (ill)(1LL << i);
                    _tmp.push_back((ill)(1LL << i));
                    ++cnt1;
                } 
                ++i;
                
            }
            
            // ill cntSum = 0LL;
            // for (auto x:_tmp) cntSum += x;
            // cerr << "\n\n" << cntSum * 2 << '\n' << iniSum  << '\n';

            cout.flush();
        }
    }
};

signed main()
{
    FastIO;

// #ifdef LOCAL_DEBUG
//     freopen("B.in", "r", stdin);
//     freopen("B.out", "w", stdout);
//     auto startTime = chrono::high_resolution_clock::now();
// #endif

    solution sln1;
    sln1.solve();
    cout.flush();

// #ifdef LOCAL_DEBUG
//     cerr << "Execution time: "
//          << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
//          << " ms\n";
// #endif

    return 0;
}