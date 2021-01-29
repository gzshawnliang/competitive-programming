#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

int stor1[1<<10][20], stor2[1<<10][20];
 
int main() {
    freopen("aac.in", "r", stdin);
    freopen("aac.out", "w", stdout);    
	string s; cin >> s;
	map<char,int> m; for(char c: s) m[c] = 0;
	int cnt = 0; for (auto& t: m) t.s = cnt++;
	int N = m.size(); assert(N <= 20);
	vector<vector<int>> oc(N,vector<int>(N));
	for (int i = 0; i+1 < s.size(); ++i) 
		++oc[m[s[i]]][m[s[i+1]]];
	vector<int> dp(1<<N,1e9);
	dp[0] = 1;
	int bits = N/2;
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < 1<<bits; ++i) 
			for (int k = 0; k < bits; ++k) if (i&1<<k) 
				stor1[i][j] += oc[k][j];
		for (int i = 0; i < 1<<(N-bits); ++i) 
			for (int k = 0; k < N-bits; ++k) if (i&1<<k)
				stor2[i][j] += oc[bits+k][j];
	}
	for (int i = 0; i < 1<<N; ++i)
		for (int j = 0; j < N; ++j) if (i&1<<j) {
			int sum = dp[i^1<<j];
			sum += stor1[i&((1<<bits)-1)][j];
			sum += stor2[i>>bits][j];
			dp[i] = min(dp[i],sum);
		}
	cout << dp[(1<<N)-1] << "\n";
}