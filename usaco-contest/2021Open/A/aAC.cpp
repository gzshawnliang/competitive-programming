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

struct Node
{
    int v;
    int flag;
};

Node _Node(int v, int flag)
{
    Node temp{v, flag};
    return temp;
};

class SegTree
{
  private:
    int sizeA;
    vector<int> a;
    vector<Node> _segTree;

    int query(int l, int r, int i, int nowLeft, int nowRight)
    {
        if (nowRight < l || nowLeft > r)
        {
            return 0;
        }
        
        if(_segTree[i].flag !=0)
        {
            _segTree[i].v += ((nowRight - nowLeft + 1) * _segTree[i].flag);
            if(nowLeft != nowRight)
            {
                _segTree[i * 2].flag += _segTree[i].flag;
                _segTree[i * 2 + 1].flag += _segTree[i].flag;
            }
            _segTree[i].flag = 0;
        }

        if (nowLeft >=l && nowRight <=r)
        {
            return _segTree[i].v;
        }        

        int m = (nowLeft + nowRight) / 2;

        return query(l, r, i * 2, nowLeft, m) + query(l, r, i * 2 + 1, m + 1, nowRight);
    }

    void update(int l, int r, int v, int i, int nowLeft, int nowRight)
    {
        if(_segTree[i].flag !=0)
        {
            _segTree[i].v += ((nowRight - nowLeft + 1) * _segTree[i].flag);
            if(nowLeft != nowRight)
            {
                _segTree[i * 2].flag += _segTree[i].flag;
                _segTree[i * 2 + 1].flag += _segTree[i].flag;
            }
            _segTree[i].flag = 0;
        }

        if (r < nowLeft || l > nowRight)
        {
            return;
        }

        if (nowLeft >= l && nowRight <= r)
        {
            _segTree[i].v += v*(nowRight - nowLeft + 1);
            
            if (nowLeft != nowRight)
            {
                _segTree[i * 2].flag += v;
                _segTree[i * 2 + 1].flag += v;
            }            
            return;
        }        

        int m = (nowLeft + nowRight) / 2;

        update(l, r, v, i * 2, nowLeft, m);
        update(l, r, v, i * 2 + 1, m + 1, nowRight);
        _segTree[i].v = _segTree[i * 2].v + _segTree[i * 2+1].v;
    }

  public:
    SegTree(int siz)
    {
        a.assign(siz, 0);
        sizeA = siz;
        _segTree.assign(sizeA * 4, _Node(0, 0));
    }

    int query(int l, int r)
    {
        return query(l, r, 1, 0, sizeA - 1);
    }

    void update(int l, int r, int v)
    {
        update(l, r, v, 1, 0, sizeA - 1);
    }
};

class solution
{
  public:
    void solve()
    {
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        vector<vector<int>> pos(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        auto cntInv=[&](int l, int r, int val)
        {
            int ansLm1 = upper_bound(pos[val].begin(), pos[val].end(), l - 1) - pos[val].begin();
            int ansR = upper_bound(pos[val].begin(), pos[val].end(), r) - pos[val].begin();

            return ansR - ansLm1;
        };

        vector<int> preN(n + 1, 0);
        vector<vector<int>> preNInd(n + 1);
        for (int ind = 1; ind <= n; ++ind)
        {
            int ans = lower_bound(pos[a[ind]].begin(), pos[a[ind]].end(), ind) - pos[a[ind]].begin();
            if (ans == 0) preN[ind] = 1;
            else          preN[ind] = pos[a[ind]][ans - 1] + 1;
            preNInd[preN[ind]].push_back(ind);
        }

        vector<int> bacN(n + 1, 0);
        for (int ind = 1; ind <= n; ++ind)
        {
            int ans = lower_bound(pos[a[ind]].begin(), pos[a[ind]].end(), ind) - pos[a[ind]].begin();

            int siz = pos[a[ind]].size();
            if (ans == siz - 1) bacN[ind] = n;
            else                bacN[ind] = pos[a[ind]][ans + 1] - 1;
        }

        SegTree tree(n + 1);
        ill ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (auto x:preNInd[i]) tree.update(x, x, 1);
            ans += tree.query(i + 1, bacN[i]);
            // for (int j = i + 1; j <= bacN[i]; ++j)
            //     if (preN[j] <= i)
            //         ++ans;
        }

        cout << ans << '\n';
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