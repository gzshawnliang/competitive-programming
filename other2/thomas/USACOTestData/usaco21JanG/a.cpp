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
    vector<vector<int>> g; //g[i->j]第i->j个牛有条边
    vector<int> vist;      //第i个牛是否访问过

    vector<int> currPos;                   //第i个牛现在的位置
    vector<unordered_set<int>> vistPosSet; //第i个牛到过的地方
    vector<int> fa;                        //第i个牛的父亲，同一个环父亲一样

    void swapPos(int a, int b)
    {
        vistPosSet[currPos[a]].insert(b);
        vistPosSet[currPos[b]].insert(a);
        swap(currPos[a], currPos[b]);
    }

    int find(int x)
    {
        if (fa[x] != x)
            fa[x] = find(fa[x]);

        return fa[x];
    }

    void dfs(int p, int c, int first)
    {
        if (vist[c] == 1 && c != first)
            return;

        vist[c] = 1;
        fa[c] = p;
        for (auto i : g[c])
        {
            if (i == c)
                return;

            dfs(c, i, first);
        }
    }

  public:
    void solve()
    {
        ill n, k, m;
        cin >> n >> k >> m;
        currPos = vector<int>(n + 1);
        fa = vector<int>(n + 1);
        g = vector<vector<int>>(n + 1, vector<int>());
        vist = vector<int>(n + 1);
        vistPosSet = vector<unordered_set<int>>(n + 1);

        //初始位置
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = i;
            currPos[i] = i;
            vistPosSet[i].insert(i);
        }

        //模拟交换k次，如果m<k则m次
        queue<pair<int, int>> q;
        ill sw = min(k, m);
        for (int i = 1; i <= sw; ++i)
        {
            int ai, bi;
            cin >> ai >> bi;
            q.push({ai, bi});
            swapPos(ai, bi);
        }

        if (m == (ill)1e18)
        {
            //建图
            for (int i = 1; i <= n; ++i)
                g[i].push_back(currPos[i]);

            //在图中找环，填充fa[i]数组
            for (int i = 1; i <= n; ++i)
                if (vist[i] == 0)
                    dfs(i, i, true);

            //合并currPos[i]和i，他们是同属于一个环
            for (int i = 1; i <= n; ++i)
            {
                int fx = find(i);
                int fy = find(currPos[i]);

                if (fx != fy)
                    fa[fy] = fx;
            }
            //把同一个环中经过的位置合并到根节点
            for (int i = 1; i <= n; ++i)
                vistPosSet[fa[i]].insert(vistPosSet[i].begin(), vistPosSet[i].end());

            for (int i = 1; i <= n; ++i)
                cout << vistPosSet[fa[i]].size() << "\n";
        }
        // else if(n<=100 && k <=200)
        // {
        //     if(m>k)
        //     {
        //         for (int i = k+1; i <= m; ++i)
        //         {
        //             auto s=q.front();
        //             q.pop();
        //             int ai=s.first;
        //             int bi=s.second;
        //             swapPos(ai,bi);
        //             q.push(s);
        //         }
        //     }

        //     for (int i = 1; i <= n; ++i)
        //         cout << vistPosSet[i].size() << "\n";

        // }
        else
        {
            //建图
            for (int i = 1; i <= n; ++i)
                fa[currPos[i]] = i;

            // for(int i=1;i<=n;++i)
            //     g[i].push_back(currPos[i]);

            // //在图中找环，填充fa[i]数组
            // for(int i=1;i<=n;++i)
            //     if(vist[i]==0)
            //         dfs(i,i,i);

            ill roundCnt = m / k;          //牛交换的回合数
            ill remCnt = m - roundCnt * k; //完成交换回合数之后，还需要交换remCnt次

            

            //模拟交换
            for (int i = 2; i <= roundCnt; ++i) //已经跑了一回合，i从2开始
            {
                vector<unordered_set<int>> vistPosSet2 = vistPosSet;
                for (int j = 1; j <= n; ++j)
                {
                    if (currPos[j] != j)
                    {
                        //vistPosSet2[currPos[j]].insert(vistPosSet[currPos[j]].begin(),vistPosSet[currPos[j]].end());
                        vistPosSet2[currPos[j]].insert(vistPosSet[j].begin(), vistPosSet[j].end());
                    }
                }
                vistPosSet = vistPosSet2;
            }

            //模拟交换p次数
            for (int i = 1; i <= remCnt; ++i)
            {
                auto s = q.front();
                q.pop();
                swapPos(s.first, s.second);
                q.push(s);
            }

            for (int i = 1; i <= n; ++i)
                cout << vistPosSet[i].size() << "\n";
        }
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