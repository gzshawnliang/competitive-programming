
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef LOCAL_DEBUG
    freopen("C.in", "r", stdin);
    freopen("C.ok", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ts;
    cin >> ts;
    auto get_not = [&](string s) {
        for (auto & x : s)
        {
            if (x == '1')
                x = '0';
            else
                x = '1';
        }
        while (s.size() > 1 && s[0] == '0')
            s.erase(s.begin());
        return s;
    };
    auto get_double = [&](string s) {
        if (s == "0")
            return s;
        else
        {
            s += '0';
            return s;
        }
    };
    auto cost = [&](string s, string t) {
        int ans = 1e9;
        for (int shift = 0; shift <= (int)t.size(); shift++)
        {
            for (int gg = 0; gg < 2; gg++)
            {
                string me = s;
                int ptr = shift;
                int iters = 0;
                auto relax = [&](string x) {
                    if (x == t)
                        ans = min(ans, iters);
                };
                for (int its = 0; its < 210; its++)
                {
                    relax(me);
                    while (ptr < (int)t.size() && gg == ((t[ptr] - '0') ^ (its % 2)))
                    {
                        me = get_double(me);
                        ptr++;
                        iters++;
                    }
                    relax(me);
                    me = get_not(me);
                    iters++;
                }
            }
        }
        return ans;
    };
    auto solve = [&]() {
        string s, t;
        cin >> s >> t;
        int ans = cost(s, t);
        if (ans == 1e9)
            cout << "IMPOSSIBLE";
        else
            cout << ans;
    };
    for (int i = 1; i <= ts; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
