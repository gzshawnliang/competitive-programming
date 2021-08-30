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
    vector<ill> C;
    vector<ill> sumC;
    vector<vector<int>> g;
    vector<int> visited;
    vector<int> parent;
    ill maxC;
    int root;
    int maxValueLeaf;
    vector<int> jionRoot;
    vector<int> disjionRoot;
    void dfs(int s,int p)
    {
        if(visited[s]==0)
        {
            parent[s]=p;
            visited[s]=1;
            if(p==0)
                sumC[s]=C[s];
            else
                sumC[s]=C[s]+sumC[p];
            
            if(sumC[s] > maxC)
                maxValueLeaf=s;

            maxC=max(maxC,sumC[s]);

            for (int i = 0,len=g[s].size(); i <= len-1; ++i)
                if(g[s][i]>1)
                    dfs(g[s][i],s);
        }

    }

  public:
    void solve()
    {
        int T;
        cin>>T;
        for (int caseId = 1; caseId <= T; ++caseId)
        {
            int N,K,ans;
            cin >> N >> K;
            C.assign(N+1,0);
            sumC.assign(N+1,0);
            visited.assign(N+1,0);
            jionRoot.assign(N+1,0);
            jionRoot[1]=1;
            disjionRoot.clear();

            parent.assign(N+1,1);
            for (int i = 1; i <= N; ++i)
                cin >> C[i];

            

            g.assign(N + 1, vector<int>());

            for (int i = 1; i <= N - 1; ++i)
            {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            ans = 0;
            if(K>=1)
            {
                vector<ill> ansSet;
                for (int i = 0,len=g[1].size(); i <= len-1; ++i)
                {
                    maxC=0;
                    root=g[1][i];
                    maxValueLeaf=0;
                    dfs(root,0);
                    ansSet.push_back(maxC);
                    if(maxValueLeaf>0)
                    {
                        int p=maxValueLeaf;
                        while (p>1)
                        {
                            jionRoot[p]=1;
                            //cout << p << " ";
                            p=parent[p];
                        }
                        //cout << '\n';
                    }
                }

                for (int i = 1; i <= N; ++i)
                {
                    if(jionRoot[i]==0)                    
                        disjionRoot.push_back(i);
                }
                
                sort(ansSet.begin(),ansSet.end(),greater<int>());
                if(ansSet.size()>=2)
                    ans +=(ansSet[0]+ansSet[1]);
                else if(ansSet.size()>=1)
                    ans +=(ansSet[0]);

                int currDrill = 1;
                while(K>currDrill)
                {
                    ++currDrill;
                }
            }

            ans += C[1];
            cout << "Case #"<< caseId <<": " << ans << "\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C2.in", "r", stdin);
    freopen("C2.txt", "w", stdout);
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
