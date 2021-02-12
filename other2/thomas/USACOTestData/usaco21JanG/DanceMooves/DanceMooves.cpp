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
    vector<int> vist;                       //编号i牛是否访问过
    vector<int> currPosCow;                    //currPosCow[i]=j,编号i位置现在是编号j牛
    vector<int> currCowPos;                    //currCowPos[i]=j,编号i牛现在是位置j
    vector<unordered_set<int>> vistPos;     //编号i牛到过的地方

    vector<int> to;                         //to[i]=j,编号i牛下个回合到编号j牛
    vector<int> from;                       //from[i]=j,编号i的牛来自(上回合)编号j牛

    int find(int x)
    {
        if(to[x] != x)
            to[x] =find(to[x]);

        return to[x];
    }

    void dfs2(int i,vector<int> & cycle,vector<int> & cycle2)
    {
        if(vist[i]==1)
            return;

        vist[i]=1;
        cycle.push_back(i);
        cycle2[i]=1;
        dfs2(to[i],cycle,cycle2);
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
        currPosCow = vector<int>(n + 1);
        currCowPos= vector<int>(n + 1);
        vistPos = vector<unordered_set<int>>(n + 1);

        auto swapPos=[&](int a, int b)
        {
            vistPos[currPosCow[a]].insert(b);
            vistPos[currPosCow[b]].insert(a);
            swap(currPosCow[a], currPosCow[b]);
            currCowPos[currPosCow[a]]=a;
            currCowPos[currPosCow[b]]=b;
        };

        //初始位置
        for (int i = 1; i <= n; ++i)
        {
            to[i] = i;
            from[i] = i;
            currPosCow[i] = i;
            currCowPos[i] = i;
            vistPos[i].insert(i);
            ans[i]=1;
        }

        queue<pair<int, int>> q;
        //模拟交换k次,一个回合，如果m<k则m次
        for (int i = 1; i <= min(k, m); ++i)
        {
            int a, b;
            cin >> a >> b;
            q.push({a, b});
            swapPos(a, b);
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
        //         int fy = find(currPosCow[i]);

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
                to[currPosCow[i]] = i ;
                from[i] = currPosCow[i];
            }

            ill roundCnt = m / k;          //牛交换的回合数,环中走的步数
            ill remCnt = m - roundCnt * k; //完成交换回合数之后，还需要交换remCnt次
            if (m == (ill)1e18)
                remCnt=0;


            vector<unordered_map<int,int>> visitedAll(n+1); //visitedAll[i][j]=k,编号i的牛在j的位置访问了k次
                        //在图中找环
            for(int i=1;i<=n;++i)
            {
                auto startTime = chrono::high_resolution_clock::now();
                
                vector<int> cycle;
                //vector<int> cycle2(n+1);
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
                    remCnt=0;
                }

                //环中每个节点次走roundCnt步
                --roundCnt;     //已经走了一步
                // vector<unordered_set<int>> vistPosSet2(n + 1); //(在圈内)第i个牛到过的地方
                // for(auto j:cycle)
                // {
                //     int curr=j;
                //     if(j==(*cycle.begin()) || roundCnt<size-1)
                //     {
                //         int step=1;
                //         while (step<=roundCnt)
                //         {
                //             vistPosSet2[j].insert(vistPos[to[curr]].begin(),vistPos[to[curr]].end());
                //             currPosCow[j]=from[currPosCow[j]];
                //             curr=to[curr];

                //             ++step;
                //         }
                //     }
                //     else 
                //     {
                //         ans[j]=ans[*cycle.begin()];
                //         continue;
                //     }
                //     vistPosSet2[j].insert(vistPos[j].begin(),vistPos[j].end());
                //     ans[j]=vistPosSet2[j].size();
                // }

                if(roundCnt>0)
                {
                    int currAns=0;
                    //vector<int> visited(n+1); //visited[i]=j.编号i的位置访问了j次
                    unordered_map<int,int> visited;     //visited[i]=j.编号i的位置访问了j次

                    auto addCow=[&](int cowId)
                    {
                        for(auto c:vistPos[cowId])
                        {
                            if(visited.count(c)==0 || visited[c]==0)   //增加位置c访问数量
                                ++currAns;
                            
                            ++visited[c];
                        }
                    };
                    auto removeCow=[&](int cowId)
                    {
                        for(auto c:vistPos[cowId])
                        {
                            --visited[c];               //减少位置c访问数量
                            if(visited[c]==0)       
                            {
                                --currAns;
                                visited.erase(c);
                            }
                        }
                    };                
                    int last=0;
                    //循环圈
                    for (int cyclePos = 0; cyclePos<= size - 1; ++cyclePos)
                    {
                        //visited.assign(n,0);
                        int curr=cycle[cyclePos];

                        if(cyclePos==0)                    
                        {
                            currAns=vistPos[curr].size();
                            for(auto kk:vistPos[curr])
                                visited[kk]=1;
                        
                            int step=1;
                            int j=curr;
                            while (step<=roundCnt)
                            {
                                int next=to[j];
                                addCow(next);
                                //currPosCow[j]=from[currPosCow[j]];
                                j=next;
                                ++step;
                            }  
                            last=j;
                        }
                        else
                        {
                            removeCow(from[curr]);
                            addCow(to[last]);
                            
                            //currPosCow[curr]= from[currPosCow[last]];

                            last=to[last];         
                        }
                        visitedAll[curr]=visited;
                        //currPosCow[curr]=last;
                        //currPosCow[from[curr]]=curr;
                        
                        //from[curr]->curr

                        //curr->last
                        // currCowPos[last]=currCowPos[curr];
                        // currPosCow[currCowPos[last]]=currPosCow[currCowPos[curr]];

                        // //from[curr]->curr
                        // currCowPos[curr]=currCowPos[from[curr]];
                        // currPosCow[currCowPos[curr]]=currPosCow[currCowPos[from[curr]]];

                        

                        //swap(currPosCow[curr],currPosCow[last]);
                        ans[curr] = currAns;
                    }
                

                    //todo:vistPos数据错误。bug
                    //模拟交换剩余次数：remCnt
                    // for (int p = 1; p <= remCnt; ++p)
                    // {
                    //     auto s = q.front();
                    //     q.pop();
                    //     int a = s.first;
                    //     int b = s.second;

                    //     if (visited[b] == 0)
                    //         ++ans[currPosCow[a]];
                    //     ++visited[b];

                    //     if (visited[a] == 0)
                    //         ++ans[currPosCow[b]];
                    //     ++visited[a];

                    //     swap(currPosCow[a], currPosCow[b]);
                    // }
                }

                // if (m < (ill)1e18)
                //     for (int i2 = 1; i2 <= n; ++i2)
                //     {
                //         vistPos[i2].insert(vistPosSet2[i2].begin(),vistPosSet2[i2].end());                                        
                //     }

                // auto endTime = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count();
                // cerr << "cycle size:" << size <<"\n";
                // cerr << "Execution time: " << endTime << " ms\n";                
            }


            //todo:模拟交换剩余次数
            remCnt = m % k; //完成交换回合数之后，还需要交换remCnt次
            for (int i = 1; i <= remCnt; ++i)
            {
                auto s = q.front();
                q.pop();
                int a=s.first;
                int b=s.second;

                if(visitedAll[currPosCow[a]].count(b)==0 || visitedAll[currPosCow[a]][b]==0)
                {
                    ++visitedAll[currPosCow[a]][b];
                    ++ans[currPosCow[a]];
                }

                if(visitedAll[currPosCow[b]].count(a)==0 || visitedAll[currPosCow[b]][a]==0)
                {
                    ++visitedAll[currPosCow[b]][a];
                    ++ans[currPosCow[b]];
                }
                swap(currPosCow[a], currPosCow[b]);
            } 


            // //模拟交换剩余次数
            // for (int i = 1; i <= remCnt; ++i)
            // {
            //     auto s = q.front();
            //     q.pop();
            //     int a=s.first;
            //     int b=s.second;
            //     vistPos[currPosCow[a]].insert(b);
            //     vistPos[currPosCow[b]].insert(a);
            //     ans[currPosCow[a]]=vistPos[currPosCow[a]].size();
            //     ans[currPosCow[b]]=vistPos[currPosCow[b]].size();
            //     swap(currPosCow[a], currPosCow[b]);
            // }            

            for(int i=1;i<=n;++i)
                cout <<ans[i] <<"\n";
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