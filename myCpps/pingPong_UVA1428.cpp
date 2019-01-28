#include <bits/stdc++.h>

using namespace std;

ifstream fin("pingPong_UVA1428.in");
ofstream fout("pingPong_UVA1428.out");

class fenwickTree
{
    private:

    int lowbit(int x)
    {
        return x & (-x);
    }

    public:

    vector<int> a;
    vector<int> s;

    fenwickTree(vector<int> & in)
    {
        int n = in.size();

        a.assign(n, 0);
        s.assign(n, 0);
    }

    void update(int k, int delta)
    {
        int n = s.size() - 1;

        a[k] += delta;

        for (int i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    int query(int k)
    {
        int n = s.size() - 1;
        int ans = 0;

        for (int i = k; i >= 1; i -= lowbit(i))
        {
            ans += s[i];
        }

        return ans;
    }

    int sum(int i, int j)
    {
        return query(j) - query(i - 1);
    }
};


int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int n; fin >> n;

        vector<int> s(100001, 0);
        fenwickTree treeL(s), treeR(s);

        vector<int> a(n, 0), l(n, 0), r(n, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        for (int i = 0; i <= n - 1; ++i)
        {
            treeL.update(a[i], 1);
            l[i] = treeL.query(a[i]);
        }

        for (int i = n - 1; i >= 0; --i)
        {
            treeR.update(a[i], 1);
            r[i] = treeR.query(a[i]);
        }

        long long ans = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            int minL = l[i] - 1, minR = r[i] - 1;
            ans += (minL * (n - i - 1 - minR) + (i - minL) * minR);
        } 

        fout << ans << '\n';
    }

    return 0;
}
