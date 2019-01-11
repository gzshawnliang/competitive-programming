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

ifstream fin("colossalFibonacciNumbers_UVA11582.in");
ofstream fout("colossalFibonacciNumbers_UVA11582.out");

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
    int T; fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        ll a, b, n; fin >> a >> b >> n;

        vector<ll> F(2); F[0] = 0; F[1] = 1 % n;

        int mod = solve(n, F);

        fout << F[quick(a, b, mod)] << '\n';
    }

    return 0;
}