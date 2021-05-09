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

using ull = unsigned long long;

class solution
{
  public:
    void solve()
    {
        vector<ull> merge3Plus;
        for (int i = 1; i <= 999998; ++i)
        {
            string s=to_string(i);
            int j = i;
            while (s.length() <= 19)
            {
                if (j >= i + 2 && s.length() <= 19)
                {
                    merge3Plus.push_back(stoull(s));
                }
                ++j;
                s += to_string(j);
            }
        }
        sort(merge3Plus.begin(), merge3Plus.end());

        auto merge2=[](ull x)
        {
            string s=to_string(x) + to_string(x+1);
            return stoull(s);
        };


        int T;
        cin >> T;
        for (int cat = 1; cat <= T; ++cat)
        {
            ull Y;
            cin >> Y;
            if(Y<12)
            {
                cout << "Case #" << cat << ": 12\n";
                continue;
            }

            ull ans1 = *lower_bound(merge3Plus.begin(), merge3Plus.end(), Y+1);

            ull l=1,r=999999999;
            while (r-l>1)
            {
                ull m =(l+r)/2;
                ull ret = merge2(m);
                if(ret>Y)
                    r=m;
                else if(ret<=Y)
                    l=m;
            }
            ull ans2 = merge2(r);

            cout << "Case #" << cat << ": " << min(ans1,ans2) << "\n";
        }
        return;

    }
    void solve_Set1()
    {
        vector<ull> mergeAll;
        for (int i = 1; i <= 998; ++i)
        {
            int j = i;
            ++j;
            string s = to_string(i) + to_string(j);
            while (s.length() <= 7)
            {
                mergeAll.push_back(stoll(s));
                ++j;
                s += to_string(j);
            }
        }

        sort(mergeAll.begin(), mergeAll.end());
        
        int T;
        cin >> T;
        for (int cat = 1; cat <= T; ++cat)
        {
            ull Y;
            cin >> Y;
            ull ans = *lower_bound(mergeAll.begin(), mergeAll.end(), Y+1);

            cout << "Case #" << cat << ": " << ans << "\n";
        }
        return;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
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