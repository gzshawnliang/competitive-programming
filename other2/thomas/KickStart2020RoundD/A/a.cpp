#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);               \
    std::cout.tie(NULL);

using namespace std;

using ill = long long;

class solution
{
  public:
    void solve(int caseId)
    {
        int N;
        cin >> N;
        vector<int> a(N + 1, -1);

        for (int i = 1; i <= N; ++i)
            cin >> a[i];

        int ans = 0;
        int previousMax = -1;
        for (int i = 1; i <= N ; ++i)
        {
            if(i==1 && i< N && a[1]>a[2])
                ++ans;
            else if (i == N && a[i] > previousMax)
                ++ans;
            else if(a[i]>previousMax && a[i]>a[i+1])
                ++ans;

            previousMax=max(previousMax,a[i]);

        }        

        cout << "Case #" << caseId << ": " << ans << "\n";
    }
};

signed main()
{
    FastIO

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    int t;
    cin >> t;
    solution sln1;
    for (int i = 1; i <= t; ++i)
    {
        sln1.solve(i);
    }
    cout.flush();

#ifdef LOCAL_DEBUG
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}