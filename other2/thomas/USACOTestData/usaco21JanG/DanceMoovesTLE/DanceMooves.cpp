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

        vector<vector<int>> visitedAll(n+1,vector<int>(n+1)); //visitedAll[i][j]=k,编号i的牛在j的位置访问了k次

        auto swapPos=[&](int a, int b)
        {
            vistPos[currPosCow[a]].insert(b);
            vistPos[currPosCow[b]].insert(a);
            swap(currPosCow[a], currPosCow[b]);
            currCowPos[currPosCow[a]]=a;
            currCowPos[currPosCow[b]]=b;

            // ++visitedAll[currPosCow[a]][a];
            // ++visitedAll[currPosCow[b]][b]; 
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
            visitedAll[i][i]=1;
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
        else
        {
            //建图
            for (int i = 1; i <= n; ++i)
            {
                to[currPosCow[i]] = i ;
                from[i] = currPosCow[i];
                ans[i]=vistPos[i].size();
            }

            ill roundCnt = m / k;          //牛交换的回合数==环中走的步数
            ill remCnt = m - roundCnt * k; //完成交换回合数之后，还需要交换remCnt次
            if (m == (ill)1e18)
                remCnt=0;

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
                //cerr << "cycle  size:" << size <<",";

                roundCnt = m / k;          //牛交换的回合数==环中走的步数
                if(roundCnt>=size)
                {
                    //银组代码
                    roundCnt=size;
                    remCnt=0;
                }
                else
                {
                    remCnt = m % k;         //完成交换回合数之后，还需要交换remCnt次
                }
                //cerr << " roundCnt:" << roundCnt <<",";

                //模拟在环中走roundCnt步，每个节点次走roundCnt步
                int totalStep = roundCnt-1;     //已经走了一步

                if (totalStep > 0)
                {
                    int currAns=0;
                    //vector<int> posPassCount(n+1); //posPassCount[i]=j.编号i的位置访问了j次
                    //unordered_map<int,int> posPassCount;     //posPassCount[i]=j.编号i的位置访问了j次
                    vector<int> posPassCount(n+1);     //posPassCount[i]=j.编号i的位置访问了j次

                    auto addCow=[&](int cowId)
                    {
                        for(auto c:vistPos[cowId])
                        {
                            if(posPassCount[c]==0)   //增加位置c访问数量  posPassCount.count(c)==0 ||
                                ++currAns;
                            
                            ++posPassCount[c];
                        }
                    };
                    auto removeCow=[&](int cowId)
                    {
                        for(auto c:vistPos[cowId])
                        {
                            if(posPassCount[c]==0)
                                continue;

                            if(posPassCount[c]==1)       
                                --currAns;
                                //posPassCount.erase(c);

                            --posPassCount[c];               //减少位置c访问数量
                            
                        }
                    };

                    int last=0;
                    //循环圈
                    vector<int> newPosCow=currPosCow;
                    for (int cyclePos = 0; cyclePos<= size - 1; ++cyclePos)
                    {
                        //posPassCount.assign(n,0);
                        int curr=cycle[cyclePos];

                        if(cyclePos==0)                    
                        {
                            currAns=vistPos[curr].size();
                            for(auto kk:vistPos[curr])
                                posPassCount[kk]=1;
                        
                            int step=1;
                            int j=curr;
                            while (step<=totalStep)
                            {
                                int next=to[j];
                                addCow(next);
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
                        visitedAll[curr]=posPassCount;
                        newPosCow[currCowPos[last]]=curr;
                        ans[curr] = currAns;
                    }
                    currPosCow=newPosCow;
               
                }
                
                //todo:往前走remCnt步，模拟交换剩余次数
                // for (int i = 1; i <= remCnt; ++i)
                // {
                //     auto s = q.front();
                //     q.pop();
                //     int a=s.first;
                //     int b=s.second;

                // }

                
                // auto endTime = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count();
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

                if(visitedAll[currPosCow[a]][b]==0)             //visitedAll[currPosCow[a]].count(b)==0 ||
                {
                    ++visitedAll[currPosCow[a]][b];
                    ++ans[currPosCow[a]];
                }

                if(visitedAll[currPosCow[b]][a]==0)             //visitedAll[currPosCow[b]].count(a)==0 || 
                {
                    ++visitedAll[currPosCow[b]][a];
                    ++ans[currPosCow[b]];
                }
                swap(currPosCow[a], currPosCow[b]);
            } 

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