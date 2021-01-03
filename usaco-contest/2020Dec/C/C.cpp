#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{
  public:

    const int inf = INT_MAX / 2;
    vector<pair<int, int>> a;

    int getR()
    {
        int n = a.size(), ans = 0;

        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n - 1; ++j)
            {
                int l = abs(a[i].second - a[j].second) + 1,
                    nowX = a[j].first - l + 1;

                vector<pair<int, int>> tmp;
                for (auto pr:a)
                    if (pr.second >= min(a[i].second, a[j].second) && pr.second <= max(a[i].second, a[j].second))
                        tmp.push_back(pr);
                int sizT = tmp.size();

                if (nowX > a[i].first) break;

                if (i == 1 && j == 2)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }
                
                int res = 0;
                while (nowX <= a[i].first)
                {
                    ++res;
                    int posLx = upper_bound(tmp.begin(), tmp.end(), make_pair(nowX, 0)) - tmp.begin(),
                        posRx = upper_bound(tmp.begin(), tmp.end(), make_pair(nowX + l - 1, inf)) - tmp.begin();
                    
                    //int ld = tmp[posLx].first - nowX + 1;

                    int ld;
                    if (posLx == sizT) ld = inf;
                    else               ld = tmp[posLx].first - nowX + 1;

                    int rd;
                    if (posRx == sizT) rd = inf;
                    else               rd = tmp[posRx].first - (nowX + l - 1);

                    //if (ld > rd && posRx == sizT) break;

                    nowX += min(ld, rd);
                }

                //cout << i << " " << j << ": " << res << '\n';
                ans += res;
            }
        }

        return ans;
    }

    void solve()
    {
        int n; cin >> n;
        
        a = vector<pair<int, int>> (n);
        for (int i = 0; i <= n - 1; ++i)
            cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end());

        int ans = n;
        ans += getR();

        for (int i = 0; i <= n - 1; ++i)
            swap(a[i].first, a[i].second);
        sort(a.begin(), a.end());
        ans += getR();

        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}