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
  public:
    void solve()
    {
        bitset<100001> pos;
        queue<pair<int,int>> q;
        int n,k;
        cin >>n>>k;
        pair<int,int> firstPos;
        vector<int> pos2(n+1);
        vector<unordered_set<int>> pos3(n+1);
        for (int i = 1; i <= n; ++i)
        {
            pos2[i] = i;
            pos3[i].insert(i);
        }

        for (int i = 1; i <= k; ++i)
        {
            int a,b;
            cin>> a>>b;
            if(i==1)
                firstPos=make_pair(a,b);

            q.push({a,b});
        }

        while (true)
        {
            auto curr = q.front();
            q.pop();
            
            pos3[pos2[curr.first]].insert(curr.second);
            pos3[pos2[curr.second]].insert(curr.first);

            swap(pos2[curr.first],pos2[curr.second]);

            if (pos2[curr.first] != curr.first)
                pos.set(curr.first);
            else
                pos.set(curr.first, 0);

            if (pos2[curr.second] != curr.second)
                pos.set(curr.second);
            else
                pos.set(curr.second, 0);
            
            q.push(curr);

            if (pos.none())
                break;
        }

        for (int i = 1; i <= n; ++i)
        {
            cout << pos3[i].size() << "\n";
        }

    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
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