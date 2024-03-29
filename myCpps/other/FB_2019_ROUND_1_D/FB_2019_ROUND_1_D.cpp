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

            // ill x = ((ax % dx * x2 % dx) % dx + (bx % dx * x1 % dx) % dx + cx % dx) % dx + 1;
            // ill y = ((ay % dy * y2 % dy) % dy + (by % dy * y1 % dy) % dy + cy % dy) % dy + 1;
            ill x = (ax * x2 + bx * x1  + cx) % dx + 1;
            ill y = (ay * y2 + by * y1  + cy) % dy + 1;

            dot[i] = {x, y};
        }
        sort(dot.begin() + 1, dot.end());

        for (ill i = 1; i <= N ; ++i)
            cout<<"(" <<get<0>(dot[i]) << "," << get<1>(dot[i])<<")\n";

        // auto checkillersectAndSwap=[](tuple<ill,ill> & dotV,tuple<ill,ill> & dotH)
        // {
        //     auto[xH,yH]=dotH;
        //     auto[xV,yV]=dotV;
        //     if(xV<xH && yV>yH)
        //         swap(dotH,dotV);
        // }; 
        
        auto checkIntersect=[](const tuple<ill,ill> & dotV,const tuple<ill,ill> & dotH)
        {
            auto[xH,yH]=dotH;
            auto[xV,yV]=dotV;
            if(xV<xH && yV>yH)
                return true;
            
            return false;
        }; 

        auto compare1 = [](const tuple<ill,ill> & a,const tuple<ill,ill> & b) 
        { 
            if(get<0>(a) < get<0>(b))
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
            if(get<1>(a) < get<1>(b))
            {
                return true;
            }
            else if(get<1>(a) == get<1>(b))
            {
                return (get<0>(a) > get<0>(b));
            }
            return false;
        };        

        priority_queue<tuple<ill,ill>,vector<tuple<ill,ill>>,decltype(compare1)> horizontal(compare1);
        priority_queue<tuple<ill,ill>,vector<tuple<ill,ill>>,decltype(compare2)> vertical(compare2);            
        
        auto getMultisetTopH=[&]()
        {
            if(!horizontal.empty())
                return get<0>(horizontal.top());
            
            return 0LL;            
        };  

        auto getMultisetTopV=[&]()
        {
            if(!vertical.empty())
                return get<1>(vertical.top());
            
            return 0LL;
        };                

        ill ans=INF;

        for (ill i = 1; i <= N ; ++i)
            horizontal.push(dot[i]);

        while (true)
        {
            if((ill)horizontal.size()<=H && (ill)vertical.size()<=V)
            {
                ans = min(ans, getMultisetTopH() + getMultisetTopV());
                // ++icount;
                // ill temp1 = getMultisetTopH();
                // cout << temp1 << "+";                
                // ill temp2 = getMultisetTopV();
                // cout << temp2 << "=";                
                // ans = min(ans, temp1+temp2);
                // cout << ans << "   " << icount <<"\n"; 
                //cout << ans << ":" << temp << "\n";
            }
                
            if (horizontal.empty())
                break;

            // if((ill)vertical.size()==V)
            //     break;

            // auto topH = horizontal.top();
            // horizontal.pop();
            // vertical.push(topH);

            if((ill)vertical.size()<V)
            {
                auto topH = horizontal.top();
                horizontal.pop();
                vertical.push(topH);
            }
            else if((ill)vertical.size()==V && V>0)
            {
                auto topH = horizontal.top();
                auto topV = vertical.top();
                //cout << get<0>(topH) << "," << get<1>(topH) << ":"<< get<0>(topV) << "," << get<1>(topV)<< endl;

                if(get<0>(topV)+get<1>(topH) <ans)
                {

                if(!checkIntersect(topH,topV))
                {
                    horizontal.pop();
                    vertical.pop();
                    vertical.push(topH);
                    horizontal.push(topV);
                }
                }
                else
                {
                    break;
                }
                
            }
            else
            {
                break;
            }
            
        }

        while (true)
        {
            if((ill)horizontal.size()<=H && (ill)vertical.size()<=V)
            {
                ans=min(ans,getMultisetTopH()+getMultisetTopV());

                // ++icount;
                // ill temp1 = getMultisetTopH();
                // cout << temp1 << "+";                
                // ill temp2 = getMultisetTopV();
                // cout << temp2 << "=";                
                // ans = min(ans, temp1+temp2);
                // cout << ans << "   " << icount <<"\n"; 
            }
            
            //cout << ans << "\n";

            //horizontal.size()<H && !vertical.empty()
            if (vertical.empty() || (ill)horizontal.size()==H)
                break;

            auto topV = vertical.top();
            vertical.pop();
            horizontal.push(topV);
        }

        while (!horizontal.empty())
            horizontal.pop();

        while (!vertical.empty())
            vertical.pop();


        // //priority_queue<tuple<ill,ill>,vector<tuple<ill,ill>>,decltype(compare1)> horizontal(compare1);
        // // priority_queue<tuple<ill,ill>,vector<tuple<ill,ill>>,decltype(compare1)> horizontal(compare1);
        // // priority_queue<tuple<ill,ill>,vector<tuple<ill,ill>>,decltype(compare2)> vertical2(compare2);
        // //vertical = priority_queue<tuple<ill,ill>,vector<tuple<ill,ill>>,decltype(compare2)>(compare2);

        for (ill i = 1; i <= N ; ++i)
            vertical.push(dot[i]);
        
        while (true)
        {
            if((ill)horizontal.size()<=H && (ill)vertical.size()<=V)
            {
                ans=min(ans,getMultisetTopH()+getMultisetTopV());
                // ill temp1 = getMultisetTopH();
                // cout << temp1 << "+";                
                // ill temp2 = getMultisetTopV();
                // cout << temp2 << "=";                
                // ans = min(ans, temp1+temp2);
                // cout << ans << "\n"; 
                //cout << ans << ":" << temp << "\n";                
            }
            
            //cout << ans << "\n";

            //horizontal.size()<H && !vertical.empty()
            if (vertical.empty() || (ill)horizontal.size()==H)
                break;

            auto topV = vertical.top();
            vertical.pop();
            horizontal.push(topV);


            if((ill)horizontal.size()<H)
            {
                auto topV = vertical.top();
                vertical.pop();
                horizontal.push(topV);
            }
            else if((ill)horizontal.size()==H && H>0)
            {
                auto topH = horizontal.top();
                auto topV = vertical.top();
                //cout << get<0>(topH) << "," << get<1>(topH) << ":"<< get<0>(topV) << "," << get<1>(topV)<< endl;

                if(get<0>(topV)+get<1>(topH) <ans)
                {

                if(!checkIntersect(topH,topV))
                {
                    horizontal.pop();
                    vertical.pop();
                    vertical.push(topH);
                    horizontal.push(topV);
                }
                }
                else
                {
                    break;
                }
                
            }
            else
            {
                break;
            }

        }

        while (true)
        {
            if((ill)horizontal.size()<=H && (ill)vertical.size()<=V)
            {
                ans=min(ans,getMultisetTopH()+getMultisetTopV());
                // ill temp1 = getMultisetTopH();
                // cout << temp1 << "+";                
                // ill temp2 = getMultisetTopV();
                // cout << temp2 << "=";                
                // ans = min(ans, temp1+temp2);
                // cout << ans << "\n"; 
            }
            
            //cout << ans << "\n";

            if (horizontal.empty() || (ill)vertical.size()==V)
                break;

            auto topH = horizontal.top();
            horizontal.pop();
            vertical.push(topH);
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
    freopen("FB_2019_ROUND_1_D.in", "r", stdin);
    freopen("FB_2019_ROUND_1_D.out", "w", stdout);
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