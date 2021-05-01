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
    struct pr
    {
        ill x, y;
        bool operator < (const pr & tmp) const
        {
            if (x != tmp.x) return x < tmp.x;
            else            return y < tmp.y;
        }
    };

    pr _pr(ill x, ill y)
    {
        pr tmp{x, y}; return tmp;
    }

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            string s1, s2; cin >> s1 >> s2;
            
            int stN = 0, edN = 0;
            for (int i = 0, sizN = s1.size(); i <= sizN - 1; ++i)
                stN += (s1[sizN - 1 - i] - '0') * (1 << i);
            for (int i = 0, sizN = s2.size(); i <= sizN - 1; ++i)
                edN += (s2[sizN - 1 - i] - '0') * (1 << i);
            
            ill capN = (1 << 12);
            map<ill, ill> minD;
            priority_queue<pr> pq;
            pq.push(_pr(0, stN));
            while (!pq.empty())
            {
                pr nowPR = pq.top(); pq.pop();
                if (minD.count(nowPR.y) && minD[nowPR.y] <= nowPR.x) continue;
                minD[nowPR.y] = nowPR.x;

                ill newN = 0LL;
                bool flg = false;
                bitset<13> b(nowPR.y);
                for (int i = 12 - 1; i >= 0; --i)
                {
                    if (b[i] == 1)
                    {
                        flg = true;
                    }
                    else if (flg)
                    {
                        newN += (1 << i);
                    }
                }
                if (flg == false) ++newN;

                if (newN < capN)
                {
                    if (minD.count(newN) == 0)
                        pq.push(_pr(nowPR.x + 1, newN));
                    else if (minD[newN] > nowPR.x + 1)
                        pq.push(_pr(nowPR.x + 1, newN));
                }

                ill newN2 = nowPR.y * 2LL;
                if (newN2 < capN)
                {
                    if (minD.count(newN2) == 0)
                        pq.push(_pr(nowPR.x + 1, newN2));
                    else if (minD[newN2] > nowPR.x + 1)
                         pq.push(_pr(nowPR.x + 1, newN2));
                } 
            }

            cout << "Case #" << tcc << ": ";
            if (minD.count(edN) > 0)
            {
                cout << minD[edN] << '\n';
            }
            else
            {
                cout << "IMPOSSIBLE\n";
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
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