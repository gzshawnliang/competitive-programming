/*
===========================================================
* @Name:           939E Maximize!
* @Author:         Shawn
* @create Time:    2020/6/6 21:09:40
* @url:            https://codeforces.com/contest/939/problem/E
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

void solve()
{
    cout << fixed << setprecision(10);

    int tq; cin >> tq;
    vector<double> a, sum;
    sum.push_back(0);

    auto f = [&](int sizI)
    {
        return a.back() - (sum[sizI] + a.back()) / (double)(sizI + 1);
    };

    for (int cq = 1; cq <= tq; ++cq)
    {
        int typ; cin >> typ;

        if (typ == 1)
        {
            int x; cin >> x; a.push_back(x);
            sum.push_back(sum.back() + x);
        }
        else
        {
            int l = 0, r = a.size() - 1;
            while (true)
            {
                if (r - l == 2)
                {
                    cout << max(f(l), max(f(l + 1), f(r))) << '\n';
                    break;
                }
                else if (r - 1 <= 1)
                {
                    cout << max(f(l), f(r)) << '\n';
                    break;
                }

                int p1 = l + (r - l) / 3;
                int p2 = r - (r - l) / 3;  

                if (f(p1) > f(p2)) r = p2;
                else               l = p1;
            }
        }
    }

    for (int __s = 0; __s == 0; ++__s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_939E_Maximize!.in", "r", stdin);
    freopen("CF_939E_Maximize!.out", "w", stdout);
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