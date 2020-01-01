#include <bits/stdc++.h>

using namespace std;

#define reg register
#define ge getchar()
#define Re read()
#define FI "poetry.in"
#define FO "poetry.out"
#define MAXN 5000
#define mod 1000000007

inline int read() {
    reg int x = 0, ch;
    while(!isdigit(ch = ge)) ;
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = ge;
    return x;
}

int f[MAXN + 1][MAXN + 1];
int s[MAXN + 1];
int l[MAXN + 1];
int y[MAXN + 1];
int cnt[26];

inline int quick_pow(reg int x, reg int k) {
    reg int s = 1;
    while(k) {
        if(k & 1) s = (1LL * s * x) % mod;
        x = (1LL * x * x) % mod;
        k >>= 1;
    }
    return s;
}

int main() {
    freopen(FI, "r", stdin);
    freopen(FO, "w", stdout);
    reg int n = Re;
    reg int m = Re;
    reg int k = Re;
    s[0] = 1;
    for(reg int i = 1; i <= n; i++) l[i] = Re, y[i] = Re;
    for(reg int i = 1; i <= k; i++) {
        for(reg int j = 1; j <= n; j++) {
            if(i >= l[j]) {
                f[i][y[j]] = (f[i][y[j]] + s[i - l[j]]) % mod;
                s[i] = (s[i] + s[i - l[j]]) % mod;
            }
        }
    }
    for(reg int i = 1; i <= m; i++) {
        reg char ch;
        while(!isalpha(ch = ge)) ;
        cnt[ch - 'A']++;
    }
    reg int res = 1;
    for(reg int i = 0; i < 26; i++) {
        if(!cnt[i]) continue;
        reg int ans = 0;
        for(reg int j = 1; j <= n; j++)
            if(f[k][j])
                ans = (ans + quick_pow(f[k][j], cnt[i])) % mod;
        res = 1LL * res * ans % mod;
    }
    cout << res << endl;
    return 0;
}