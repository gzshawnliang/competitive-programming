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

    void solve(int caseId)
    {
        
        int N,H,V;
        cin >> N >> H >> V;
        int x1, x2, y1, y2, ax, bx, cx, dx, ay, by, cy, dy;
        cin >> x1 >> x2 >> ax >> bx >> cx >> dx;
        cin >> y1 >> y2 >> ay >> by >> cy >> dy;

        if (N > H + V)
        {
            cout << "Case #" << caseId << ": -1" << "\n";
            return;
        }

        vector<tuple<int,int>> dot = vector<tuple<int, int>>(N + 1);
        dot[1] = {x1, y1};
        dot[2] = {x2, y2};
        for (int i = 3; i <= N; ++i)
        {
            auto [x2, y2] = dot[i - 2];
            auto [x1, y1] = dot[i - 1];

            int x = ((ax * x2 + bx * x1 + cx) % dx) + 1;
            int y = ((ay * y2 + by * y1 + cy) % dy) + 1;
            dot[i] = {x, y};
        }
        sort(dot.begin() + 1, dot.end());

        multiset<int,greater<int>> horizontal;
        multiset<int,greater<int>> vertical;
        auto [X1, Y1] = dot[1];            

        auto checkIntersectAndSwap=[](tuple<int,int> & dotV,tuple<int,int> & dotH)
        {
            auto[xH,yH]=dotH;
            auto[xV,yV]=dotV;
            if(xV<xH && yV>yH)
                swap(dotH,dotV);
        };

            
            if(true)
                horizontal.insert(X1);
            else
                vertical.insert(Y1);            

            for (int i = 2; i <= N ; ++i)
            {
                auto [x, y] = dot[i];

                int topY=0;
                if(!vertical.empty())
                    topY = * vertical.begin();
                
                bool putH=false;

                if(y>topY)
                {
                    if(x<y && horizontal.size()<H)
                    {
                        putH=true;
                    }
                }

                if(putH)
                    horizontal.insert(x);
                else if(vertical.size()<V)
                    vertical.insert(y);
                else 
                    horizontal.insert(x);

            }

            int ans = 0;

            int topH=0;
            if(!horizontal.empty())
            {
                auto Top=horizontal.begin();
                topH=*Top;
                ans +=topH;

                ++Top;
                for (auto it=Top; it!=horizontal.end(); ++it)
                {
                    if(*it==topH)
                        ans +=topH;
                    else
                        break;
                }
            }

            int topV=0;
            if(!vertical.empty())
            {
                auto Top=vertical.begin();
                topV=*Top;
                ans +=topV;

                ++Top;
                for (auto it=Top; it!=vertical.end(); ++it)
                {
                    if(*it==topV)
                        ans +=topV;
                    else
                        break;
                }
            }
                      





        cout << "Case #" << caseId << ": " << ans << "\n";
        return;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("FB_2019_ROUND_1_DConnecttheDots.in", "r", stdin);
    //freopen("FB_2019_ROUND_1_DConnecttheDots.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    int T;
    cin >> T;
    for (int i = 1; i <= T ; ++i)
        sln1.solve(i);
    
    
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}