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
        int T;
        cin >> T;
        
        for(int t=1;t<=T;++t)
        {
            int ans= INT_MAX;
            int x,y;
            string s;
            cin >> x >> y >> s;
            int meTime=abs(x)+abs(y);
            int peppurrTime=0;
            if(meTime<=peppurrTime)
            {
                ans = peppurrTime;
            }
            else
            {
                for (int i = 0, len = s.length(); i <= len - 1; ++i)
                {
                    if(s[i]=='S')
                        --y;
                    else if(s[i]=='N')
                        ++y;
                    else if(s[i]=='E')
                        ++x;
                    else if(s[i]=='W')
                        --x;
                    
                    meTime=abs(x)+abs(y);
                    ++peppurrTime;
                    if(meTime<=peppurrTime)
                    {
                        ans = min(ans,peppurrTime);
                    }                    

                }
            }


            if(ans==INT_MAX)
                cout << "Case #"<< t<<": IMPOSSIBLE\n";
            else 
                cout << "Case #"<< t<<": "<< ans <<"\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("OverexcitedFan.in", "r", stdin);
    freopen("OverexcitedFan.out", "w", stdout);
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