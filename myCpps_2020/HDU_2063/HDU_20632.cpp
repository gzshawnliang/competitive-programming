/*
===========================================================
* @Name:            过山车 
* @Author:          Shawn
* @create Time:     2020/5/4 21:53:42
* @url:             http://acm.hdu.edu.cn/showproblem.php?pid=2063
* @Description:     二分图|匈牙利算法 模板
===========================================================
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

using ll = long long;


bool dfs(int u, vector<int> & match, vector<int> & visit, vector<vector<int>> & g)
{
    for (auto v :g[u])
    {
        if (visit[v] == false)
        {
            visit[v] = true;
            if (match[v] == 0 || dfs(match[v], match, visit, g) == true)
            {
                match[v] = u;
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    while (true)
    {
        int k = 0;
        cin >> k;
        if (k == 0)
            break;

        int m, n;
        cin >> m >> n;

        vector<vector<int>> g(m + 1, vector<int>());
        for (int c = 1; c <= k; ++c)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }

        int ans = 0;
        vector<int> match(n + m + 1, 0);    //匹配数组 match[u]=v，说明u-v匹配
        for (int u = 1; u <= m; ++u)
        {
            vector<int> visit(n + m + 1, 0);
            if (dfs(u, match, visit, g) == true)
            {
                ++ans;
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("HDU_2063.in", "r", stdin);
    //freopen("HDU_2063.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}