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
        //++maxSize;
        vector<vector<int>> dp(AllGroupCount.size()+1,vector<int>(maxSize+1,-1));

    // int[][] dp = new int[A.length+1][m+1];
    // for(int i=0;i<A.length;i++){
    //     for(int j=0;j<=m;j++){
    //         if(A[i]>j)dp[i+1][j] = dp[i][j];
    //         else dp[i+1][j] = Math.max(dp[i][j],dp[i][j-A[i]]+V[i]);
    //     }
    // }

        dp[0][0] = 0;
        for (int j = 1; j <= maxSize; ++j)
            dp[0][j]=0;

        
        for (int i = 1; i <= AllGroupCount.size(); ++i)
        {
            for (int j = 1; j <= maxSize; ++j)
            {
                if(j-AllGroupCount[i-1]>=0)
                    dp[i][j] = max(dp[i - 1][j], AllGroupCount[i - 1] + dp[i - 1][j - AllGroupCount[i - 1]]);
                else 
                    dp[i][j]= dp[i-1][j];
                
                //cout << i << "-" << j << ":" << dp[i][j] << " ";
            }
//            cout << "\n";
        }

        // for(int i=0;i<=AllGroupCount.size()-1;++i)
        //     cout << i << ":"<< AllGroupCount[i] << "\n";
             
        // cout << "\n";

        // for(int i=0;i<=AllGroup.size()-1;++i)
        // {
        //     cout << i << ":";
        //     for(auto j:AllGroup[i])
        //     {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }        
        // cout << "\n";

        set<int> result1;
        set<int> result2;

        // for(int j=0;j<=dp[0].size()-1;++j)
        //     cout <<  setw(2) << j << " ";
        
        // cout << "\n";
        // for(int i=0;i<=dp.size()-1;++i)
        // {
        //     if(i==0)
        //         cout <<  setw(2) << i << "    ";
        //     else 
        //         cout <<  setw(2) << i << " " << AllGroupCount[i-1] << " ";
        //     for(int j=0;j<=dp[i].size()-1;++j)
        //         cout <<  setw(2) << dp[i][j] << " ";
            
        //     cout << "\n";
        // }

        // for(int i=0;i<=dp.size()-1;++i)
        // {
        //     cout <<  setw(2) << i << ":";
        //     for(int j=0;j<=dp[i].size()-1;++j)
        //     {
        //         cout <<  setw(2) << dp[i][j] << " ";
        //         if(i>0)
        //         {
        //             if(dp[i][j]>dp[i-1][j])
        //             {
        //                 if(j==N/2+1 && w1+AllGroupCount[i-1] <=N/2+1)
        //                 {
        //                     result1.insert(i);                
        //                     w1 +=AllGroupCount[i-1];
        //                 }
        //                 else if(j==N/2 && w2+AllGroupCount[i-1] <=N/2)    
        //                 {
        //                     result2.insert(i);                
        //                     w2 +=AllGroupCount[i-1];
        //                 }
        //             }
        //         }
        //     }
        //     cout << "\n";
        // }

        int w1=0;
        int w2=0;

        int j=N/2;
        int i=dp.size()-1;

        while (j>=0 && i>=1)
        {
            if(dp[i][j]==dp[i-1][j])
            {
                --i;
                continue;
            }
            result1.insert(i);
            w1+=AllGroupCount[i-1];
            int nextJ=dp[i][j]-AllGroupCount[i-1];
            while (dp[i][j]>nextJ)
                --j;
            
            while (j>0 && dp[i][j-1]==nextJ)
                --j;
            
        }

        j=N/2+1;
        i=dp.size()-1;
        while (j>=0 && i>=1)
        {
            if(dp[i][j]==dp[i-1][j])
            {
                --i;
                continue;
            }
            result2.insert(i);
            w2+=AllGroupCount[i-1];
            int nextJ=dp[i][j]-AllGroupCount[i-1];
            while (dp[i][j]>nextJ)
                --j;

            while (j>0 && dp[i][j-1]==nextJ)
                --j;                
        }        

        vector<int> ans1(N+1,0);
        int cout1=0;
        for(auto i:result1)
        {
            for(auto j:AllGroup[i-1])
            {
                ans1[j]=1;
                ++cout1;
            }
        }

        vector<int> ans2(N+1,0);
        int cout2=0;
        for(auto i:result2)
        {
            for(auto j:AllGroup[i-1])
            {
                ans2[j]=1;
                ++cout2;
            }
        }        

        // for(auto[x,y]:edge)
        // {
        //     cout << x << " " << y << "\n";
        // }

        cout << "Case #" << caseId << ": ";
        if(abs(N-cout1-cout1)<abs(N-cout2-cout2))
        {
            for (int i = 1; i <= N; ++i)
                cout <<ans1[i];
            
            //cout << " " << abs(N-cout1-cout1);
        }    
        else 
        {
            for (int i = 1; i <= N; ++i)
                cout <<ans2[i];
            
            //cout << " " << abs(N-cout2-cout2);
        }    
        
        cout << "\n";
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    //freopen("FB_2019_ROUND_2_B.in", "r", stdin);
    freopen("bitstrings_as_a_service_input.in", "r", stdin);
    freopen("FB_2019_ROUND_2_B.ok", "w", stdout);
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