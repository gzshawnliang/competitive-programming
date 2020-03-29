#include <bits/stdc++.h>

using namespace std;

ifstream fin("haircut.in");
ofstream fout("haircut.out");

using ill = long long;

const ill maxN = 1e5 + 1;

class fenwickTree
{
    private:

    ill lowbit(ill x)
    {
        return x & (-x);
    }

    public:

    vector<ill> a;
    vector<ill> s;

    fenwickTree(vector<ill> & in)
    {
        ill n = in.size();

        a.assign(n, 0);
        s.assign(n, 0);
    }

    void update(ill k, ill delta)
    {
        ill n = s.size() - 1;

        a[k] += delta;

        for (ill i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    ill query(ill k)
    {
        ill ans = 0;

        for (ill i = k; i >= 1; i -= lowbit(i))
        {
            ans += s[i];
        }

        return ans;
    }

    ill sum(ill i, ill j)
    {
        return query(j) - query(i - 1);
    }
};


int main()
{
    ill n; fin >> n;

    vector<ill> a(n, 0);
        vector<vector<ill>> pos(maxN + 1);
    for (ill i = 0; i <= n - 1; ++i)
    {
        fin >> a[i]; ++a[i];
        pos[a[i]].push_back(i);
    }

    vector<ill> larges(n, 0);
        vector<ill> tmp(maxN + 1, 0);
            fenwickTree treT(tmp);
    for (ill i = 0; i <= n - 1; ++i)
    {
        treT.update(a[i], 1);
        larges[i] = i + 1 - treT.query(a[i]);
    }
    larges.insert(larges.begin(), -1);

    vector<ill> ans;
        fenwickTree treL(larges);
            for (ill i = 1; i <= n; ++i) treL.update(i, larges[i]);
    for (ill l = n; l >= 1; --l)
    {
        for (auto i:pos[l])
        {
            treL.update(i + 1, -treL.a[i + 1]);
        }
        
        ans.push_back(treL.query(n));
    }

    for (ill i = n - 1; i >= 0; --i)
    {
        fout << ans[i] << '\n';
    }

    return 0;
}
