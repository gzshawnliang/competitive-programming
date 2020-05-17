/*
===========================================================
* @Name:           1355C Count Triangles
* @Author:         Shawn
* @create Time:    2020/5/16 19:35:30
* @url:            https://codeforces.com/contest/1355/problem/C
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

void solve()
{
    ill a, b, c, d; cin >> a >> b >> c >> d;

    ill ans = 0;
    for (ill y = b; y <= c; ++y)
    {
        ill minX = c - (y - 1), maxX = d - (y - 1);
        ill maxV = d - c + 1;

        if (b < minX)
        {
            // do nothing
        }
        else if (a <= minX && minX <= b && b <= maxX)
        {
            ans += ((1 + (b - minX + 1)) * (b - minX + 1) / 2);
        }
        else if (minX <= a && b <= maxX)
        {
            ans += (((a - minX + 1) + (b - minX + 1)) * (b - a + 1) / 2);
        }
        else if (minX <= a && a <= maxX && maxX <= b)
        {
            ans += (((a - minX + 1) + maxV) * (maxV - (a - minX + 1) + 1) / 2);
            ans += maxV * ((b - a + 1) - (maxV - (a - minX + 1) + 1));
        }
        else if (a <= minX && maxX <= b)
        {
            ans += ((1 + maxV) * maxV / 2);
            ans += maxV * (b - maxX);
        }
        else
        {
            ans += maxV * (b - a + 1);
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1355C_CountTriangles.in", "r", stdin);
        freopen("CF_1355C_CountTriangles.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}