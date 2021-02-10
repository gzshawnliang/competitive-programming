#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
    struct node
    {
        int indI;
        int disI;
        int indJ;
        int disJ;
        //int pass;

        bool operator<(const node & p) const
        {
            return max(disI, disJ) > max(p.disI, p.disJ);
        }
    };

    vector<int> f;
    vector<vector<int>> g;

    void dfs(int u)
    {
        if (f[u] >= 0) return;

        f[u] = 0;
        for (auto v:g[u])
        {
            dfs(v);
            f[u] += (1 + f[v]);
        }
    }

  public:
    void solve()
    {
        int n; cin >> n;
        
        vector<tuple<char, int, int>> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
        }

        priority_queue<node> q;
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n - 1; ++j)
            {
                tuple<char, int, int> pi = a[i], pj = a[j];
                if (get<0>(pi) != get<0>(pj))
                {
                    int tmpI = i, tmpJ = j;
                    if (get<0>(pi) == 'E'){
                        swap(pi, pj);
                        swap(tmpI, tmpJ);
                    }

                    node now;
                    //now.pass = -1;
                    now.indI = tmpI; now.disI = get<2>(pj) - get<2>(pi);
                    now.indJ = tmpJ; now.disJ = get<1>(pi) - get<1>(pj);

                    bool flg = true;
                    if ((get<0>(pi) == 'N' && now.disI < 0) || (get<0>(pi) == 'S' && now.disI > 0)) flg = false;
                    if ((get<0>(pj) == 'E' && now.disJ < 0) || (get<0>(pj) == 'W' && now.disJ > 0)) flg = false;
                    now.disI = abs(now.disI); now.disJ = abs(now.disJ);
                    if (now.disI == now.disJ) flg = false;

                    if (flg)
                    {
                        q.push(now);
                    }
                }
            }
        }

        vector<int> finalM(n, 0);
        g = vector<vector<int>>(n);
        while (!q.empty())
        {
            node now = q.top(); q.pop();
            
            if (finalM[now.indI] > 0 || finalM[now.indJ] > 0)
            {
                if (finalM[now.indI] > 0 && finalM[now.indJ] > 0)
                {
                    if (finalM[now.indI] >= now.disI && finalM[now.indJ] >= now.disJ)
                    {
                        if (now.disI < now.disJ)
                        {
                            finalM[now.indJ] = now.disJ;
                            g[now.indI].push_back(now.indJ);
                        }
                        else
                        {
                            finalM[now.indI] = now.disI;
                            g[now.indJ].push_back(now.indI);
                        }
                    }
                }
                else if (finalM[now.indI] > 0)
                {
                    if (finalM[now.indI] >= now.disI)
                    {
                        finalM[now.indJ] = now.disJ;
                        g[now.indI].push_back(now.indJ);
                    }
                }
                else
                {
                    if (finalM[now.indJ] >= now.disJ)
                    {
                        finalM[now.indI] = now.disI;
                        g[now.indJ].push_back(now.indI);
                    }
                }
            }
            else
            {
                if (now.disI < now.disJ)
                {
                    finalM[now.indJ] = now.disJ;
                    g[now.indI].push_back(now.indJ);
                }
                else
                {
                    finalM[now.indI] = now.disI;
                    g[now.indJ].push_back(now.indI);
                }
            }
        }

        // for (int i = 0; i <= n - 1; ++i)
        // {
        //     if (g[i].size() > 0)
        //     {
        //         cout << "g[" << i << "]:";
        //         for (auto x:g[i])
        //             cout << ' ' << x;
        //         cout << '\n';
        //     }
        // }

        f = vector<int>(n, -1);
        for (int i = 0; i <= n - 1; ++i)
        {
            if (f[i] == -1)
                dfs(i);

            cout << f[i] << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("StuckinaRut.in", "r", stdin);
    freopen("StuckinaRut.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}

// vector<vector<int>> g(n);
// for (int i = 0; i <= n - 1; ++i)
// {
//     for (int j = i + 1; j <= n - 1; ++j)
//     {
//         int f1, f2;
//         if (get<0>(a[i]) == 'N' || get<0>(a[i]) == 'S') f1 = 0;
//         else                                            f1 = 1;
//         if (get<0>(a[j]) == 'N' || get<0>(a[j]) == 'S') f2 = 0;
//         else                                            f2 = 1;

//         if (i == 1 && j == 3)
//         {
//             for(int _s_=0;_s_==0;++_s_);
//         }

//         if (f1 != f2)
//         {
//             bool flg = true;
//             int insX, insY;
//             if (f1 == 0)
//             {
//                 insX = get<1>(a[i]);
//                 insY = get<2>(a[j]);

//                 if (get<0>(a[j]) == 'W' && get<1>(a[j]) < insX) flg = false;
//                 if (get<0>(a[j]) == 'E' && insX < get<1>(a[j])) flg = false;

//                 if (get<0>(a[i]) == 'N' && get<2>(a[i]) > insX) flg = false;
//                 if (get<0>(a[i]) == 'S' && insX > get<2>(a[i])) flg = false;
//             }
//             else
//             {
//                 insX = get<1>(a[j]);
//                 insY = get<2>(a[i]);

//                 if (get<0>(a[i]) == 'W' && get<1>(a[i]) < insX) flg = false;
//                 if (get<0>(a[i]) == 'E' && insX < get<1>(a[i])) flg = false;

//                 if (get<0>(a[j]) == 'N' && get<2>(a[j]) > insX) flg = false;
//                 if (get<0>(a[j]) == 'S' && insX > get<2>(a[j])) flg = false;
//             }

//             if (flg == true)
//             {
//                 int disI = abs(insX - get<1>(a[i])) + abs(insY - get<2>(a[i])), disJ = abs(insX - get<1>(a[j])) + abs(insY - get<2>(a[j]));
//                 if (disI < disJ)
//                 {
//                     g[i].push_back(j);
//                 }
//                 else if (disI > disJ)
//                 {
//                     g[j].push_back(i);
//                 }
//             }
//         }
//     }
// }