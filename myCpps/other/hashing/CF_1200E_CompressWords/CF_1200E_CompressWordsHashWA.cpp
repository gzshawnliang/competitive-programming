/*
===========================================================
* @Name:           1200E Compress Words
* @Author:         Shawn
* @create Time:    2019/11/18 9:45:43
* @url:            https://codeforces.com/contest/1200/problem/E
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>
 
using namespace std;

using ll = long long;
 
const ll P1 = 131;
const ll MOD1 = 201326611;
 
const ll P2 = 113;
const ll MOD2 = 402653189;
 
vector<ll> h1;
vector<ll> h2;
vector<ll> pow1;
vector<ll> pow2;
 
pair<ll, ll> subStrHash(int l, int r)
{
    ll ret1, ret2;
    if (l == 0)
    {
        ret1 = (h1[r] % MOD1 + MOD1) % MOD1;
        ret2 = (h2[r] % MOD2 + MOD2) % MOD2;
    }
    else
    {
        ret1 = ((h1[r] - h1[l - 1] * pow1[r - l + 1]) % MOD1 + MOD1) % MOD1;
        ret2 = ((h2[r] - h2[l - 1] * pow2[r - l + 1]) % MOD2 + MOD2) % MOD2;
    }
    return make_pair(ret1, ret2);
}
 
void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> pos(n);
 
    string t = "";
 
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        t += a[i];
        if (i == 0)
            pos[i] = a[i].length() - 1;
        else
            pos[i] = pos[i - 1] + a[i].length();
    }
    int len = t.length();
 
    h1.assign(len, 0);
    h2.assign(len, 0);
    pow1.assign(len, 0);
    pow2.assign(len, 0);
 
    pow1[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i <= len - 1; ++i)
    {
        pow1[i] = pow1[i - 1] * P1 % MOD1;
        pow2[i] = pow2[i - 1] * P2 % MOD2;
    }
 
    ll hashValue1 = 0;
    ll hashValue2 = 0;
    for (int i = 0; i <= len - 1; ++i)
    { //计算哈希
        hashValue1 = (P1 * hashValue1 + t[i]) % MOD1;
        hashValue2 = (P2 * hashValue2 + t[i]) % MOD2;
        h1[i] = hashValue1;
        h2[i] = hashValue2;
    }
 
    string ans = a[0];
    for (int i = 1; i <= n - 1; ++i)
    {
        int maxJ = 0;
        int beginPos = pos[i - 1] + 1;
        for (int j = beginPos; j <= pos[i]; ++j)
        {
            int currLen = j - beginPos + 1;
            auto sub1 = subStrHash(beginPos, j);
            auto sub2 = subStrHash(beginPos - currLen, beginPos - 1);
 
            if (sub1.first == sub2.first && sub1.second == sub2.second) //字符串相同
                maxJ = j;
        }
        if (maxJ > 0)
            ans += a[i].substr(maxJ - beginPos + 1);
        else
            ans += a[i];
    }
    cout << ans << "\n";
    //cout << ans.length() << "\n";
 
    // auto sa = subStrHash(0, 0);
    // auto sb = subStrHash(6, 8);
    // cout << sa.first << "," << sa.second << "\n";
    // cout << sb.first << "," << sb.second << "\n";
    //cerr<< "";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1200E_CompressWords.in", "r", stdin);
    //freopen("CF_1200E_CompressWords.out", "w", stdout);
#endif
 
    solve();
 
    cout.flush();
    return 0;
}