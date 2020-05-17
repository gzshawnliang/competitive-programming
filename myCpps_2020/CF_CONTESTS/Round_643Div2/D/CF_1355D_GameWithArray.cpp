/*
===========================================================
* @Name:           1355D Game With Array
* @Author:         Shawn
* @create Time:    2020/5/16 19:35:30
* @url:            https://codeforces.com/contest/1355/problem/D
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
    int n, s; cin >> n >> s;

    if (2 * n > s)
    {
        cout << "NO\n";
    }
    else
    {
        bool first = true;

        cout << "YES\n";
        for (int c = 1; c <= n - 1; ++c)
        {
            if (first == false) cout << ' ';
            else                first = false;
            
            cout << 2;
            s -= 2;
        }

        if (first == false) cout << ' ';
        else                first = false;
        cout << s << '\n' << "1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1355D_GameWithArray.in", "r", stdin);
        freopen("CF_1355D_GameWithArray.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}