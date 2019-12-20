#include <iostream>
//#include <cstdio>
#include <cstring>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <list>
#include <iterator>
#include <cmath>
#include <queue>

using namespace std;

int ans, first, second;
vector<int> child[10010];
int pre[10010];

bool dfs(int root)
{
    int res = 0;
    if (root == first || root == second)
        ++res;

    for (int i = 0;i < child[root].size();++i)
    {
        if (dfs(child[root][i]))
            ++res;
        if (res >= 2)
        {
            ans = root;
            throw int();
        }
    }

    if (res == 1)
        return true;
    else
        return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("lca2.in", "r", stdin);
    //freopen("CF_7D_PalindromeDegree.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1;i <= n;++i)
        {
            child[i].clear();
            pre[i] = i;
        }
        int m = n - 1;
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            child[a].push_back(b);
            pre[b] = a;
        }

        cin >> first >> second;
        ans = 0;

        int root = 1;
        while (pre[root] != root)
            root = pre[root];

        try { dfs(root); }
        catch (int) {}

        cout << ans << endl;
    }
}