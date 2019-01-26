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

ifstream fin("potentiometers_UVA12086.in");
ofstream fout("potentiometers_UVA12086.out");

class fenwickTree
{
    private:

    int lowbit(int x)
    {
        return x & (-x);
    }

    public:

    vector<long long> a;
    vector<long long> s;

    fenwickTree(vector<long long> & in)
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
        long long ans = 0;

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
    int testCase = 0;
    while (true)
    {
        ++testCase;

        int n; fin >> n;
        if (n == 0) break;

        if (testCase > 1) fout << '\n';
        fout << "Case " << testCase << ":\n";

        vector<long long> a(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            fin >> a[i];
        }

        fenwickTree tree(a);

        while (true)
        {
            string in; fin >> in;
            if (in == "END") break;

            int x, y; fin >> x >> y;

            if (in == "M")
            {
                fout << tree.sum(x, y) << '\n';
            }
            else
            {
                tree.update(x, y - tree.a[x]);
            }
        }
    }

    return 0;
}
