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

#define a first
#define b second

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
            int ai,bi;
            cin>> ai>>bi;
            if(i==1)
                firstPos=make_pair(ai,bi);

            q.push({ai,bi});
        }

        while (true)
        {
            auto curr = q.front();
            q.pop();
            
            pos3[pos2[curr.a]].insert(curr.b);
            pos3[pos2[curr.b]].insert(curr.a);

            swap(pos2[curr.a],pos2[curr.b]);

            if (pos2[curr.a] != curr.a)
                pos.set(curr.a);
            else
                pos.set(curr.a, 0);

            if (pos2[curr.b] != curr.b)
                pos.set(curr.b);
            else
                pos.set(curr.b, 0);
            
            q.push(curr);

            if (pos.none())
                break;
        }

        for (int i = 1; i <= n; ++i)
            cout << pos3[i].size() << "\n";
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