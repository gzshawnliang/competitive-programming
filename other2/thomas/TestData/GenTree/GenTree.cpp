#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

#include "MyRandom.h"
#include "treegenerator.h"

using namespace std;
using namespace tree_generator_by_ouuan;

using ill = long long;

class solution
{

  public:

    void solve()
    {
        // Tree t(9);
        // Tree t(9)t.random(1,1);
        // cout << t << '\n';    
        int t=5;
        random rdNum;              //note:随机数
        cout << t << "\n";
        while (t--)
        {
            int N =rdNum.GetRand(2, 8);
            cout << N << "\n";
            Tree tree(N);
            //tree.random(1,1);
            cout << tree;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
#ifndef ONLINE_JUDGE
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
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