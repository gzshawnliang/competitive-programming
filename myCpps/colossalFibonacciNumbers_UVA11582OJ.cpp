#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ll;


ll quick(ll a, ll b, ll n)
{
    a %= n;
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans *= a; ans %= n;
        }
        a *= a; a %= n;

        b /= 2;
    }

    return ans;
}

ll solve(ll n, vector<ll> & F)
{
    int i = 2;
    while (true)
    {
        F.push_back((F[i - 1] + F[i - 2]) % n);

        if (F[i] == F[1] && F[i - 1] == F[0])
        {
            return i - 1;
        }

        ++i;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        ll a, b, n; cin >> a >> b >> n;

        vector<ll> F(2); F[0] = 0; F[1] = 1 % n;

        int mod = solve(n, F);

        cout << F[quick(a, b, mod)] << '\n';
    }

   	cout.flush();
   	return 0;
}
