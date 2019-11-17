/*
===========================================================
* @Name:           633C Spy Syndrome 2
* @Author:         Shawn
* @create Time:    2019/11/16 20:12:01
* @url:            https://codeforces.com/contest/633/problem/C
* @Description:    
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;


using ll = unsigned long long;

const ll base = 137;

ll _hash(string s)
{
    ll n = s.size();
    for (ll i = 0; i <= n - 1; ++i)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            s[i] = 'a' + s[i] - 'A';
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= n - 1; ++i)
    {
        ans = ans * base + s[i];
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    ll n; cin >> n;
    string s; cin >> s;

    ll m; cin >> m;
    unordered_map<ll, string> d;
    for (ll i = 0; i <= m - 1; ++i)
    {
        string temp; cin >> temp;
        d[_hash(temp)] = temp;
    }

    vector<string> dp(n);
    for (ll i = 0; i <= n - 1; ++i)
    {
        ll nowH = 0;
        for (int j = i; j >= 0; --j)
        {
            nowH = nowH * base + s[j];
            
            if (d.count(nowH) > 0)
            {
                if (j == 0)
                {
                    dp[i] = d[nowH];
                    break;
                }
                else if (dp[j - 1].size() > 0)
                {
                    dp[i] = d[nowH];
                    break;
                }
            }
        }
    }

    vector<string> out;
    for (int i = n - 1; i >= 0; i -= dp[i].size())
    {
        out.push_back(dp[i]);
    }

    ll size = out.size();
    for (int i = size - 1; i >= 0; --i)
    {
        if (i < size - 1) cout << ' ';
        cout << out[i];
    }
    cout << '\n';

   	cout.flush();
   	return 0;
}

