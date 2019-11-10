#include <bits/stdc++.h>

using namespace std;


using ll = unsigned long long;

const ll k = 3, mod = 100000000743856857ll;

ll _hash(string & s)
{
    ll ans = 0, base = 1;

    int size = s.size();
    for (int i = 0; i <= size - 1; ++i)
    {
        ans += ((base * (s[i] - 'a' + 1)) % mod);
        ans %= mod;

        base *= k;
        base %= mod;
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("wattoAndMechanism_CF514C.in", "r", stdin);

    #endif

    int n, m; cin >> n >> m;

    unordered_map<ll, int> lib;
    for (int c = 1; c <= n; ++c)
    {
        string temp; cin >> temp;
        lib[_hash(temp)] = 1;
    }

    for (int c = 1; c <= m; ++c)
    {
        string s; cin >> s;
        int size = s.size();

        bool flag = false;

        ll now = _hash(s), base = 1;
        for (int i = 0; i <= size - 1 && flag == false; ++i)
        {
            if (i == 10)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            for (ll ch = 'a'; ch <= 'c' && flag == false; ++ch)
            {
                if (ch == (ll)s[i]) continue;

                //ll next = now + ((base % mod) * (ch - (ll)s[i])) % mod;
                ll next = (mod + now - ((ll)s[i] * base) % mod + (ch * base) % mod) % mod;

                next %= mod;

                if (lib.count(next) == 1)
                {
                    if (lib[next] == 1)
                    {
                        flag = true;
                    }
                }
            }

            // base *= k;
            // base %= mod;
            base = (base * k) % mod;
        }

        if (flag == true)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

   	cout.flush();
   	return 0;
}

