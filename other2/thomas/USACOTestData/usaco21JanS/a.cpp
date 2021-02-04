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

#define a first
#define b second

using namespace std;

using ill = long long;


class solution
{
    vector<vector<int>> g;                  //g[i->j]第i->j个牛有条边
    vector<int> vist;                       //第i个牛是否访问过

    vector<int> currPos;                    //第i个牛现在的位置
    vector<unordered_set<int>> goPos;       //第i个牛到过的地方
    vector<int> fa;                         //第i个牛的父亲，同一个环父亲一样

    int find(int x)
    {
        if(fa[x] != x)
            fa[x] =find(fa[x]);

        return fa[x];
    }

    void dfs(int p,int c)
    {
        if(vist[c]==1)
            return;
        
        vist[c]=1;
        fa[c]=p;
        for (auto i:g[c])
        {
            dfs(c,i);
        }
        
    }
  public:
    void solve()
    {
        int n,k;
        cin >>n>>k;
        currPos = vector<int>(n+1);
        fa= vector<int>(n+1);
        g = vector<vector<int>>(n+1,vector<int>());
        vist= vector<int>(n+1);
        goPos=vector<unordered_set<int>>(n+1);

        for (int i = 1; i <= n; ++i)
        {
            fa[i]=i;
            currPos[i] = i;
            goPos[i].insert(i);
        }

        //模拟交换
        for (int i = 1; i <= k; ++i)
        {
            int ai,bi;
            cin>> ai>>bi;

            goPos[currPos[ai]].insert(bi);
            goPos[currPos[bi]].insert(ai);

            swap(currPos[ai],currPos[bi]);
        }
        
        //建图
        for(int i=1;i<=n;++i)
            g[i].push_back(currPos[i]);
        
        //合并环
        for(int i=1;i<=n;++i)
            if(vist[i]==0)
                dfs(i,i);


        for(int i=1;i<=n;++i)
        {	
            int fx=find(i);
            int fy=find(currPos[i]);

            if(fx!=fy)
                fa[fy]=fx;
        }

        for (int i = 1; i <= n; ++i)
            goPos[fa[i]].insert(goPos[i].begin(),goPos[i].end());

        for (int i = 1; i <= n; ++i)
            cout << goPos[fa[i]].size() << "\n";
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