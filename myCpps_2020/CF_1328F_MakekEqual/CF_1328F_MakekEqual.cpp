/*
===========================================================
* @Name:           1328F Make k Equal
* @Author:         Shawn
* @create Time:    2020/4/13 22:08:41
* @url:            https://codeforces.com/contest/1328/problem/F
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const ill inf = LLONG_MAX / 2;

void solve()
{
        ill n, k; cin >> n >> k;
        set<ill> a_s;
        map<ill, ill> cntN;
    for (ill i = 0; i <= n - 1; ++i)
    {
        ill tmp; cin >> tmp;

        a_s.insert(tmp);
        a_s.insert(tmp + 1);
        a_s.insert(tmp - 1);

        ++cntN[tmp];
    }

    a_s.insert(4);

    vector<ill> a;
    for (auto ite = a_s.begin(); ite != a_s.end(); ++ite)
    {
        a.push_back(*ite);
    }
    ill sizA = a.size();

        if (sizA == 1) {cout << "0\n"; return;}

        vector<ill> f1(sizA, 0), c1(sizA, 0); f1[0] = 0; c1[0] = cntN[a[0]];
    for (ill i = 1; i <= sizA - 1; ++i)
    {
        f1[i] = f1[i - 1] + c1[i - 1] * (a[i] - a[i - 1]);
        c1[i] = c1[i - 1] + cntN[a[i]];
    }
        
        vector<ill> f2(sizA, 0), c2(sizA, 0); f2[sizA - 1] = 0; c2[sizA - 1] = cntN[a[sizA - 1]];
    for (ill i = sizA - 2; i >= 0; --i)
    {
        f2[i] = f2[i + 1] + c2[i + 1] * (a[i + 1] - a[i]);
        c2[i] = c2[i + 1] + cntN[a[i]];
    }

    ill ans = inf;
    for (ill i = 0; i <= sizA - 1; ++i)
    {

        ill cntNowN = cntN[a[i]];

        if      (cntNowN >= k) {cout << "0\n"; return;}
        else if (cntNowN == 0) continue;

        if (i == 0)
        {
            if (c2[i + 1] >= k - cntNowN)
                ans = min(ans, f2[i + 1] + (k - cntNowN) * (a[i + 1] - a[i]));
        }
        else if (i == sizA - 1)
        {
            if (c1[i - 1] >= k - cntNowN)
                ans = min(ans, f1[i - 1] + (k - cntNowN) * (a[i] - a[i - 1]));
        }
        else
        {
            if (c1[i - 1] + c2[i + 1] >= k - cntNowN)
            {
                bool flg = false;
                ill ld = (a[i] - a[i - 1]), rd = (a[i + 1] - a[i]);

                if (c1[i - 1] >= k - cntNowN)
                {
                    ans = min(ans, f1[i - 1] + (k - cntNowN) * ld);
                    flg = true;
                }

                if (c2[i + 1] >= k - cntNowN)
                {
                    ans = min(ans, f2[i + 1] + (k - cntNowN) * rd);
                    flg = true;
                }
                    
                if (flg == false)
                {
                    if (a[i] - a[i - 1] < a[i + 1] - a[i])
                        ans = min(ans, f1[i - 1] + f2[i + 1] + c1[i - 1] * ld + (k - cntNowN - c1[i - 1]) * rd);
                    else
                        ans = min(ans, f1[i - 1] + f2[i + 1] + (k - cntNowN - c2[i + 1]) * ld + c2[i + 1] * rd);
                }
            }
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
        freopen("CF_1328F_MakekEqual.in", "r", stdin);
        freopen("CF_1328F_MakekEqual.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}