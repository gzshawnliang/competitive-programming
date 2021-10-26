#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
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

bool dfs(int curr, const vector<vector<int>> & g, vector<int> & vist, vector<int> & vist2)
{
    if (vist[curr ^ 1] == 1)
        return false;

    if (vist[curr] == 1)
        return true;

    vist2.push_back(curr);

    vist[curr] = 1;
    int size1 = g[curr].size();
    for (int i = 0; i <= size1 - 1; ++i)
    {
        if (dfs(g[curr][i], g, vist, vist2) == false)
            return false;
    }
    return true;
}

void solve()
{
    while (true)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        if(n==0 && m==0)
            break;

        //assert(n > 0);

        vector<vector<int>> g(n * 2, vector<int>());

        for (int i = 0; i <= m - 1; ++i)
        {
            int a, b;
            cin >> a >> b;
            --a;
            --b;

            g[a].push_back(b ^ 1);
            g[b].push_back(a ^ 1);
        }

        vector<int> vist(n * 2, 0);
        bool ans = true;
        for (int i = 0; i <= n * 2 - 1 && ans==true; i += 2)
        {
            vector<int> vist2;
            if (vist[i] == 0 && vist[i + 1] == 0)
            {
                bool result = dfs(i, g, vist, vist2);
                if (result == false)
                {
                    for (auto k : vist2)
                        vist[k] = 0;

                    vist2.clear();
                    result = dfs(i + 1, g, vist, vist2);
                    if (result == false)
                    {
                        ans=false;
                    }
                }
            }
        }
        
        if(ans==false)
            cout << "NIE\n";
        else             
            for (int j = 0; j <= n * 2 - 1; ++j)
                if (vist[j] == 1)
                    cout << j + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("SPO.IN", "r", stdin);
    freopen("SPO.OUT", "w", stdout);
#endif

    solve();

    // for (int i = 0; i <= 30 - 1; ++i)
    // {
    //     cout << i << " " << (i^1) << "\n";
    // }

    cout.flush();
    return 0;
}