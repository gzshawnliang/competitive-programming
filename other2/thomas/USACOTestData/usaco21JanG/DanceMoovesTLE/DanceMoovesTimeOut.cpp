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
    vector<int> ans;
    vector<int> vist;                       //第i个牛是否访问过
    vector<int> currPos;                    //第i个牛现在的位置
    vector<unordered_set<int>> vistPos;     //第i个牛到过的地方

    vector<int> to;                         //to[i]=j,第i牛下个回合到第j牛
    vector<int> from;                       //from[i]=j,第i牛来自第j牛

    int find(int x)
    {
        if(to[x] != x)
            to[x] =find(to[x]);

        return to[x];
    }

    void dfs(int i,vector<int> & cycle)
    {
        if(vist[i]==1)
            return;

        vist[i]=1;
        cycle.push_back(i);
        dfs(to[i],cycle);
    }

  public:
    void solve()
    {
        ill n, k, m;
        cin >> n >> k >> m;
        to = vector<int>(n + 1);
        from = vector<int>(n + 1);
        vist = vector<int>(n + 1);
        ans =vector<int> (n+1);
        currPos = vector<int>(n + 1);
        vistPos = vector<unordered_set<int>>(n + 1);

        auto swapPos=[&](int a, int b)
        {
            vistPos[currPos[a]].insert(b);
            vistPos[currPos[b]].insert(a);
            swap(currPos[a], currPos[b]);
        };

        //初始位置
        for (int i = 1; i <= n; ++i)
        {
            to[i] = i;
            from[i] = i;
            currPos[i] = i;
            vistPos[i].insert(i);
            ans[i]=1;
        }

        //模拟交换k次,一个回合，如果m<k则m次
        queue<pair<int, int>> q;
        for (int i = 1; i <= min(k, m); ++i)
        {
            int ai, bi;
            cin >> ai >> bi;
            q.push({ai, bi});
            swapPos(ai, bi);
        }

        if(m<=k)        //m<=k输出答案
        {
            for (int i = 1; i <= n; ++i)
                cout << vistPos[i].size() << "\n";
        }
        // else if (m == (ill)1e18)
        // {
        //     //合并currPos[i]和i，他们是同属于一个环
        //     for (int i = 1; i <= n; ++i)
        //     {
        //         int fx = find(i);
        //         int fy = find(currPos[i]);

        //         if (fx != fy)
        //             to[fy] = fx;
        //     }
        //     //把同一个环中经过的位置合并到根节点
        //     for (int i = 1; i <= n; ++i)
        //         vistPos[to[i]].insert(vistPos[i].begin(), vistPos[i].end());

        //     for (int i = 1; i <= n; ++i)
        //         cout << vistPos[to[i]].size() << "\n";
        // }
        // if(n<=100 && k <=200)
        // {
        //     if(m>k)
        //     {
        //         for (int i = k+1; i <= m; ++i)
        //         {
        //             auto s=q.front();
        //             q.pop();
        //             int ai=s.first;
        //             int bi=s.second;
        //             swapPos(ai,bi);
        //             q.push(s);
        //         }
        //     }

        //     for (int i = 1; i <= n; ++i)
        //         cout << vistPos[i].size() << "\n";

        // }
        else
        {
            //建图
            for (int i = 1; i <= n; ++i)
            {
                to[currPos[i]] = i ;
                from[i] = currPos[i];
            }

            ill roundCnt = m / k;          //牛交换的回合数,环中走的步数
            ill remCnt = m - roundCnt * k; //完成交换回合数之后，还需要交换remCnt次
            if (m == (ill)1e18)
                remCnt=0;

            //在图中找环
            
            for(int i=1;i<=n;++i)
            {
                auto startTime = chrono::high_resolution_clock::now();
                
                vector<int> cycle;
                if(vist[i]==0)
                    dfs(i,cycle);
                else 
                    continue;

                ans[i]=vistPos[i].size();
                int size=cycle.size();


                roundCnt = m / k;          //牛交换的回合数,环中走的步数
                if(roundCnt>=size)
                {
                    //银组代码
                    roundCnt=size;
                    //remCnt=0;
                }

                //环中每个节点次走roundCnt步
                --roundCnt;     //已经走了一步
                vector<unordered_set<int>> vistPosSet2(n + 1); //第i个牛到过的地方
                for(auto j:cycle)
                {
                    int curr=j;

                    if(roundCnt==size-1 && j!=(*cycle.begin()))
                    {
                        ans[j]=ans[*cycle.begin()];
                        //vistPosSet2[j]=vistPosSet2[*cycle.begin()];
                        continue;
                    }
                    int step=1;
                    while (step<=roundCnt)
                    {
                        vistPosSet2[j].insert(vistPos[to[curr]].begin(),vistPos[to[curr]].end());
                        //swap(currPos[curr], currPos[to[curr]]);
                        currPos[j]=from[currPos[j]];
                        curr=to[curr];

                        ++step;
                    }
                    vistPosSet2[j].insert(vistPos[j].begin(),vistPos[j].end());
                    ans[j]=vistPosSet2[j].size();
                }

                if (m < (ill)1e18)
                    for (int i2 = 1; i2 <= n; ++i2)
                    {
                        vistPos[i2].insert(vistPosSet2[i2].begin(),vistPosSet2[i2].end());                                        
                    }

                auto endTime = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count();
                cerr << "cycle size:" << size <<"\n";
                cerr << "Execution time: " << endTime << " ms\n";                

            }

            //模拟交换剩余次数
            for (int i = 1; i <= remCnt; ++i)
            {
                auto s = q.front();
                q.pop();
                int a=s.first;
                int b=s.second;
                vistPos[currPos[a]].insert(b);
                vistPos[currPos[b]].insert(a);
                ans[currPos[a]]=vistPos[currPos[a]].size();
                ans[currPos[b]]=vistPos[currPos[b]].size();
                swap(currPos[a], currPos[b]);
            }            


            for(int i=1;i<=n;++i)
            {
                cout <<ans[i] <<"\n";
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("DanceMooves.in", "r", stdin);
    freopen("DanceMooves.out", "w", stdout);
#endif

    solution sln1;
    sln1.solve();
    cout.flush();



    return 0;
}