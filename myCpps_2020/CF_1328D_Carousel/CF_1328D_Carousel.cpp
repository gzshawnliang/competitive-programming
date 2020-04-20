/*
===========================================================
* @Name:           1328D Carousel
* @Author:         Shawn
* @create Time:    2020/4/18 23:37:00
* @url:            https://codeforces.com/contest/1328/problem/D
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dif(int col)
{
    if (col == 1) return 2;
    else          return 1;
}

void solve()
{
        int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
        int n; cin >> n;

            int ans = 1;
            vector<int> colors(n, 0), typ(n, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> typ[i];

            if      (i == 0)
            {
                colors[i] = 1;
            }
            else if (i == n - 1)
            {
                for (int col = 1; col <= 3; ++col)
                {
                    if (col == colors[0] && typ[i] != typ[0] && typ[0] != typ[1]) continue;
                    if (col == colors[i - 1] && typ[i] != typ[i - 1] && typ[i - 1] != typ[i - 2]) continue;

                    colors[i] = col;
                    if (col == colors[0] && typ[i] != typ[0] && typ[0] == typ[1]) colors[0] = dif(col);
                    if (col == colors[i - 1] && typ[i] != typ[i - 1] && typ[i - 1] == typ[i - 2]) colors[i - 1] = dif(col);

                    break;
                }
            }
            else
            {
                if (typ[i] == typ[i - 1]) colors[i] = colors[i - 1];
                else                      colors[i] = dif(colors[i - 1]);
            }

            ans = max(ans, colors[i]);
        }

        cout << ans << '\n';
        for (int i = 0; i <= n - 1; ++i)
        {
            if (i > 0) cout << ' ';
            cout << colors[i];
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1328D_Carousel.in", "r", stdin);
        freopen("CF_1328D_Carousel.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}