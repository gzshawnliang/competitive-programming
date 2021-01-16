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
    int ans, tolRep;
    const int inf = INT_MAX / 2;
    vector<pair<int, int>> a;

    void getTol()
    {
        int n = a.size();
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n - 1; ++j)
            {
                pair<int, int> p1 = a[i], p2 = a[j];
                    if (p1.first > p2.first) swap(p1, p2);
                int l = p2.first - p1.first + 1,
                    lowY = min(p1.second, p2.second),
                    higY = max(p1.second, p2.second);

                if (l < higY - lowY + 1) continue;

                map<int, int> mp;
                vector<pair<int, int>> allP;
                for (auto p:a)
                {
                    if (p1.first <= p.first && p.first <= p2.first)
                    {
                        allP.push_back(p);
                        mp[p.second] = 1;
                    }
                }

                sort(allP.begin(), allP.end(), [](pair<int, int> pa, pair<int, int> pb)
                {
                    return pa.second < pb.second;
                });

                int yd = -1, yu = -1, sizP = allP.size();
                for (int i = 0; i <= sizP - 1; ++i)
                {
                    if (yd == -1 && allP[i].second >= higY - l + 1) yd = i;
                    if (yu == -1 && allP[i].second >= higY)         yu = i;
                }
                
                int nowY = higY - l + 1;
                while (true)
                {
                    ++ans;
                    if (mp.count(nowY) > 0 && mp.count(nowY + l - 1) > 0) ++tolRep;
                    
                    int disRid = inf, disNew = inf;
                    if (allP[yd + 1].second <= lowY)
                        disRid = (allP[yd].second + 1 - nowY);
                    if (yu + 1 <= sizP - 1)
                        disNew = (allP[yu + 1].second - (nowY + l - 1));
                    
                    if (disRid < disNew)
                    {
                        nowY += disRid;
                        ++yd;
                    }
                    else if (disNew < disRid)
                    {
                        nowY += disNew;
                        if (nowY > lowY) break;

                        ++yu;
                    }
                    else
                    {
                        if (disNew == inf) break;
                        nowY += disRid;
                        ++yd; ++yu;
                    }
                }
            }
        }
    }

    void solve()
    {
        int n; cin >> n;
        a = vector<pair<int, int>>(n);
        for (int i = 0; i <= n - 1; ++i)
            cin >> a[i].first >> a[i].second;
        
        ans = 0; tolRep = 0;
        getTol();

        for (int i = 0; i <= n - 1; ++i)
            swap(a[i].first, a[i].second);
        getTol();

        cout << n + ans - tolRep / 2 + 1 << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
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