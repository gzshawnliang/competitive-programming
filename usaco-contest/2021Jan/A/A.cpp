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
    const ill tolA = 26;
  public:
    void solve()
    {
        string s; cin >> s;
        ill n = s.size(), cntm = 0;
        map<char, ill> mpmp;
        vector<ill> a(n + 1, 0), exist(n + 1, 0);
        for (ill i = 1; i <= n; ++i)
        {
            if (mpmp.count(s[i - 1]) == 0)
            {
                mpmp[s[i - 1]] = cntm++;
            }
            a[i] = mpmp[s[i - 1]];
        }

        vector<vector<ill>> g(tolA);
        vector<vector<ill>> bef(n + 2, vector<ill>(tolA, 0)), aft(n + 2, vector<ill>(tolA, 0));
        for (ill i = 1; i <= n; ++i)
        {
            for (ill alf = 0; alf <= tolA - 1; ++alf)
            {
                if (a[i] == alf)
                    bef[i][alf] = bef[i - 1][alf] + 1;
                else
                    bef[i][alf] = bef[i - 1][alf];
            }
        }
        for (ill i = n; i >= 0; --i)
        {
            for (ill alf = 0; alf <= tolA - 1; ++alf)
            {
                if (a[i] == alf)
                    aft[i][alf] = aft[i + 1][alf] + 1;
                else
                    aft[i][alf] = aft[i + 1][alf];
            }
        }

        vector<vector<pair<ill, ill>>> allCnt(tolA, vector<pair<ill, ill>>(tolA, {0, 0}));
        for (ill i = 0; i <= n - 1; ++i)
        {
            for (ill alf = 0; alf <= tolA - 1; ++alf)
            {
                allCnt[a[i]][alf].first += aft[i][alf];
                allCnt[a[i]][alf].second += bef[i][alf];
            }
        }

        vector<ill> inDegree(tolA);
        for (ill a1 = 0; a1 <= cntm - 1; ++a1)
        {
            for (ill a2 = a1 + 1; a2 <= cntm - 1; ++a2)
            {
                if (allCnt[a1][a2].first > allCnt[a1][a2].second)
                {
                    g[a1].push_back(a2);
                    ++inDegree[a2];
                }
                else if (allCnt[a1][a2].first < allCnt[a1][a2].second)
                {
                    g[a2].push_back(a1);
                    ++inDegree[a1];
                }
            }
        }

        queue<ill> q;
        for (ill i = 0; i <= cntm - 1; ++i)
            if (inDegree[i] == 0)
                q.push(i);

        vector<ill> topoOrder; //topoOrder 为拓扑序列
        while (!q.empty())
        {
            ill p = q.front();
            q.pop();                // 选一个入度为0的点，出队列
            topoOrder.push_back(p);
            for (auto y:g[p])
            {
                --inDegree[y];
                if (inDegree[y] == 0)
                    q.push(y);
            }
        }

        vector<ill> num(cntm, 0), cntP(cntm, 0);
        for (ill i = 0; i <= cntm - 1; ++i)
            num[topoOrder[i]] = i;

        ill ans = 0;
        for (ill i = 1; i <= n; ++i)
        {
            if (i > 1)
            {
                if (num[a[i - 1]] >= num[a[i]])
                {
                    ++ans;
                }
            }
        }
        ++ans;
        cout << ans << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
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