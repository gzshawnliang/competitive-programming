/*
===========================================================
* @Name:           UVa-13010 Galactic taxes
* @Author:         Shawn
* @create Time:    2020/6/14 21:59:29
* @url:            
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
// #include "MyRandom.h"
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const double eps = 1e-12;

struct edge
{
    int v;
    int k;
    int b;
};

void solve()
{
    cout << fixed << setprecision(5);
    while (true)
    {
        int n = 0, m = 0; cin >> n >> m;
        if(cin.good()==false)
            break;        
        if (n + m == 0) break;


        vector<vector<edge>> g(n + 1);
        for (int c = 1; c <= m; ++c)
        {
            int u, v; cin >> u >> v;
            
            edge tmp{v, 0, 0};
            cin >> tmp.k >> tmp.b;
            

            g[u].push_back(tmp);

            tmp.v = u;
            g[v].push_back(tmp);
        }

        auto F = [&](double t)
        {
            priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
            q.push({0, 1});

            int n = g.size() - 1;

            vector<double> d(n + 1, 1e60); d[1] = 0;
            while (q.empty() == false)
            {
                pair<double, int> now = q.top(); q.pop();

                for (auto vp: g[now.second])
                {
                    double l = vp.k * t + vp.b; l = max(l, 0.0);
                    pair<double, int> nxt{now.first + l, vp.v};
                    //if (d[vp.v] > nxt.first && abs(d[vp.v] - nxt.first) > eps)
                    if (d[vp.v] > nxt.first)
                    {
                        d[vp.v] = nxt.first;
                        q.push(nxt);
                    }
                }
            }

            return (double)d[n];
        };
        
        double l = 0.0, r = 24.0 * 60.0;
        while (r - l > eps)
        {
            double p1 = l + (r - l) / 3.0;
            double p2 = r - (r - l) / 3.0;

            if (F(p1) > F(p2)) r = p2;
            else               l = p1;
        }

        cout << F(l) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("UVa13010_Galactictaxes.in", "r", stdin);
    freopen("UVa13010_Galactictaxes.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}

// int main2()
// {
//     random rdNum;              //note:随机数
//     freopen("g.in", "r", stdin);
//     freopen("UVa13010_Galactictaxes.in", "w", stdout);
//     int n,m;
//     cin >> n >> m;
//     cout << n << " " <<  m << "\n";
//     for (int i = 0; i <= m - 1; ++i)
//     {
//         int u,v;
//         cin >> u >> v;
//         cout << u << " " << v << " 0 " << rdNum.GetRand(1, 1e6) << "\n";
//     }
//     return 0;

// }