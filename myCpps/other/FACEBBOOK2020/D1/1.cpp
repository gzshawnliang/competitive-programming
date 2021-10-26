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
    vector<int> a;
  public:

    void solve()
    {
        std::multiset<int> mymultiset;
        std::multiset<int>::iterator it;

        // insert some values:
        mymultiset.insert(40); // 40
        for (int i = 1; i < 7; i++)
            mymultiset.insert(i * 10); // 10 20 30 40 40 50 60

        //it = mymultiset.begin();
        //it++; //    ^

        //mymultiset.erase(it); // 10 30 40 40 50 60

        //ymultiset.erase(40); // 10 30 50 60

        it = mymultiset.find(40);
        mymultiset.erase(it); 

        std::cout << "mymultiset contains:";
        for (it = mymultiset.begin(); it != mymultiset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}