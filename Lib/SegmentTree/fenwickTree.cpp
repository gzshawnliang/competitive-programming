#include<bits/stdc++.h>

using namespace std;

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

        a = in;
        s.assign(n + 1, 0);

        for (int i = 0; i <= n - 1; ++i)
        {
            update(i, a[i]);
        }
    }

    void update(int k, int delta)
    {
        ++k;

        int n = s.size();

        for (int i = k; i <= n - 1; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    int query(int k)
    {
        ++k;

        int n = s.size(), ans = 0;

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

    cout << tree.sum(1, 2) << '\n';

    return 0;
}