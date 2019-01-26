#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>


using namespace std;

ifstream fin("tempCode1.in");
ofstream fout("tempCode1.out");

class fenwickTree
{
    private:
    int lowbit(int x)
    {
        return x & (-x);
    }

    public:
    vector<int> num;
    vector<int> c;

    fenwickTree(vector<int> & in)
    {
        int n = in.size();

        num = in;
        c.assign(n, INT_MAX);

        for (int i = 1; i <= n; ++i)
        {
            add(i, num[i]);
        }
    }

    void add(int x, int d)
    {
        int n = c.size();

        num[x] = d;
        while (x <= n)
        {
            if (c[x] > d)
            {
                c[x] = d;
            }
            else
                break;
            x = x + lowbit(x);
        }
    }

    int find_c(int l, int r)
    {
        int n = c.size();

        int ans = num[r];
        while (l != r)
        {
            r--;
            while (r - lowbit(r) > l)
            {
                ans = min(ans, c[r]);
                r -= lowbit(r);
            }
            ans = min(ans, num[r]);
        }
        return ans;
    }
};

int main()
{
    vector<int> temp = {0, 2,11,5,17,15,10,19};
    fenwickTree t(temp);

    t.add(1, 213);

    fout << t.find_c(1, 7) << '\n';

    return 0;
}
