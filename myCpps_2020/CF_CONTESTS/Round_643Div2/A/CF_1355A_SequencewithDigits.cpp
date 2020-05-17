/*
===========================================================
* @Name:           1355A Sequence with Digits
* @Author:         Shawn
* @create Time:    2020/5/16 19:35:30
* @url:            https://codeforces.com/contest/1355/problem/A
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

ill add(ill x)
{
    ill maxD = 0, minD = 10;
    while (x > 0)
    {
        maxD = max(maxD, x % 10);
        minD = min(minD, x % 10);
        x /= 10;
    }

    return maxD * minD;
}

void solve()
{
    ill tct; cin >> tct;
    for (ill tcc = 1; tcc <= tct; ++tcc)
    {
        ill x, k; cin >> x >> k;
        for (ill c = 1; c <= k - 1; ++c)
        {
            ill addX = add(x);
            if (x == x + addX) break;

            x += addX;
        }

        cout << x << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1355A_SequencewithDigits.in", "r", stdin);
        freopen("CF_1355A_SequencewithDigits.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}