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
        multiset<int> a;
        a.insert(10);
        a.insert(30);
        a.insert(20);
        a.insert(40);
        a.insert(20);
        a.insert(25);
        auto it = a.find(20);
        a.erase(it);

        std::priority_queue<int> mypq;
        mypq.push(10);
        mypq.push(20);
        mypq.push(15);
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // freopen("set.in", "r", stdin);
    // freopen("set.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chron
              o::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}