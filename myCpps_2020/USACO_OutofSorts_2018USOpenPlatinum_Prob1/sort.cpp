/*
===========================================================
* @Name:           Problem 1. Out of Sorts 
* @Author:         Shawn
* @create Time:    2020/3/23 20:41:17
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=840&lang=en
* @Description:    USACO 2018 US Open Contest, Platinum
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("sort.in");
ofstream fout("sort.out");

//using ill = long long;

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
    vector<pair<int, int>> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i].first; a[i].second = i;
    }
    sort(a.begin(), a.end());

    int ans = 1;
        vector<int> f(n + 1, 0);
        fenwickTree tre(f);
    for (int i = 0; i <= n - 1; ++i)
    {
        tre.update(a[i].second + 1, 1);
        ans = max(ans, i + 1 - tre.query(i + 1));
    }

    fout << ans << '\n';

    return 0;
}
