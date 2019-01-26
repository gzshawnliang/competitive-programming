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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase = 0;
    while (true)
    {
        ++testCase;

        int n; cin >> n;
        if (n == 0) break;

        if (testCase > 1) cout << '\n';
        cout << "Case " << testCase << ":\n";

        vector<long long> a(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }

        fenwickTree tree(a);

        while (true)
        {
            string in; cin >> in;
            if (in == "END") break;

            int x, y; cin >> x >> y;

            if (in == "M")
            {
                cout << tree.sum(x, y) << '\n';
            }
            else
            {
                tree.update(x, y - tree.a[x]);
            }
        }
    }

   	cout.flush();
   	return 0;
}

