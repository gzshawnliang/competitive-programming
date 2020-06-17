/*
===========================================================
* @Name:           1364A XXXXX
* @Author:         Shawn
* @create Time:    2020/6/13 23:05:31
* @url:            https://codeforces.com/contest/1364/problem/A
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
    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        int n, x; cin >> n >> x;
 
        bool flg = true;
        int total = 0;
        vector<int> a(n, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
            a[i] %= x;
 
            if (a[i] > 0) flg = false;
            total = (total + a[i]) % x;
        }
 
        if (flg == true)
        {
            cout << "-1\n";
        }
        else
        {
            if (total == 0)
            {
                int m0 = 0;
                for (int i = 0; a[i] == 0; ++i) ++m0;
 
                int m1 = 0;
                for (int i = n - 1; a[i] == 0; --i) ++m1;
 
                cout << n - min(m0, m1) - 1 << '\n';
            }
            else
            {
                cout << n << '\n';
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1364A_XXXXX.in", "r", stdin);
    freopen("CF_1364A_XXXXX.out", "w", stdout);
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