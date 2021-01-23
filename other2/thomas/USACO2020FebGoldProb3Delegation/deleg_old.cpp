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
    int n;
    vector<vector<int>> g;   //邻接矩阵判断相邻关系
    vector<vector<int>> son; //son[2]代表以2为根，2的儿子们分别有多少个链,例如son[2]={1,2,8,1}；
    vector<int> sub;         //sub数组表示子树的数量

    //dfs求son[][]
    void dfs(int child, int father)
    {
        sub[child] = 1;
        for (auto c : g[child])
        {
            if (c != father)
            {
                dfs(c, child);
                sub[child] += sub[c];
                son[child].push_back(sub[c]);
            }
        }
        if (sub[child] != n)
            son[child].push_back(n - sub[child]);
    }

    //长度K是否满足
    int check(int k)
    {
        if ((n - 1) % k != 0) //特判，如果不能整除，说明不能均分
            return 0;

        vector<int> c(k + 1); //c[i]表示长度是i的链的数量

        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0; //cnt代表不匹配的数量
            for (auto s : son[i])
            {
                int m = s % k;
                if (m == 0)
                    continue;

                if (c[k - m] > 0) //可以配对，减少不匹配链的数量
                {
                    --c[k - m];
                    --cnt;
                }
                else //如果不能配对，保留，增加不匹配链的数量
                {
                    ++c[m];
                    ++cnt;
                }
            }

            if (cnt > 0) //如果有落单(不能匹配)的说明不行
                return 0;
        }
        return 1;
    }

  public:
    int solve()
    {
        cin >> n;
        g = vector<vector<int>>(n + 1);
        son = vector<vector<int>>(n + 1);
        sub = vector<int>(n + 1);

        for (int i = 1; i <= n - 1; ++i)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, 0);
        for (int i = 1; i <= n - 1; ++i)
            cout << check(i);
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