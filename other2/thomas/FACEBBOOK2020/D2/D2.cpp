#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill INF = LONG_LONG_MAX;

class solution
{
    vector<pair<int,int>> treeP;
    vector<vector<int>> treeMatrix;
    vector<int> depth;    
    vector<int> mainPath;
    vector<int> isMainPath;
    vector<vector<pair<int,int>>> mainPathData;

    // void dfs(int curr,int p)
    // {
    //     depth[curr]=depth[p]+1;
    //     for (int i = 0,len=treeMatrix[curr].size(); i <= len - 1; ++i)
    //     {
    //         dfs(treeMatrix[curr][i],curr);
    //     }
    // }

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
        int N,M,A,B;
        cin >> N>>M>>A>>B;
        treeP = vector<pair<int,int>>(N+1);
        mainPathData = vector<vector<pair<int,int>>>(N+1);

        for (int i = 1; i <= N; ++i)
        {
            int Pi,Ci;
            cin >> Pi>>Ci;
            treeP[i]= make_pair(Pi,Ci);
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

        //dfs(root,0);
        depth[root]=0;
        dfsMainPath(mainPath.back(),root,0);



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