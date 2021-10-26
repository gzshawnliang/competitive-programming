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
        string s;
        cin >> s;
        int len = s.length();
        map<char, int> m;
        int last = 0;

        for (int i = 0; i <= len - 1; ++i)
        {
            if (m.count(s[i]) == 0)
            {
                m[s[i]] = last;
                ++last;
            }
        }
        int n=m.size();
        vector<vector<int>> occ(n, vector<int>(n, 0));

        for (int i = 1; i <= len - 1; ++i)
        {
            char c1=s[i-1];
            char c2=s[i];
            ++occ[m[c1]][m[c2]];
        }

        int result = INT32_MAX;

        vector<int> v2;
        for (int i = 0; i <= n - 1; ++i)
            v2.push_back(i);

        do 
        {
            int ans = 0;
            for (int i = 0; i <= n - 1; ++i)
            {
                for (int j = 0; j <= i; ++j)
                {
                    if(occ[v2[i]][v2[j]]>0)
                        ans += occ[v2[i]][v2[j]];
                }
            }
            //cerr << ans << "\n";
            result = min(result, ans);
        }
        while ((next_permutation(v2.begin(), v2.end())));

        
        cout << result + 1 << "\n";
        return;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
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