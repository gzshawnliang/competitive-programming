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
    vector<int> vist;      //第i个牛是否访问过
    vector<int> currPos;                   //第i个牛现在的位置
    vector<unordered_set<int>> vistPosSet; //第i个牛到过的地方

    vector<int> to;                      //to[i]=j,第i牛下个回合到第j牛
    vector<int> from;                      //to[i]=j,第i牛下个回合到第j牛

    void swapPos(int a, int b)
    {
        vistPosSet[currPos[a]].insert(b);
        vistPosSet[currPos[b]].insert(a);
        ans[currPos[a]]=vistPosSet[currPos[a]].size();
        ans[currPos[b]]=vistPosSet[currPos[b]].size();
        swap(currPos[a], currPos[b]);
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
        currPos = vector<int>(n + 1);
        to = vector<int>(n + 1);
        from = vector<int>(n + 1);
        vist = vector<int>(n + 1);
        ans =vector<int> (n+1);
        vistPosSet = vector<unordered_set<int>>(n + 1);

        //初始位置
        for (int i = 1; i <= n; ++i)
        {
            to[i] = i;
            from[i] = i;
            currPos[i] = i;
            vistPosSet[i].insert(i);
        }

        //模拟交换k次,一个回合，如果m<k则m次
        queue<pair<int, int>> q;
        ill sw = min(k, m);
        for (int i = 1; i <= sw; ++i)
        {
            int ai, bi;
            cin >> ai >> bi;
            q.push({ai, bi});
            swapPos(ai, bi);
        }
        if(m<k)
        {
            
        }
        else if (m == (ill)1e18)
        {
            //建图
            // for (int i = 1; i <= n; ++i)
            //     g[i].push_back(currPos[i]);

            // //在图中找环，填充fa[i]数组
            // for (int i = 1; i <= n; ++i)
            //     if (vist[i] == 0)
            //         dfs(i, i, true);

            // //合并currPos[i]和i，他们是同属于一个环
            // for (int i = 1; i <= n; ++i)
            // {
            //     int fx = find(i);
            //     int fy = find(currPos[i]);

            //     if (fx != fy)
            //         to[fy] = fx;
            // }
            // //把同一个环中经过的位置合并到根节点
            // for (int i = 1; i <= n; ++i)
            //     vistPosSet[to[i]].insert(vistPosSet[i].begin(), vistPosSet[i].end());

            // for (int i = 1; i <= n; ++i)
            //     cout << vistPosSet[to[i]].size() << "\n";
        }
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
        //         cout << vistPosSet[i].size() << "\n";

        // }
        else
        {
            //建图
            for (int i = 1; i <= n; ++i)
            {
                to[currPos[i]] = i ;
                from[i] = currPos[i];
            }

            // for(int i=1;i<=n;++i)
            //     g[i].push_back(currPos[i]);
            
            //在图中找环
            for(int i=1;i<=n;++i)
            {
                vector<int> cycle;
                if(vist[i]==0)
                    dfs(i,cycle);
                else 
                    continue;

                ans[i]=vistPosSet[i].size();
                int size=cycle.size();

                ill roundCnt = m / k;          //牛交换的回合数,环中走的步数
                ill remCnt = m - roundCnt * k; //完成交换回合数之后，还需要交换remCnt次                
                if(roundCnt>=size)
                {
                    //银组代码
                    roundCnt=size;
                    remCnt=0;
                }

                //再环中每个节点次走remCnt步
                --roundCnt;     //已经走了一步
                vector<unordered_set<int>> vistPosSet2(n + 1); //第i个牛到过的地方
                for(auto j:cycle)
                {
                    //unordered_set<int> set2=vistPosSet[j];
                    int step=1;
                    int curr=j;
                    while (step<=roundCnt)
                    {
                        vistPosSet2[j].insert(vistPosSet[to[curr]].begin(),vistPosSet[to[curr]].end());
                        //swap(currPos[curr], currPos[to[curr]]);
                        currPos[j]=from[currPos[j]];
                        curr=to[curr];

                        ++step;
                    }
                    //todo:最终位置
                    vistPosSet2[j].insert(vistPosSet[j].begin(),vistPosSet[j].end());
                    ans[j]=vistPosSet2[j].size();
                }

                //模拟交换p次数
                for (int i = 1; i <= remCnt; ++i)
                {
                    auto s = q.front();
                    q.pop();
                    int a=s.first;
                    int b=s.second;
                    vistPosSet2[currPos[a]].insert(b);
                    vistPosSet2[currPos[b]].insert(a);
                    ans[currPos[a]]=vistPosSet2[currPos[a]].size();
                    ans[currPos[b]]=vistPosSet2[currPos[b]].size();
                    swap(currPos[a], currPos[b]);

                    //swapPos(s.first, s.second);
                    q.push(s);
                }                
            }


            for(int i=1;i<=n;++i)
            {
                cout <<ans[i] <<"\n";
            }

            // //模拟交换
            // for (int i = 2; i <= roundCnt; ++i) //已经跑了一回合，i从2开始
            // {
            //     vector<unordered_set<int>> vistPosSet2 = vistPosSet;
            //     for (int j = 1; j <= n; ++j)
            //     {
            //         if (currPos[j] != j)
            //         {
            //             //vistPosSet2[currPos[j]].insert(vistPosSet[currPos[j]].begin(),vistPosSet[currPos[j]].end());
            //             vistPosSet2[currPos[j]].insert(vistPosSet[j].begin(), vistPosSet[j].end());
            //         }
            //     }
            //     vistPosSet = vistPosSet2;
            // }


        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
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