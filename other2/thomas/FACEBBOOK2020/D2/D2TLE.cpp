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
    vector<int> parent;
    vector<int> cost;
    vector<vector<int>> treeAdj;
    vector<ill> dp;    
    vector<int> mainPath;
    vector<int> isMainPath;

    vector<int> branch;

    int N,M;

    void dfsNode(int curr,int p,int depth)
    {
        if(depth>=M)
            return;
        
        if(depth>0 && curr !=p)
        {
            if((int)branch.size()<=depth)
                branch.push_back(curr);
            else if(cost[curr] >0 && cost[curr] < cost[branch[depth]]) 
                branch[depth] = curr;
        }

        for (int i = 0,len=treeAdj[curr].size(); i <= len - 1; ++i)
        {
            if(isMainPath[treeAdj[curr][i]]==0)
                dfsNode(treeAdj[curr][i],p,depth+1);
        }
    }

  public:

    void solve(int T)
    {
        int A,B;
        cin >> N>>M>>A>>B;
        parent = vector<int>(N+1);
        cost = vector<int>(N+1);
        cerr << "T-N:" << T << "-" << N << " " << M << "\n";

        for (int i = 1; i <= N; ++i)
            cin >> parent[i]>>cost[i];

        // if(N>=1e6)
        // {
        //     cout << "Case #" << T <<": " << N << "\n";
        //     return;        
        // }

        //Change Root to B
        int root =B;
        int curr =B;
        vector<int> path;
        while (true)
        {
            path.push_back(curr);
            curr = parent[curr];
            if(curr==0)
                break;
        }

        parent[root]=0;
        for (int i = 1,len=path.size(); i <= len - 1; ++i)
            parent[path[i]] =path[i-1];


        //Make Tree Matrix
        treeAdj= vector<vector<int>>(N+1);
        for (int i = 1; i <= N; ++i)
            treeAdj[parent[i]].push_back(i);
        

        // for (int i = 1; i <= N; ++i)
        // {
        //     for (int j = 0,len=treeAdj[i].size(); j <= len-1; ++j)
        //     {
        //         cout << i << " " << treeAdj[i][j] << "\n";
        //     }
        // }
        // cout << "\n";

        //fill mainPath
        curr =A;
        isMainPath=vector<int>(N+1);
        while (true)
        {
            mainPath.push_back(curr);
            curr = parent[curr];
            if(curr==0)
                break;
        }           
        //mainPath.pop_back();

        for (int i = 0,len=mainPath.size(); i <= len - 1; ++i)
            isMainPath[mainPath[i]]=1;
        
        
        dp = vector<ill>(mainPath.size() , INF);
        dp[0]=0;
        multiset<ill> st; 
        st.insert(0);
        for (int i = 1,len=mainPath.size(); i <= len - 1; ++i)
        {
            if (st.empty()) 
                break;

            int curr=mainPath[i];
            //branch.clear();
            branch.assign(1,0);
            dfsNode(curr,curr,0);
            
            if(cost[curr]>0)
            {
                dp[i] = *st.begin() + cost[curr]*1LL;
                st.insert(dp[i]);
            }

            for (int d=1;d <=M-1 && i-d>=0;++d)
            {
                if((int)branch.size()-1>=d)
                {
                    int replaceId = branch[d];
                    if(cost[replaceId]==0)
                        continue;

                    for (int k = 1; k <= M-d; ++k)  //从i-1 到 i-(M-d)找最小值
                    {
                        if(i-k<0)
                            break;

                        if(dp[i-k]==INF)
                            continue;

                        ill replaceValue = dp[i - k] + cost[replaceId]*1LL;
                        if(replaceValue < dp[i - d])
                        {
                            if(dp[i - d] !=INF)
                            {
                                auto it = st.find(dp[i - d]);
                                if (it != st.end())
                                    st.erase(it);
                            }
                            dp[i - d] = replaceValue;
                            st.insert(replaceValue);
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

        auto begin = dp.begin();
        if (M < (int)dp.size() - 1)
            begin = dp.end() - 1 - M;

        ill ans = *min_element(begin,dp.end());
        cout << "Case #" << T << ": " << (ans == INF ? -1 : ans) << "\n";
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
    freopen("D2.txt", "r", stdin);
    freopen("D2.out", "w", stdout);
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