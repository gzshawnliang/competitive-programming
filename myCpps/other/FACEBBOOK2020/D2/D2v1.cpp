#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill INF = LLONG_MAX /2 ;

class solution
{
    vector<pair<int,int>> treeP;
    vector<vector<int>> treeMatrix;
    vector<ill> dp;    
    vector<int> depth;    
    vector<int> mainPath;
    vector<int> isMainPath;
    vector<vector<pair<int,int>>> mainPathData;
    vector<vector<int>> mainPathData2;

    int N,M;
    // void dfs(int curr,int p)
    // {
    //     depth[curr]=depth[p]+1;
    //     for (int i = 0,len=treeMatrix[curr].size(); i <= len - 1; ++i)
    //     {
    //         dfs(treeMatrix[curr][i],curr);
    //     }
    // }

    void dfsNode(int curr,int p,int depth)
    {
        if(depth>=M)
            return;
        
        if(depth>0 && curr !=p)
        {
            if((int)mainPathData2[p].size()<depth)
                mainPathData2[p].push_back(curr);
            else 
            {

                if(treeP[curr].second < treeP[mainPathData2[p][depth-1]].second)
                    mainPathData2[p][depth-1] = curr;
            }
        }

        for (int i = 0,len=treeMatrix[curr].size(); i <= len - 1; ++i)
        {
            if(isMainPath[treeMatrix[curr][i]]==0)
                dfsNode(treeMatrix[curr][i],p,depth+1);
        }        
    }

    void dfsMainPath(int curr,int p,int mainPathPoint)
    {
        depth[curr]=depth[p]+1;

        if(isMainPath[curr]==1)
        {
            mainPathPoint=curr;
        }

        for (int i = 0,len=treeMatrix[curr].size(); i <= len - 1; ++i)
        {
            dfsMainPath(treeMatrix[curr][i],curr,mainPathPoint);
        }

        if(isMainPath[curr]==0)
        {
            int mainPathDepth=depth[curr]-depth[mainPathPoint];
            mainPathData[mainPathPoint].push_back({mainPathDepth,treeP[curr].second});
            // if(mainPathData[mainPathPoint].size()==0)
            //     mainPathData[mainPathPoint].push_back({mainPathDepth,treeP[curr].second});
            // else if (treeP[curr].second < mainPathData[mainPathPoint].back().second) 
            //     mainPathData[mainPathPoint].push_back({mainPathDepth,treeP[curr].second});
        }
    }    

  public:

    void solve(int T)
    {
        int A,B;
        cin >> N>>M>>A>>B;
        treeP = vector<pair<int,int>>(N+1);
        //cerr << "T-N:" << T << "-" << N << "\n";

        mainPathData2=vector<vector<int>>(N+1);
        mainPathData = vector<vector<pair<int,int>>>(N+1);

        for (int i = 1; i <= N; ++i)
        {
            int Pi,Ci;
            cin >> Pi>>Ci;
            treeP[i]= make_pair(Pi,Ci);
        }

        if(N>=1e6)
        {
            cout << "Case #" << T <<": " << N << "\n";
            return;        
        }

        //Change Root to B
        int root =B;
        int curr =B;
        vector<int> path;
        while (true)
        {
            path.push_back(curr);
            curr = treeP[curr].first;
            if(curr==0)
                break;
        }
        treeP[root].first=0;
        for (int i = 1,len=path.size(); i <= len - 1; ++i)
        {
            treeP[path[i]].first =path[i-1];
        }

        //Make Tree Matrix
        treeMatrix= vector<vector<int>>(N+1);
        depth=vector<int>(N+1,-1);
       
        for (int i = 1; i <= N; ++i)
        {
            treeMatrix[treeP[i].first].push_back(i);
        }

        // for (int i = 1; i <= N; ++i)
        // {
        //     for (int j = 0,len=treeMatrix[i].size(); j <= len-1; ++j)
        //     {
        //         cout << i << " " << treeMatrix[i][j] << "\n";
        //     }
        // }
        //cout << "\n";


        //fill mainPath
        curr =A;
        isMainPath=vector<int>(N+1);
        while (true)
        {
            mainPath.push_back(curr);
            curr = treeP[curr].first;
            if(curr==0)
                break;
        }           
        mainPath.pop_back();

        for (int i = 0,len=mainPath.size(); i <= len - 1; ++i)
        {
            isMainPath[mainPath[i]]=1;
        }
        
        dp = vector<ill>(mainPath.size() + 1, INF);
        dp[0]=0;
        multiset<ill> st; 
        st.insert(0);
        for (int i = 1,len=mainPath.size(); i <= len - 1; ++i)
        {
            if (st.empty()) 
                break;
            int curr=mainPath[i];
            mainPathData2[curr].clear();
            dfsNode(curr,curr,0);
            
            if(treeP[curr].second>0)
            {
                dp[i] = *st.begin();
                dp[i] += treeP[curr].second;
                
                st.insert(dp[i]);
            }
            for (int d=1;d <=M-1 && i-d>=0;++d)
            {
                //int pre =mainPath[i-d];
                if((int)mainPathData2[curr].size()>=d)
                {
                    int replaceId = mainPathData2[curr][d-1];
                    if(treeP[replaceId].second==0)
                        continue;
                    for (int k = 1; k <= M-d; ++k)
                    {
                        if(i-k<0)
                            break;

                        if(dp[i-k]==INF)
                            continue;

                        //int replaceValue = (dp[i - k] == INF ? 0 : dp[i - k]) + treeP[replaceId].second;
                        int replaceValue = dp[i - k] + treeP[replaceId].second;
                        if(replaceValue < dp[i - d])
                        {
                            if(dp[i - d] !=INF)
                            {
                                auto it = st.find(dp[i - d]);
                                if (it != st.end())
                                {
                                    st.erase(it);
                                    st.insert(replaceValue);
                                }
                                
                            }
                            dp[i - d] = replaceValue;
                        }                        
                    }
                }
            }

            if (i >= M && dp[i - M] != INF) 
            {
                auto it=st.find(dp[i - M]);
                 if (it != st.end())
                    st.erase(it);
            }            
        }

        ill ans = *min_element(dp.end()-M-1,dp.end()-1);
        ans =max(ans,0LL);
        cout << "Case #" << T <<": " << (ans==INF?-1:ans) << "\n";
        //cout << "Case #" << T <<": " << (ans==INF?-1:ans) << "  (" << N <<")\n";
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("D2.in", "r", stdin);
    //freopen("D2.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        solution sln1;
        sln1.solve(i);
        cout.flush();
    }

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}