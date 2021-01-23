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
    int N;
    vector<vector<int>> g;   //邻接矩阵判断相邻关系
    vector<vector<int>> son; //son[2]代表以2为根，2的儿子里面子树节点数,例如son[2]={1,2,8,1}；
    vector<int> sub;         //totleSon[2]代表以2为根，2的子树节点总数,包括2本身

    void dfs(int c,int p)
    {
        sub[c]=1;
        for(auto s:g[c])
        {
            if (s != p)
            {
                dfs(s,c);
                son[c].push_back(sub[s]);
                sub[c] += sub[s];
            }
        }

        if(N-sub[c]>0)
            son[c].push_back(N-sub[c]);
    }

  public:
    int solve()
    {
        cin >> N;
        g = vector<vector<int>>(N + 1);
        son = vector<vector<int>>(N + 1);

        sub = vector<int>(N + 1);

        for (int i = 1; i <= N - 1; ++i)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
         dfs(1, 0);
        // for (int i = 1; i <= n - 1; ++i)
        //     cout << check(i);
        return 0;
    }
};

signed main()
{
    FastIO;

    //#ifdef LOCAL_DEBUG
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    //#endif

    solution sln1;
    sln1.solve();
    cout.flush();

    return 0;
}