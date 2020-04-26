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

void solve()
{
        int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
        int n; cin >> n;

            bool is3 = (n % 2), is1 = true;
            vector<int> typ(n, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> typ[i];
            if (i > 0)
            {
                if (typ[i] == typ[i - 1]) is3 = false;
                if (typ[i] != typ[i - 1]) is1 = false;
            }
        }
        if (typ[n - 1] == typ[0]) is3 = false;

        if (is1 == true)
        {
            cout << "1\n";
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i > 0) cout << ' ';

                cout << 1;
            }
            cout << '\n';
        }
        else if (is3 == true)
        {
            cout << "3\n";
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i > 0) cout << ' ';

                if (i == n - 1) cout << 3;
                else            cout << i % 2 + 1;
            }
            cout << '\n';
        }
        else
        {
            vector<int> colors(n, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i == 0) colors[i] = 1;
                else
                {
                    if (typ[i] == typ[i - 1]) colors[i] = colors[i - 1];
                    if (typ[i] != typ[i - 1]) colors[i] = 3 - colors[i - 1];
                }
            }

            if (typ[0] != typ[n - 1] && colors[0] == colors[n - 1])
            {
                colors[n - 1] = 3 - colors[0];
                for (int i = n - 2; i >= 0; --i)
                {
                    if (typ[i] != typ[i + 1]) colors[i] = 3 - colors[i + 1];
                }
            }

            cout << "2\n";
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i > 0) cout << ' ';

                cout << colors[i];
            }
            cout << '\n';
        }
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