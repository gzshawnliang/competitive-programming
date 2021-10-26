#include<bits/stdc++.h>

using namespace std;

class fenwickTree1index
{
    private:

    int lowbit(int x)
    {
        return (x & (-x));
    }

    public:

    vector<int> a;
    vector<int> s;

    fenwickTree1index(vector<int> & in)
    {
        int n = in.size();

        a.assign(n, 0);
        s.assign(n, 0);

        for (int i = 1; i <= n - 1; ++i)
        {
            update(i, in[i]);
        }
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

        int n = s.size();

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
    vector<int> a = {6,16,2,13,20,11,14,14,13,6};

    fenwickTree tree(a);

    // for (int i = 0; i <= (int)a.size() - 1; ++i)
    // {
    //     cout << tree.query(i) << '\n';
    // }

    cout << tree.sum(1, 2) << '\n';

    return 0;
}