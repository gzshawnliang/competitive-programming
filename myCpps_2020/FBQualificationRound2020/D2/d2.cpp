#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const ill inf = LLONG_MAX / 2;

class SegTree
{
  private:
    ill sizeA;           //原数组的大小
    vector<ill> segTree; //线段树的数组

    void build(ill l, ill r, ill i)
    {
        if (i > sizeA * 4 - 1)
            return;

        if (l == r)
        {
            segTree[i] = a[l];
            return;
        }

        ill m = (l + r) / 2;

        build(l, m, i * 2);
        build(m + 1, r, i * 2 + 1);

        segTree[i] = min(segTree[i * 2], segTree[i * 2 + 1]);
    }

    ill query(ill l, ill r, ill i, ill nowLeft, ill nowRight)
    {
        if (nowRight < l || r < nowLeft)
        {
            return inf;
        }
        if (nowLeft >= l && nowRight <= r)
        {
            return segTree[i];
        }

        ill m = (nowLeft + nowRight) / 2;

        return min(query(l, r, i * 2, nowLeft, m), query(l, r, i * 2 + 1, m + 1, nowRight));
    }

    void update(ill pos, ill _new, ill i, ill nowLeft, ill nowRight)
    {
        if (pos < nowLeft || pos > nowRight)
        {
            return;
        }        

        if (nowLeft == nowRight)
        {
            a[pos] = _new;
            segTree[i] = _new;
            return;
        }

        ill m = (nowLeft + nowRight) / 2;
        update(pos, _new, i * 2, nowLeft, m);
        update(pos, _new, i * 2 + 1, m + 1, nowRight);
        //segTree[i] = max(update(pos, _new, i * 2, nowLeft, m), update(pos, _new, i * 2 + 1, m + 1, nowRight));
        segTree[i] = min(segTree[i*2],segTree[i*2+1]);
    }

  public:
    vector<ill> a;       //原数组

    SegTree(const vector<ill> & p_Sour)
    {
        a = p_Sour;
        sizeA = a.size();
        segTree.assign(sizeA * 4, inf);

        build(0, sizeA-1, 1);
    }

    ill query(ill l, ill r)
    {
        return query(l, r, 1, 0, sizeA-1);
    }

    void update(ill index, ill newVal)
    {
        update(index, newVal, 1, 0, sizeA-1);
    }
};

class solution
{
    ill N, M;
    vector<ill> parent, cost, mPth, isMPth, f, branch;
    vector<vector<ill>> g;

    void dfs(ill u, ill d)
    {
        if (d > M - 1) return;

        if      (d >= branch.size())                       branch.push_back(u);
        else if (cost[branch[d]] > cost[u] && cost[u] > 0) branch[d] = u;

        for (auto v:g[u])
            if (isMPth[v] == 0)
                dfs(v, d + 1);
    }

  public:

    // void solve()
    // {
    //     vector<ill> a = {1, 2, 3, 4, 5};
    //     SegTree tree(a);

    //     cout << tree.query(3, 4) << '\n';
    //     tree.update(4, 0);
    //     cout << tree.query(3, 4) << '\n';
    // }

    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            
            ill A, B; cin >> N >> M >> A >> B;
            //cerr << tcc << ": " << N << " " << M << " " << A << " " << B << "\n";

            parent = vector<ill>(N + 1, 0);
            cost = vector<ill>(N + 1, inf);
            for (ill u = 1; u <= N; ++u) cin >> parent[u] >> cost[u];
            
            ill root = B, u1 = B;
            vector<ill> pth2R;
            while (u1 > 0)
            {
                pth2R.push_back(u1);
                u1 = parent[u1];
            }

            parent[root] = 0;
            for (ill i = 1, siz = pth2R.size(); i <= siz - 1; ++i)
                parent[pth2R[i]] = pth2R[i - 1];
            
            g = vector<vector<ill>>(N + 1);
            for (ill u = 1; u <= N; ++u)
                g[parent[u]].push_back(u);

            ill u2 = A;
            mPth.clear();
            isMPth = vector<ill>(N + 1, 0);
            while (u2 > 0)
            {
                mPth.push_back(u2);
                isMPth[u2] = 1;
                u2 = parent[u2];
            }

            ill sizMP = mPth.size();
            f = vector<ill>(sizMP, inf); f[0] = 0;
            SegTree tree(f);
            for (ill i = 1; i <= sizMP - 1; ++i)
            {
                ill now = mPth[i];
                branch = vector<ill>(1, 0);
                dfs(now, 0);

                if (cost[now] > 0)
                {
                    tree.update(i, tree.query(max(0LL, i - M), i - 1) + cost[now]);
                }

                for (ill d = 1, siz = branch.size(); d <= min(M - 1, min(i, siz - 1)); ++d)
                {
                    ill u = branch[d];
                    if (cost[u] == 0) continue;

                    ill tmp = tree.query(max(0LL, i - M + d), i - 1) + cost[u];
                    if (tree.a[i - d] > tmp) tree.update(i - d, tmp);
                }
            }

            ill ans = tree.query(max(0LL, sizMP - M - 1), sizMP - 1);
            
            cout << "Case #" << tcc << ": " << (ans == inf ? -1 : ans) << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("d2.in", "r", stdin);
    freopen("d2.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}