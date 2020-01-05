#include <bits/stdc++.h>

using namespace std;

ifstream fin("sleepy.in");
ofstream fout("sleepy.out");

class fenwickTree
{
    private:

    vector<int> a;
    vector<int> s;

    int lowbit(int x)
    {
        return x & (-x);
    }

    public:

    fenwickTree(vector<int> & in)
    {
        int n = in.size();

        a.assign(n, 0);
        s.assign(n + 1, 0);

        for (int i = 0; i <= n - 1; ++i)
        {
            update(i, in[i]);
        }
    }

    void update(int k, int delta)
    {
        ++k;

        a[k - 1] += delta;

        int n = s.size() - 1;

        for (int i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    int query(int k)
    {
        ++k;

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
    int n; fin >> n;

    int maxE = 0;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];

        maxE = max(maxE, a[i]);
    }

    int incCount = 1;
    vector<int> backA(maxE + 1, 0); backA[a.back()] = 1;
    for (int i = n - 2; i >= 0 && a[i] < a[i + 1]; --i)
    {
        backA[a[i]] = 1;
        ++incCount;
    }

    fenwickTree tree(backA);

    fout << n - incCount << '\n';
    for (int i = 0; i <= n - 1 - incCount; ++i)
    {
        int now = a[i];

        int pos = tree.query(now);
        tree.update(now, 1);
        
        if (i > 0) fout << ' ';
        fout << pos + n - incCount - i - 1;

    }
    fout << '\n';

    return 0;
}
