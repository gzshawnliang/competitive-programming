#include <bits/stdc++.h>

using namespace std;

ifstream fin("wattoAndMechanism_CF514C.in");
ofstream fout("wattoAndMechanism_CF514C.out");

using ll = long long;

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
    int n, m; fin >> n >> m;

    unordered_map<ll, int> lib;
    for (int c = 1; c <= n; ++c)
    {
        string temp; fin >> temp;
        lib[_hash(temp)] = 1;
    }

    for (int c = 1; c <= m; ++c)
    {
        string s; fin >> s;
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

                ll next = now + ((base % mod) * (ch - (ll)s[i])) % mod;
                next %= mod;

                if (lib.count(next) == 1)
                {
                    if (lib[next] == 1)
                    {
                        flag = true;
                    }
                }
            }

            base *= k;
            base %= mod;
        }

        if (flag == true)
        {
            fout << "YES\n";
        }
        else
        {
            fout << "NO\n";
        }
    }

    return 0;
}
