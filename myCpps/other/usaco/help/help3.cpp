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
    int maxN=0;
    for (auto & a : v)
    {
        cin >> a.first >> a.second;
        maxN=max(maxN,a.second+1);
    }

    vector<int> over(2 * N + 1);
    vector<int> pow2(N);

    pow2[0] = 1;
    for (int i = 1; i < N; ++i)
        pow2[i] = 2 * pow2[i - 1] % MOD;

    vector<int> l(N+1);
    vector<int> r(N+1);
    vector<int> dp(N+1);
    
    vector<int> t(maxN+1);
    vector<int> sum(maxN+1);
    
    int i=1;
    for (auto & a : v)
    {
		l[i]=a.first;
		r[i]=a.second;
		++t[r[i]];
        ++i;
	}

	for (int i=1;i<=maxN;++i)
		sum[i]=sum[i-1]+t[i];
    
    for (int i=1;i<=N;++i)
		dp[i] = (dp[i-1]*2ll+pow2[sum[l[i]-1]])%MOD;

    cout << dp[N] << "\n";
}


