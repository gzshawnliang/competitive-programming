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
    vector<vector<int>> g;
    vector<int> vist;
    void dfs(int u,vector<int> & group)
    {
        vist[u]=1;
        for(auto v:g[u])
        {
            if(vist[v]==0)
            {
                group.push_back(v);
                dfs(v,group);
            }
        }
    }

  public:
    void solve(int caseId)
    {
        int N,M;
        cin >> N>> M;
        vector<pair<int,int>> req;
        set<pair<int,int>> edge;
        g=vector<vector<int>>(N+1);
        vist=vector<int>(N+1,0);


        for (int i = 1; i <= M; ++i)
        {
            int x,y;
            cin >> x >> y;
            req.push_back({x,y});

            while (y-x>=1)
            {
                edge.insert({x,y});
                g[x].push_back(y);
                g[y].push_back(x);
                ++x;
                --y;
            }
        }

        if(M==0)
        {
            cout << "Case #" << caseId << ": ";
            for (int i = 1; i <= N/2; ++i)
            {
                cout <<1;
            }        
        
            for (int i = N/2+1; i <= N; ++i)
            {
                cout <<0;
            }
            cout << "\n";                        
            return;
        }

        vector<vector<int>> AllGroup;
        vector<int> AllGroupCount;
        AllGroup.push_back(vector<int>());
        AllGroupCount.push_back(0);
        for (int i = 1; i <= N; ++i)
        {
            if(vist[i]==0)
            {
                vector<int> currGroup;
                currGroup.push_back(i);
                dfs(i,currGroup);
                AllGroup.push_back(currGroup);
                AllGroupCount.push_back(currGroup.size());
            }
        }
        int maxSize = N;
        vector<vector<int>> dp(AllGroupCount.size(),vector<int>(maxSize+1,-1));

        for (int j = 0; j <= maxSize; ++j)
            dp[0][j]=0;

        for (int i = 1,len=AllGroupCount.size(); i <= len-1; ++i)
        {
            for (int j = 1; j <= maxSize; ++j)
            {
                if(j-AllGroupCount[i]>=0)
                    dp[i][j] = max(dp[i - 1][j], AllGroupCount[i] + dp[i - 1][j - AllGroupCount[i]]);
                else 
                    dp[i][j]= dp[i-1][j];
            }
        }

        auto getResult=[&](int size1,int & w)
        {
            set<int> result;
            int j=size1;
            int i=dp.size()-1;

            while (j>0 && i>=1)
            {
                if(dp[i][j]==dp[i-1][j])
                {
                    --i;
                    continue;
                }
                result.insert(i);
                w+=AllGroupCount[i];
                int nextJ=dp[i][j]-AllGroupCount[i];
                while (j>0 && dp[i][j]>nextJ)
                    --j;
                
                while (j>0 && dp[i][j-1]==nextJ)
                    --j;
                
            }
            return result;
        };

        int j=N/2;
        int w1=0;
        set<int> result1=getResult(j,w1);

        j=N/2+1;
        int w2=0;
        set<int> result2=getResult(j,w2);

        set<int> result;

        int w=min(abs(N-w1-w1),abs(N-w2-w2));
        
        if(abs(N-w1-w1)<abs(N-w2-w2))
            result=result1;
        else 
            result=result2;

        vector<int> ans(N + 1, 0);
        for (auto i : result)
            for (auto j : AllGroup[i])
                ans[j] = 1;

        // for(auto[x,y]:edge)
        // {
        //     cout << x << " " << y << "\n";
        // }

        cout << "Case #" << caseId << ": ";

        for (int i = 1; i <= N; ++i)
            cout << ans[i];

        //cout << " " << w;
        cout << "\n";
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    //freopen("FB_2019_ROUND_2_B.in", "r", stdin);
    freopen("bitstrings_as_a_service_input.in", "r", stdin);
    freopen("FB_2019_ROUND_2_B.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; ++i)
    {
        solution sln1;    
        sln1.solve(i);
    }
    
    
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}