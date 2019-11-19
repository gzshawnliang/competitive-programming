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

const ll BASE = 131;
const ll PRIME = 201326611;

vector<ll> hashArray;
vector<ll> powArray;

//O(1)取出子串的哈希值，使用之前注意测试
ll subStrHash(int l, int r)
{
    if (l == 0)
        return (hashArray[r] % PRIME + PRIME) % PRIME;
    else
        return  ((hashArray[r] - hashArray[l - 1] * powArray[r - l + 1]) % PRIME + PRIME) % PRIME;
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

    hashArray.assign(totalLen, 0);
    powArray.assign(totalLen, 0);

    powArray[0] = 1;
    for (int i = 1; i <= totalLen - 1; ++i)
        powArray[i] = powArray[i - 1] * BASE % PRIME;

    string ans = a[0];
    ll hashValue1 = 0;
    int ansLen = ans.length();
    for (int i = 0; i <= ansLen - 1; ++i)
    {
        //计算哈希
        hashValue1 = (BASE * hashValue1 + ans[i]) % PRIME;
        hashArray[i] = hashValue1;
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
            hashPrefix = (BASE * hashPrefix + a[i][j]) % PRIME;

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
        ll hAns = hashArray[j];
        for (int i = 0; i <= subLen - 1; ++i)
        {
            ++j;
            hAns = (BASE * hAns + subStr[i]) % PRIME;
            hashArray[j] = hAns;
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