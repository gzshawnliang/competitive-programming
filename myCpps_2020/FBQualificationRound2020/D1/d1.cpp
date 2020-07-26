#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

class solution
{
    const ill inf = LLONG_MAX / 2;

  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, m; cin >> n >> m;

            vector<ill> a(n, 0);
            for (ill i = 0; i <= n - 1; ++i) cin >> a[i];

            multiset<ill> st; st.insert(0);
            vector<ill> f(n, inf); f[0] = 0;
            for (ill i = 1; i <= n - 1; ++i)
            {
                if (st.empty()) break;

                if (a[i] == 0 && i < n - 1)
                {
    
                }
                else
                {
                    f[i] = *st.begin();
                    if (i < n - 1) f[i] += a[i];
                    
                    st.insert(f[i]);
                }
                
                if (i >= m && f[i - m] != inf) 
                {
                    auto it=st.find(f[i - m]);
                    st.erase(it);
                }
            }

            cout << "Case #" << tcc << ": ";
            cout << ((f[n - 1] == inf) ? -1 : f[n - 1]) << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("d1.in", "r", stdin);
    freopen("d1.out", "w", stdout);
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