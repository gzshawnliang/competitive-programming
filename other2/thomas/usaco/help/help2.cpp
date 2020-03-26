#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("help.in", "r", stdin);
        //freopen("CF_839D_Winterishere.out", "w", stdout);
    #endif
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (auto & a : v)
        cin >> a.first >> a.second;

    vector<int> over(2 * N + 1);
    vector<int> pow2(N);

    pow2[0] = 1;
    for (int i = 1; i < N; ++i)
        pow2[i] = 2 * pow2[i - 1] % MOD;

    for (auto & t : v)
    {
        ++over[t.first];
        --over[t.second];
    }

    for (int i = 1; i <= 2 * N; ++i)
        over[i] += over[i - 1];
    
    int ans = 0;
    for (auto & t : v)
        ans = (ans + pow2[N - 1 - over[t.first - 1]]) % MOD;

    cout << ans << "\n";
}


