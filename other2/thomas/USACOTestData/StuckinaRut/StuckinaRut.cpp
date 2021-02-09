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
    int N;
    vector<int> childCount;
    vector<int> vist;
    vector<vector<int>> g;

    void dfs(int p,int curr)
    {
        vist[curr]=1;
        childCount[curr]=1;
        for (auto i : g[curr])
        {
            dfs(curr,i);
            childCount[curr] +=childCount[i];
        }
    }

  public:
    void solve()
    {
        cin >> N;
        vector<tuple<int,int,int>> vE;
        vector<tuple<int,int,int>> vN;
        int id=1;
        for (int i = 1; i <= N; ++i)
        {
            char c;
            int x,y;
            cin >> c>> x>>y;
            if(c=='E')
            {
                vE.push_back({id,x,y});
            }
            else if(c=='N')
            {
                vN.push_back({id,x,y});
            }
            ++id;
        }

        std::sort(vE.begin(), vE.end(), [](tuple<int,int,int> const & a, tuple<int,int,int> const & b) 
        {
            return get<1>(a) < get<1>(b); 
        });

        std::sort(vN.begin(), vN.end(), [](tuple<int,int,int> const & a, tuple<int,int,int> const & b) 
        {
            return get<2>(a) < get<2>(b); 
        });

        //crossover point
        auto compare = [](const tuple<int,int,int> & a, const tuple<int,int,int> & b)
                    {
                        return get<0>(a) > get<0>(b); 
                    };

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, decltype(compare)> pq(compare);
        for (int i = 0,lenE=vE.size(); i <= lenE - 1; ++i)
        {
            for (int j = 0,lenN=vN.size(); j <= lenN - 1; ++j)
            {
                if(get<1>(vE[i])>get<1>(vN[j]) || get<2>(vE[i])<get<2>(vN[j]))
                    continue;

                //创建交点，如果相交，放入队列,距离近的放入
                pair<int,int> point={get<1>(vN[j]),get<2>(vE[i])};
                if(abs(point.first-get<1>(vE[i]))==abs(point.second-get<2>(vN[j])))
                    continue;
                
                int dis=min(abs(point.first-get<1>(vE[i])),abs(point.second-get<2>(vN[j])));
                if(abs(point.first-get<1>(vE[i]))>abs(point.second-get<2>(vN[j])))
                {
                    pq.push({dis,get<0>(vN[j]),get<0>(vE[i])});
                }
                else
                {
                    pq.push({dis,get<0>(vE[i]),get<0>(vN[j])});
                }
            }
        }
        
        //出队，建图
        vector<int> stop(N+1);
        childCount=vector<int>(N+1);
        vist=vector<int>(N+1);
        g = vector<vector<int>>(N+1);
        while (!pq.empty())
        {
            auto curr=pq.top();
            pq.pop();
            if(stop[get<1>(curr)]==0 && stop[get<2>(curr)]==0)
            {
                stop[get<2>(curr)]=1;
                g[get<1>(curr)].push_back(get<2>(curr));
                cerr << "dis:" << get<0>(curr) << ", " << get<1>(curr) << " stop " << get<2>(curr) << "\n";
            }
        }

        for (int i = 1; i <= N; ++i)
        {
            if(vist[i]==0)
                dfs(i,i);
        }

        for (int i = 1; i <= N; ++i)
        {
            cout << childCount[i]-1 << "\n";
        }
        return;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("StuckinaRut.in", "r", stdin);
    freopen("StuckinaRut.out", "w", stdout);
#endif

    solution sln1;
    sln1.solve();
    cout.flush();



    return 0;
}