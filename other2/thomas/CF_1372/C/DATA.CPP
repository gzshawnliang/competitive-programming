#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000+5;
int dp[maxn][maxn];
int n;
int col[maxn];
int main() {

#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	vector<int> a,b;
	for(int i = 1; i <= n; ++i) {
		int c; 
		scanf("%d", &c);
		if(a.size() > 0){
			if(c != a.back()) {
				a.push_back(c);
			}
		}
		else 
			a.push_back(c);
	}
	b = a;
	n = a.size();
	reverse(b.begin(), b.end());
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(a[i-1] == b[j-1]) 
				dp[i][j] = dp[i-1][j-1]+1;
			else 
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	// cout << n << endl;
	cout << n-dp[n][n]/2-1 << endl;
	return 0;
}
