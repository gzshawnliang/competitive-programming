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
        int N=1000;
        for (int x = 0; x <= N-1; ++x)
        {
            for (int y = 0; y <= N-1; ++y)
            {
                int k=0;
                int r=1;
                bool tag=false;
                while (r<=N)
                {
                    int xR=(x / r) % 3;
                    int yR=(y / r) % 3;
                    r = r*3;

                    if(xR == yR)
                    {
                        continue;
                    }
                    else if(xR % 2 == 0 && yR % 2 == 0)
                    {
                        continue;
                    }
                    else 
                    {
                        tag=true;
                        break;
                    }
                }
                if(tag)
                    cout<<' ';
                else 
                    cout<<'x';
                
            }
            cout<<"\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    //freopen("counttheCows.in", "r", stdin);
    freopen("counttheCows.out", "w", stdout);
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