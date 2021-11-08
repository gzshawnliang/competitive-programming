/*
===========================================================
* @Name:           1200E Compress Words
* @Author:         Shawn
* @create Time:    2019/11/18 9:45:43
* @url:            https://codeforces.com/contest/1200/problem/E
* @Description:    Double Hash版本
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
 
pair<ll, ll> subStrHash(unsigned int l, unsigned int r)
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
    int len =0;
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        len +=a[i].length();
    }
    ++len;
 
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

    string ans = a[0];
 
    ll hashValue1 = 0;
    ll hashValue2 = 0;
    int ansLen=ans.length();
    for (int i = 0; i <= ansLen - 1; ++i)
    {   //计算哈希
        hashValue1 = (P1 * hashValue1 + ans[i]) % MOD1;
        hashValue2 = (P2 * hashValue2 + ans[i]) % MOD2;
        h1[i] = hashValue1;
        h2[i] = hashValue2;
    }

    for (int i = 1; i <= n - 1; ++i)
    {
        int maxJ = 0;
        int beginPos = ans.length() - 1;
        int aLen=a[i].length();
        ll hashValue1 = 0;
        ll hashValue2 = 0;
        for (int j = 0; j <= aLen-1; ++j)
        {
            if(j>beginPos)
                break;            

            hashValue1 = (P1 * hashValue1 + a[i][j]) % MOD1;
            hashValue2 = (P2 * hashValue2 + a[i][j]) % MOD2;

            auto sub2 = subStrHash(beginPos - j, beginPos);
 
            if (hashValue1 == sub2.first && hashValue2 == sub2.second) //字符串相同
                maxJ = j+1;
        }
        
        string subStr=a[i].substr(maxJ);
           
        int subLen=subStr.length();
        int j=ans.length()-1;
        
        ll hashValue_1 = h1[j];
        ll hashValue_2 = h2[j];
        for (int i = 0; i <= subLen - 1; ++i)
        {
            ++j;
            hashValue_1 = (P1 * hashValue_1 + subStr[i]) % MOD1;
            hashValue_2 = (P2 * hashValue_2 + subStr[i]) % MOD2;
            h1[j] = hashValue_1;
            h2[j] = hashValue_2;
        }
        ans += subStr;
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