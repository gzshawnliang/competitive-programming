#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill INF=LLONG_MAX;

class solution
{
  public:

    void solve(ill caseId)
    {
        
        ill N,H,V;
        cin >> N >> H >> V;
        ill x1, x2, y1, y2, ax, bx, cx, dx, ay, by, cy, dy;
        cin >> x1 >> x2 >> ax >> bx >> cx >> dx;
        cin >> y1 >> y2 >> ay >> by >> cy >> dy;

        if (N > H + V)
        {
            cout << "Case #" << caseId << ": -1" << "\n";
            return;
        }

        vector<tuple<ill,ill>> dot = vector<tuple<ill, ill>>(N + 1);
        dot[1] = {x1, y1};
        dot[2] = {x2, y2};
        for (ill i = 3; i <= N; ++i)
        {
            auto [x2, y2] = dot[i - 2];
            auto [x1, y1] = dot[i - 1];

            ill x = ((ax * x2 + bx * x1 + cx) % dx) + 1;
            ill y = ((ay * y2 + by * y1 + cy) % dy) + 1;
            dot[i] = {x, y};
        }
        sort(dot.begin() + 1, dot.end());

        // for (ill i = 1; i <= N ; ++i)
        //     cout<<"(" <<get<0>(dot[i]) << "," << get<1>(dot[i])<<")\n";

        auto checkillersectAndSwap=[](tuple<ill,ill> & dotV,tuple<ill,ill> & dotH)
        {
            auto[xH,yH]=dotH;
            auto[xV,yV]=dotV;
            if(xV<xH && yV>yH)
                swap(dotH,dotV);
        }; 
        
        auto compare1 = [](const tuple<ill,ill> & a,const tuple<ill,ill> & b) 
        { 
            if(get<0>(a) > get<0>(b))
            {
                return true;
            }
            else if(get<0>(a) == get<0>(b))
            {
                return (get<1>(a) > get<1>(b));
            }
            return false;

        };
        auto compare2 = [](const tuple<ill,ill> & a,const tuple<ill,ill> & b) 
        { 
            if(get<1>(a) > get<1>(b))
            {
                return true;
            }
            else if(get<1>(a) == get<1>(b))
            {
                return (get<0>(a) > get<0>(b));
            }
            return false;
        };        

        multiset<tuple<ill,ill>,decltype(compare1)> horizontal(compare1);
        multiset<tuple<ill,ill>,decltype(compare2)> vertical(compare2);            
        
        auto getMultisetTopH=[&]()
        {
            if(!horizontal.empty())
                return get<0>((*horizontal.begin()));
            
            return 0LL;            
        };  

        auto getMultisetTopV=[&]()
        {
            if(!vertical.empty())
                return get<1>((*vertical.begin()));
            
            return 0LL;
        };                

        ill ans=INF;

        for (ill i = 1; i <= N ; ++i)
            horizontal.insert(dot[i]);
        
        while (true)
        {
            if(horizontal.size()<=H && vertical.size()<=V)
                ans=min(ans,getMultisetTopH()+getMultisetTopV());
            
            if (horizontal.empty() || vertical.size()==V)
                break;

            auto topH = *horizontal.begin();
            vertical.insert(topH);
            horizontal.erase(horizontal.begin());
        }

        while (true)
        {
            if(horizontal.size()<=H && vertical.size()<=V)
                ans=min(ans,getMultisetTopH()+getMultisetTopV());
            
            //horizontal.size()<H && !vertical.empty()
            if (vertical.empty() || horizontal.size()==H)
                break;

            auto topV = *vertical.begin();
            horizontal.insert(topV);
            vertical.erase(vertical.begin());
        }

        horizontal.clear();
        vertical.clear();
        for (ill i = 1; i <= N ; ++i)
            vertical.insert(dot[i]);
        
        while (true)
        {
            if(horizontal.size()<=H && vertical.size()<=V)
                ans=min(ans,getMultisetTopH()+getMultisetTopV());
            
            //horizontal.size()<H && !vertical.empty()
            if (vertical.empty() || horizontal.size()==H)
                break;

            auto topV = *vertical.begin();
            horizontal.insert(topV);
            vertical.erase(vertical.begin());
        }

        while (true)
        {
            if(horizontal.size()<=H && vertical.size()<=V)
                ans=min(ans,getMultisetTopH()+getMultisetTopV());
            
            if (horizontal.empty() || vertical.size()==V)
                break;

            auto topH = *horizontal.begin();
            vertical.insert(topH);
            horizontal.erase(horizontal.begin());
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
    freopen("FB_2019_ROUND_1_DConnecttheDots.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    ill T;
    cin >> T;
    for (ill i = 1; i <= T ; ++i)
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