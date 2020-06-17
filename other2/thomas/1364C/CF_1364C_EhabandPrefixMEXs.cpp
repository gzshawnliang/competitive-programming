/*
===========================================================
* @Name:           1364C Ehab and Prefix MEXs
* @Author:         Shawn
* @create Time:    2020/6/13 23:05:31
* @url:            https://codeforces.com/contest/1364/problem/C
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
    int n; cin >> n;
 
    vector<int> a(n, 0);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
    }
 
    vector<int> nxtN(n, -1), nxtL(n, -1);
    nxtL[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (a[i] != a[i + 1])
        {
            nxtN[i] = a[i + 1];
            nxtL[i] = 1;
        }
        else
        {
            nxtN[i] = nxtN[i + 1];
            nxtL[i] = nxtL[i + 1] + 1;
        }
    }
 
    int nowM = 1 - a[0];
    vector<int> b(n, -1);
    b[0] = 1 - a[0];
    for (int i = 1; i <= n - 1; ++i)
    {
        if (a[i] != a[i - 1])
        {
            b[i] = a[i - 1];
            nowM = max(nowM, a[i - 1]);
 
            if (a[i] != nowM + 1)
            {
                cout << "-1\n";
                return;
            }
        }
        else
        {
            if (nxtN[i] <= nowM + 1)
            {
                b[i] = b[i - 1];
            }
            else
            {
                if (nowM + 1 == a[i])
                {
                    b[i] = nowM + 2;
                    nowM += 2;
                }
                else
                {
                    b[i] = nowM + 1;
                    ++nowM;
                }
            }
        }
    }
 
    for (int i = 0; i <= n - 1; ++i)
    {
        if (i > 0) cout << ' ';
        cout << b[i];
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1364C_EhabandPrefixMEXs.in", "r", stdin);
    freopen("CF_1364C_EhabandPrefixMEXs.out", "w", stdout);
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