/*
===========================================================
* @Name:           1200E Compress Words
* @Author:         Thomas
* @create Time:    2019/11/18 9:45:43
* @url:            https://codeforces.com/contest/1200/problem/E
* @Description:    哈希好题
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll P1 = 131;
const ll MOD1 = 201326611;

vector<ll> ansHash;
vector<ll> pow1;

//O(1)取出子串的哈希值，使用之前需要测试
ll subStrHash(int l, int r)
{
    ll ret1;
    if (l == 0)
    {
        ret1 = (ansHash[r] % MOD1 + MOD1) % MOD1;
    }
    else
    {
        ret1 = ((ansHash[r] - ansHash[l - 1] * pow1[r - l + 1]) % MOD1 + MOD1) % MOD1;
    }
    return ret1;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    int totalLen = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        totalLen += a[i].length();
    }

    ansHash.assign(totalLen, 0);
    pow1.assign(totalLen, 0);

    pow1[0] = 1;
    for (int i = 1; i <= totalLen - 1; ++i)
    {
        pow1[i] = pow1[i - 1] * P1 % MOD1;
    }

    string ans = a[0];

    ll hashValue1 = 0;
    int ansLen = ans.length();
    for (int i = 0; i <= ansLen - 1; ++i)
    {
        //计算哈希
        hashValue1 = (P1 * hashValue1 + ans[i]) % MOD1;
        ansHash[i] = hashValue1;
    }

    for (int i = 1; i <= n - 1; ++i)
    {
        int maxPrefixPos = 0; //前缀最大位置
        int beginPosSuffix = ans.length() - 1;

        //查找前缀的长度，超出a[i]或ans的长度不用再找了
        int searchPrefixLen = min((int)a[i].length()-1,beginPosSuffix);

        //前缀哈希值
        ll hashPrefix = 0;
        for (int j = 0; j <= searchPrefixLen; ++j)
        {

            //计算前缀哈希值
            hashPrefix = (P1 * hashPrefix + a[i][j]) % MOD1;

            //计算后缀哈希值
            ll hashSuffix = subStrHash(beginPosSuffix - j, beginPosSuffix);

            //字符串相同
            if (hashPrefix == hashSuffix)
                maxPrefixPos = j + 1;
        }

        //增加ans的哈希值
        string subStr = a[i].substr(maxPrefixPos);
        int subLen = subStr.length();
        int j = ans.length() - 1;
        ll hAns = ansHash[j];
        for (int i = 0; i <= subLen - 1; ++i)
        {
            ++j;
            hAns = (P1 * hAns + subStr[i]) % MOD1;
            ansHash[j] = hAns;
        }

        //增加ans的字符串
        ans += subStr;
    }

    cout << ans << "\n";
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