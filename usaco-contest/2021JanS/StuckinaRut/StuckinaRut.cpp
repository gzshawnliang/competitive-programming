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
  public:
    void solve()
    {
        int n; cin >> n;
        vector<pair<int, int>> allX, allY;
        vector<tuple<char, int, int>> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);

            if (get<0>(a[i]) == 'E' || get<0>(a[i]) == 'W') allY.push_back({get<2>(a[i]), i});
            else                                            allX.push_back({get<1>(a[i]), i});
        }

        int sizAX = allX.size(), sizAY = allY.size();
        sort(allX.begin(), allX.begin());
        sort(allY.begin(), allY.begin());

        vector<vector<int>> g(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            if (get<0>(a[i]) == 'E')
            {
                int j = 0;
                while (j <= sizAX - 1 && allX[j].first < get<1>(a[i])) ++j;
                
                while (j <= sizAX - 1)
                {
                    auto now = a[allX[j].second];
                    int disX = allX[j].first - get<1>(a[i]), disY = abs(get<2>(now) - get<2>(a[i]));
                    if ((get<0>(now) == 'N' && get<2>(now) > get<2>(a[i])) || (get<0>(now) == 'S' && get<2>(now) < get<2>(a[i])))
                    {
                        continue;
                    }
                    
                    if      (disX < disY)
                        g[i].push_back(allX[j].second);
                    else if (disX > disY)
                        break;

                    ++j;
                }
            }
            else if (get<0>(a[i]) == 'E')
            {
                int j = sizAX - 1;
                while (j >= 0 && allX[j].first > get<1>(a[i])) --j;
                
                while (j >= 0)
                {
                    auto now = a[allX[j].second];
                    int disX = get<1>(a[i]) - allX[j].first, disY = abs(get<2>(now) - get<2>(a[i]));
                    if ((get<0>(now) == 'N' && get<2>(now) > get<2>(a[i])) || (get<0>(now) == 'S' && get<2>(now) < get<2>(a[i])))
                    {
                        continue;
                    }
                    
                    if      (disX < disY)
                        g[i].push_back(allX[j].second);
                    else if (disX > disY)
                        break;

                    --j;
                }
            }
        }

        for(int _s_=0;_s_==0;++_s_);
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
//                 int dis1 = abs(insX - get<1>(a[i])) + abs(insY - get<2>(a[i])), dis2 = abs(insX - get<1>(a[j])) + abs(insY - get<2>(a[j]));
//                 if (dis1 < dis2)
//                 {
//                     g[i].push_back(j);
//                 }
//                 else if (dis1 > dis2)
//                 {
//                     g[j].push_back(i);
//                 }
//             }
//         }
//     }
// }