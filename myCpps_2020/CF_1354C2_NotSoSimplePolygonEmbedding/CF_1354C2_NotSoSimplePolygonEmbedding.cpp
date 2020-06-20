/*
===========================================================
* @Name:           1354C2 Not So Simple Polygon Embedding
* @Author:         Shawn
* @create Time:    2020/6/20 20:40:11
* @url:            https://codeforces.com/contest/1354/problem/C2
* @Description:    
===========================================================
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
const double pi = 2 * acos(0.0);

class solution
{
  public:
    vector<int> a;
    void solve()
    {
        cout << fixed << setprecision(9);

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            double n; cin >> n;

            double l = cos(pi / (4 * n)) / sin(pi / (2 * n));

            cout << l << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1354C2_NotSoSimplePolygonEmbedding.in", "r", stdin);
    freopen("CF_1354C2_NotSoSimplePolygonEmbedding.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}