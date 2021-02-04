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
    vector<vector<int>> g;
    vector<int> group;
    vector<int> pos2;
    vector<unordered_set<int>> pos3;
    vector<int> vist;
    vector<int> parent;

    vector<int> group2;
    int groupId=0;
    
    void mergeSet(unordered_set<int> & set1,unordered_set<int> & set2)
    {
        set1.insert(set2.begin(),set2.end());
    }

    void dfs(int u,int v)
    {
        if(vist[v]==1)
        {
            return;
        }
        else
        {
            vist[v]=1;
            if(u==-1)
            {
                group[v]=(int)pos3[v].size();  
            }
            else
            {
                //mergeSet(pos3[v],pos3[u]);
                //pos3[v].insert(pos3[u].begin(),pos3[u].end());
                group[v]=max(group[u],(int)pos3[v].size());
                group[u]=group[v];
                parent[v]=u;
            }

            for(auto c:g[v])
            {
                parent[c]=v;
                dfs(v,c);
            }
        }
    }
    stack<int> path;
    int maxSize=0;
    void dfs2(int v)
    {
        if(vist[v]==1)
        {
            while (!path.empty())
            {
                int curr=path.top();
                path.pop();
                parent[curr]=v;
                group[curr]=maxSize;
            }
            maxSize=0;
            return;
        }
        else
        {
            vist[v]=1;
            path.push(v);
            maxSize =max(maxSize,(int)pos3[v].size());
            dfs2(parent[v]);
            
        }
    }

  public:
    void solve()
    {
        int n,k;
        cin >>n>>k;
        g = vector<vector<int>>(n+1,vector<int>());
        pos2 = vector<int>(n+1);
        group = vector<int>(n+1);
        vist = vector<int>(n+1);
        parent= vector<int>(n+1);

        pos3=vector<unordered_set<int>>(n+1);

        for (int i = 1; i <= n; ++i)
        {
            pos2[i] = i;
            pos3[i].insert(i);
        }

        //模拟交换
        for (int i = 1; i <= k; ++i)
        {
            int ai,bi;
            cin>> ai>>bi;

            pos3[pos2[ai]].insert(bi);
            pos3[pos2[bi]].insert(ai);

            swap(pos2[ai],pos2[bi]);
        }
        
        for (int i = 1; i <= n; ++i)
            g[pos2[i]].push_back(i);

        for (int i = 1; i <= n; ++i)
            if(vist[i]==0)
                dfs(-1,i);

        vist.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            dfs2(i);        

        for (int i = 1; i <= n; ++i)
            cout << group[i] << "\n";
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