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
        int n;cin>>n;
        vector<int> cow(n);
        for(auto &temp:cow)
        {
            cin>>temp;
        }
        stack<pair<int,int>> h;
        ill ans=0;
        h.push({cow[0],0});
        for(int i=1;i<n;++i)
        {
            while(!h.empty())
            {
                if(h.top().first<cow[i])
                {
                    ans+=i-h.top().second+1;
                    h.pop();
                }
                else
                    break;
            }
            if(!h.empty()) 
                ans+=i-h.top().second+1;
            h.push({cow[i],i});
        }
        cout<<ans<<'\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CowFrisbee.in", "r", stdin);
    freopen("CowFrisbee.out", "w", stdout);
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