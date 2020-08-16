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
    void solve()
    {
        cout << 1 << "\n";
        cout << (int)1e6 << " " << (int)1e6 << " " << 1 << "\n";

        int s=1;
        for (int i = 1; i <= (int)1e6 ; ++i)
        {
            cout << s << " ";
            s +=2;
        }
        cout << "\n";
        cout << "0 0 0" << " " << (int)5e8 << "\n";

        for (int i = 1; i <= (int)1e6 ; ++i)
        {
            cout << (int)5e8 << " ";
        }        
        cout << "0 0 0" << " " << (int)5e8 << "\n";
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("A2.in", "r", stdin);
    freopen("data.out", "w", stdout);
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