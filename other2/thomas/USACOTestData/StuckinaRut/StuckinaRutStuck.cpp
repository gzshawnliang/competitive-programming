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

//交点
struct CrossPoint
{
    int minDis;         //最短距离
    int cow1;           //第一头牛编号
    int cow1Dis;        //第一头牛距离
    int cow2;           //第二头牛编号
    int cow2Dis;        //第二头牛距离
    int passCow;        //经过交点的牛(0表示无牛经过)

    bool operator<(const CrossPoint & point2) const
    {
        return minDis > point2.minDis;
    }    
};


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
        vector<tuple<int,int,int>> eastCow;         //向东的牛
        vector<tuple<int,int,int>> northCow;        //向北的牛
        int id=1;                                   //牛的编号
        for (int i = 1; i <= N; ++i)
        {
            char c;
            int x,y;
            cin >> c>> x>>y;
            if(c=='E')
            {
                eastCow.push_back({id,x,y});
            }
            else if(c=='N')
            {
                northCow.push_back({id,x,y});
            }
            ++id;
        }

        //创建把交点，并放入队列，距离短的放入队列头
        //最短距离,第一头牛编号，第一头牛距离，第二头牛编号，第二头牛距离,经过交点的牛（0表示无牛经过）
        priority_queue<CrossPoint> pq;      
        for (int i = 0,lenE=eastCow.size(); i <= lenE - 1; ++i)
        {
            for (int j = 0,lenN=northCow.size(); j <= lenN - 1; ++j)
            {
                if(get<1>(eastCow[i])>get<1>(northCow[j]))
                    continue;

                if(get<2>(eastCow[i])<get<2>(northCow[j]))
                    continue;

                //创建交点，如果相交，放入队列,距离近的放入
                pair<int,int> point={get<1>(northCow[j]),get<2>(eastCow[i])};
                if(abs(point.first-get<1>(eastCow[i]))==abs(point.second-get<2>(northCow[j])))
                    continue;
                
                CrossPoint crossPoint;
                crossPoint.minDis=min(abs(point.first-get<1>(eastCow[i])),abs(point.second-get<2>(northCow[j])));
                crossPoint.cow1=get<0>(eastCow[i]);
                crossPoint.cow1Dis=abs(point.first-get<1>(eastCow[i]));
                crossPoint.cow2 = get<0>(northCow[j]);
                crossPoint.cow2Dis = abs(point.second-get<2>(northCow[j]));
                crossPoint.passCow =0;
                pq.push(crossPoint);
            }
        }
        
        //出队，距离短的牛先出,模拟牛的运动，同时建图
        vector<int> stop(N+1);          //第i个牛是否已经停止，0不停止，1停止
        g = vector<vector<int>>(N+1);   //g[i]={j,k,l}表示i停止了编号是j,k,l的牛
        while (!pq.empty())
        {
            auto curr=pq.top();
            pq.pop();

            if(curr.passCow==0)     //交点没有牛经过的情况
            {
                if(stop[curr.cow1]==0 && stop[curr.cow2]==0)    //cow1,cow2都没停止，任意一个停止则忽略此交点
                {
                    if(curr.cow1Dis<curr.cow2Dis)
                    {
                        curr.minDis=curr.cow2Dis;
                        curr.passCow=curr.cow1;
                    }
                    else 
                    {
                        curr.minDis=curr.cow1Dis;
                        curr.passCow=curr.cow2;
                    }        
                    pq.push(curr);        
                }

            }
            else if(curr.cow1==curr.passCow)    //cow1已经过交点
            {
                //cow1 stop cow2
                if(stop[curr.cow2]==0)
                {
                    stop[curr.cow2]=1;
                    g[curr.cow1].push_back(curr.cow2);      //建图
                }
            }
            else if(curr.cow2==curr.passCow)    //cow2已经过交点
            {
                //cow2 stop cow1
                if (stop[curr.cow1] == 0)
                {
                    stop[curr.cow1] = 1;
                    g[curr.cow2].push_back(curr.cow1);      //建图
                }
            }
        }

        //查找子树节点数量
        childCount=vector<int>(N+1);
        vist=vector<int>(N+1);
        for (int i = 1; i <= N; ++i)
            if(vist[i]==0)
                dfs(i,i);


        for (int i = 1; i <= N; ++i)
            cout << childCount[i]-1 << "\n";

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