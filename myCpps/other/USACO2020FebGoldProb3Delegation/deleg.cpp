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

    void dfs(int c, int p)
    {
        sub[c] = 1;
        for (auto s : g[c])
        {
            if (s != p)
            {
                dfs(s, c);
                son[c].push_back(sub[s]);
                sub[c] += sub[s];
            }
        }

        if (N - sub[c] > 0)
            son[c].push_back(N - sub[c]);
    }

    int check(int k)
    {
        if ((N - 1) % k != 0)
            return 0;

        if (k == 1)
            return 1;

        vector<int> cnt(k + 1); //cnt[1] 代表长度为1的链目前有多少条

        for (int i = 1; i <= N; ++i)
        {
            int noMatchCout = 0; //不匹配数量,如果大于0代表不匹配
            for (auto c : son[i])
            {
                int m = c % k;
                if (m == 0) //直接匹配
                    continue;

                ++cnt[m]; //增加长度是m链的数量

                int need = k - m; //m需要一条k-m的链,才能凑成k的链

                if (cnt[need] > 0) //找到need，匹配
                {
                    --cnt[need];   //取出need链，减少数量
                    --cnt[m];      //取出m链，减少数量
                    --noMatchCout; //减少不匹配数量
                }
                else //找不到匹配的need
                {
                    ++noMatchCout; //增加不匹配数量
                }
            }

            if (noMatchCout > 0) //存在不匹配的情况
                return 0;
        }

        return 1;
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
        for (int k = 1; k <= N - 1; ++k)
            cout << check(k);
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