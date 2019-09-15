#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll im = INT_MAX;

ll getNum(ll i, ll j, string & s)
{
    string ss = s.substr(i, j - i + 1);
    if (ss[0] == '0' && i != j) return -2;
    if (j - i + 1 > 10) return -1;
    ll ans = stoll(ss);
    if (ans > im) return -1;

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    ll tcc; cin >> tcc;
    for (ll t = 1; t <= tcc; ++t)
    {
        string s; cin >> s;
        ll sizeS = s.size();

        vector<ll> dp(sizeS, 0.0);
        for (ll i = 0; i <= sizeS - 1; ++i)
        {
            ll res0 = getNum(0, i, s);
            if (res0 >= 0)
            {
                dp[i] = res0;
            }
            else
            {
                for (ll j = i - 1; j >= 0; --j)
                {
                    ll res1 = getNum(j + 1, i, s);
                    if (res1 == -1) break;
                    else if (res1 == -2) continue;

                    dp[i] = max(dp[i], dp[j] + res1);
                }
            }
        }

        cout << dp[sizeS - 1] << '\n';
    }

   	cout.flush();
   	return 0;
}

