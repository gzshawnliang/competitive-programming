/*
===========================================================
* @Name:           1335F Robots on a Grid
* @Author:         Shawn
* @create Time:    2020/4/23 23:07:07
* @url:            https://codeforces.com/contest/1335/problem/F
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    vector<pair<int, int>> pls(256);
    pls['U'] = {0, -1};
    pls['D'] = {0, 1};
    pls['L'] = {-1, 0};
    pls['R'] = {1, 0};

    int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
        int n, m; cin >> n >> m;

        // auto leg=[&](int x, int y)
        // {
        //     return x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1;
        // };

            vector<string> orgColors(n);
        for (int y = 0; y <= n - 1; ++y) cin >> orgColors[y];

            vector<int> colors(n * m);
        for (int y = 0; y <= n - 1; ++y)
            for (int x = 0; x <= m - 1; ++x)
                colors[y * m + x] = (orgColors[y][x] - '0');

            vector<string> orgForces(n);
        for (int y = 0; y <= n - 1; ++y) cin >> orgForces[y];
        
            vector<int> gOut(n * m);
            vector<vector<int>> gIn(n * m);
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                int nxtX = x + pls[orgForces[y][x]].first, nxtY = y + pls[orgForces[y][x]].second;
                //if (leg(nxtX, nxtY))
                gOut[y * m + x] = nxtY * m + nxtX;
                gIn[nxtY * m + nxtX].push_back(y * m + x);
            }
        }

            vector<int> visit(n * m, 0), counter(n * m, 0), belngLop(n * m, -1);
            vector<int> lops; // {spcNod, len}
        for (int nowNod = 0; nowNod <= n * m - 1; ++nowNod)
        {
                vector<int> pth;
            if (visit[nowNod] == 0)
            {
                visit[nowNod] = 1;
                counter[nowNod] = 0;
                pth.push_back(nowNod);
                
                    int u = nowNod;
                while (true)
                {
                    int v = gOut[u];

                    if      (visit[v] == 2)
                    {
                        int siz = pth.size();
                        for (int i = siz - 1; i >= 0; --i)
                        {
                            counter[pth[i]] = counter[v] + siz - i;
                            belngLop[pth[i]] = belngLop[v];
                        }

                        break;
                    }
                    else if (visit[v] == 1)
                    {
                        lops.push_back(counter[u] + 1 - counter[v]);

                            
                            int siz = pth.size(), sizL = lops.size();
                            counter[v] = 0;
                            belngLop[v] = sizL - 1;
                        for (int i = siz - 1; i >= 0; --i)
                        {
                            if (pth[i] != v)
                            {
                                counter[pth[i]] = (siz - i);
                                belngLop[pth[i]] = sizL - 1;
                            }
                        }

                        break;
                    }
                    else
                    {
                        visit[v] = 1;
                        counter[v] = counter[u] + 1;
                        pth.push_back(v);

                        u = v;
                    }
                }
            }

            for (auto x:pth) visit[x] = 2;
        }

        int ans1 = 0;
        for (auto nowL:lops) ans1 += nowL;

        int ans2 = 0;
        // for (auto nowL:lops)
        // {
        //     int nowLS = nowL.first, nowLL = nowL.second;

        //     queue<int> q; q.push(nowLS);
        //     vector<int> visit(n * m, 0); visit[nowLS] = 1;
        //     vector<int> cntInd(nowLL, 0), dis(n * m, 0);

        //     if (colors[nowLS] == 0)
        //     {
        //         ++ans2;
        //         cntInd[0] = 1;
        //     }

        //     while (q.empty() == false)
        //     {
        //         int u = q.front(); q.pop();

        //         for (auto v:gIn[u])
        //         {
        //             if (visit[v] == 0)
        //             {
        //                 q.push(v);
        //                 visit[v] = 1;
        //                 dis[v] = dis[u] + 1;

        //                 if (colors[v] == 0 && cntInd[dis[v] % nowLL] == 0)
        //                 {
        //                     ++ans2;
        //                     cntInd[dis[v] % nowLL] = 1;
        //                 }
        //             }
        //         }
        //     }
        // }

            int sizL = lops.size();
            vector<set<int>> mmp(sizL);
        for (int nowNod = 0; nowNod <= n * m - 1; ++nowNod)
        {
            if (colors[nowNod] == 0)
            {
                mmp[belngLop[nowNod]].insert(counter[nowNod] % lops[belngLop[nowNod]]);
            }
        }

        for (auto nowS:mmp) ans2 += nowS.size();

        cout << ans1 << ' ' << ans2 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1335F_RobotsonaGrid.in", "r", stdin);
        freopen("CF_1335F_RobotsonaGrid.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}