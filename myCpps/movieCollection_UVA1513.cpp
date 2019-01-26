#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("movieCollection_UVA1513.in");
ofstream fout("movieCollection_UVA1513.out");

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
        int n, m; fin >> n >> m;

        vector<int> temp(n + m + 1, 0), pos(n + 1, 0);

        for (int i = m + 1; i <= m + n; ++i)
        {
            temp[i] = 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            pos[i] = m + i;
        }

        fenwickTree tree(temp);

        int j = m;
        for (int c = 1; c <= m; ++c)
        {
            if (c > 1) fout << ' ';

            int r; fin >> r;

            fout << tree.query(pos[r]) - 1;

            tree.update(pos[r], -1);
            tree.update(j, 1);

            pos[r] = j;
            --j; 
        }
        fout << '\n';
    }

    return 0;
}
