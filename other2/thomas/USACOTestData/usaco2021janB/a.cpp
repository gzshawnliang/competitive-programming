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
        string ord,s;
        cin>>ord >> s;
        vector<int> m(26);
        for (int i = 0,len=ord.length(); i <= len - 1; ++i)
        {
            m[ord[i]-'a']=i;
        }
        int ans=0;
        for (int i = 1, len = s.length(); i <= len - 1; ++i)
        {
            int b = s[i] - 'a';
            int a = s[i - 1] - 'a';
            if (m[b] <= m[a])
                ++ans;
        }
        cout << ans + 1 << "\n";
        return;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
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