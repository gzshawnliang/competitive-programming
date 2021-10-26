/*
-------------------------------------------------------------------
* @Name:           1385G Columns Swaps
* @Author:         Thomas
* @Create Time:    2020/7/20 17:28:13  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/G
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/


#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{
    vector<tuple<int,int,bool>> g;

  public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> a1(n+1);
        vector<int> a2(n+1);

        vector<vector<int>> pos(n+1);

        for (int i = 1; i <= n ; ++i)
        {
            cin >> a1[i];
            pos[a1[i]].push_back(i);
        }

        for (int i = 1; i <= n ; ++i)
        {
            cin >> a2[i];
            pos[a2[i]].push_back(i);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (pos[i].size() != 2) //数字i不存在2个
            {
                cout << -1 << '\n';
                return;
            }

            /*
                数字i的位置一样，不做处理,例如以下2的位置是一样的
                  |                    
                3 2 3
                1 2 1
                  |
            */
            int c1=pos[i][0];
            int c2=pos[i][1];
            if (c1 == c2)
                continue;

            int r1 = a1[c1] != i;
            int r2 = a1[c2] != i;

            g.push_back({c1,c2,r1==r2});
            g.push_back({c2,c1,r1==r2});
            
            for (int __s = 0; __s == 0; ++__s);
        }
        return;

    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385G_ColumnsSwaps.in", "r", stdin);
    //freopen("CF_1385G_ColumnsSwaps.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solution sln1;
        sln1.solve();
    }
    
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}