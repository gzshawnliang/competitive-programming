#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

struct Cmp
{
    bool operator ()(const pair<unsigned int, double> &a, const pair<unsigned int, double> &b) const
    {
        return a.second < b.second;
    }
};

class solution
{

    
  public:
    void solve()
    {
        //set <pair<unsigned int, double>, Cmp> your_set;
        set<pair<int,int>> sp
        {
            {42, 0}, {42, 1}, {43, 3}, {43, 4}
        };        
        auto it = sp.lower_bound({43, INT_MIN});
        --it;
        return;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("SETPAIR.in", "r", stdin);
    freopen("SETPAIR.out", "w", stdout);
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