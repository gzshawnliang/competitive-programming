/*
===========================================================
* @Name:           7D Palindrome Degree
* @Author:         Shawn
* @create Time:    2019/12/7 21:31:39
* @url:            https://codeforces.com/contest/7/problem/D
* @Description:    
===========================================================
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
ll MOD = 1e9 + 7, base = 137;
 
ll isPalindromes(bool reverse, int i, int j, ll nowBase, vector<ll> & startHash, vector<ll> & endHash)
{
    if (reverse == false) return ((startHash[j] - startHash[i - 1] * nowBase) % MOD + MOD) % MOD;
    else return ((endHash[i] - endHash[j + 1] * nowBase) % MOD + MOD) % MOD;
}
 
void solve()
{
    string s; cin >> s;
    int n = s.size();
 
    s = ' ' + s;
 
    vector<ll> startHash(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        startHash[i] = ((startHash[i - 1] * base + MOD) % MOD + s[i] + MOD) % MOD;
    }
    vector<ll> endHash(n + 2, 0);
    for (int i = n; i >= 1; --i)
    {
        endHash[i] = ((endHash[i + 1] * base + MOD) % MOD + s[i] + MOD) % MOD;
    }
 
    vector<ll> allBase(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        allBase[i] = (allBase[i - 1] * base) % MOD;
    }
 
    ll ans = 0;
    vector<ll> allCount(n + 1, 0);
 
    for (int size = 1; size <= n; ++size)
    {
        ll nowBase = allBase[size / 2];
        if (isPalindromes(0, 1, size / 2, nowBase, startHash, endHash) == isPalindromes(1, size - size / 2 + 1, size, nowBase, startHash, endHash))
        {
            allCount[size] = allCount[size / 2] + 1;
        }
 
        ans += allCount[size];
    }
 
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_7D_PalindromeDegree.in", "r", stdin);
        freopen("CF_7D_PalindromeDegree.out", "w", stdout);
    #endif    
 
    solve();
 
 
    cout.flush();
    return 0;
}