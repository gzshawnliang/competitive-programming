/*
===========================================================
* @Name:           1348D Phoenix and Science
* @Author:         Shawn
* @create Time:    2020/5/1 22:35:42
* @url:            https://codeforces.com/contest/1348/problem/D
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
    ill tct; cin >> tct;
    for (ill tcc = 1; tcc <= tct; ++tcc)
    {
        ill n; cin >> n;
        --n;

        if (n == 1)
        {
            cout << "1\n0\n";
            continue;
        }
        else if (n == 3)
        {
            cout << "2\n0 1\n";
            continue;
        }

        ill nowT = 1, tolM = 0, dt = 0;
        vector<ill> ans;
        while (tolM < n)
        {
            nowT *= 2;
            tolM += nowT;

            ans.push_back(nowT);
            ++dt;
        }

        ill del = tolM - n;
        for (ill i = dt - 1; i >= 1 && del > 0; --i)
        {
            del -= (ans[i] - ans[i - 1]) * (dt - i);

            for (ill j = dt - 1; j >= i; --j) ans[j] = ans[i - 1];

            if (del <= 0)
            {
                del *= -1;
                for (ill j = i; j <= dt - 1; --j)
                {
                    if (dt - j >= del)
                    {
                        for (ill k = dt - 1; k >= j && del > 0; --k)
                        {
                            ++ans[k]; --del;
                        }
                        break;
                    }
                    else
                    {
                        for (ill k = j; k <= dt - 1; ++k)
                        {
                            ans[k] += del / (dt - j);
                        }

                        del -= (del / (dt - j)) * (dt - j);
                    }
                }
            }
        }

        cout << dt << '\n';

        ill lst = 1;
        for (ill i = 0; i <= dt - 1; ++i)
        {
            if (i > 0) cout << ' ';
            cout << ans[i] - lst;

            lst = ans[i];
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
        freopen("CF_1348D_PhoenixandScience.in", "r", stdin);
        freopen("CF_1348D_PhoenixandScience.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}