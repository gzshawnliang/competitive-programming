/*
-------------------------------------------------------------------
* @Name:           Problem B: Class Treasurer
* @Author:         Shawn
* @Create Time:    2020/8/11 21:44:33  (UTC+08:00)
* @Url:            https://www.facebook.com/codingcompetitions/hacker-cup/2019/round-1/problems/B
* @Description:    Facebook Hacker Cup 2019 Round 1
-------------------------------------------------------------------
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const int mod =1000000007;

class solution
{
    vector<ill> pow2;
  public:

    void initPow2()
    {
        pow2=vector<ill>(1000000+1);
        pow2[0]=1;
        for (int i = 1; i <= 1000000 ; ++i)
        {
            pow2[i]=(pow2[i-1]*1LL % mod + pow2[i-1]*1LL % mod ) % mod ;
        }

    }

    void solve(int t)
    {
        int N,K;
        cin >> N >> K;
        
        vector<char> a(N+1);
        cin.get();
        for (int i = 1; i <= N; ++i)
            cin.get(a[i]);
        // string c;
        // cin >> c;
        // string a=' '+c;

        vector<int> pay;
        int d=0;
        for (int i = N; i >= 1; --i)
        {
            if(a[i]=='A')
            {
                --d;
                d=max(0,d);
            }
            else 
            {
                ++d;
            }
            
            if(d>K)
            {
                pay.push_back(i);
                --d;
                --d;
                d=max(0,d);
            }
        }

        ill ans = 0;
        for (int i = 0, len = pay.size(); i <= len - 1; ++i)
        {
            ans = (ans % mod + pow2[pay[i]] % mod) % mod;
        }
        cout << "Case #" << t << ": " << ans << "\n";
        return;

    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("class_treasurer.in", "r", stdin);
    freopen("FB_2019_ROUND_1_BClassTreasurer.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif
    
    int t;
    cin >> t;
    solution sln1;
    sln1.initPow2();
    for (int i = 1; i <= t ; ++i)
        sln1.solve(i);

    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}