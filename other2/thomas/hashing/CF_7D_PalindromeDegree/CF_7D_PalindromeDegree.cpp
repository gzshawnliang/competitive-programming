/*
===========================================================
* @Name:           7D Palindrome Degree
* @Author:         Thomas
* @create Time:    2019/11/30 19:02:54
* @url:            https://codeforces.com/contest/7/problem/D
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;
const ll BASE = 131;
const ll PRIME = 1e9 + 7;

vector<ll> hashArray1;
vector<ll> hashArray2;
vector<ll> powArray;

//O(1)取出子串的哈希值，使用之前注意测试
ll subStrHash1(int l, int r)
{
    if (l == 0)
        return (hashArray1[r] % PRIME + PRIME) % PRIME;
    else
        return ((hashArray1[r] - hashArray1[l - 1] * powArray[r - l + 1]) % PRIME + PRIME) % PRIME;
}

ll subStrHash2(int l, int r)
{
    if (l == 0)
        return (hashArray2[r] % PRIME + PRIME) % PRIME;
    else
        return ((hashArray2[r] - hashArray2[l - 1] * powArray[r - l + 1]) % PRIME + PRIME) % PRIME;
}


void solve()
{
    string s;
    cin >> s;
    int sLen = s.length();

    hashArray1.assign(sLen, 0);
    hashArray2.assign(sLen, 0);

    powArray.assign(sLen, 0);
    powArray[0] = 1;
    for (int i = 1; i <= sLen - 1; ++i)
    {
        powArray[i] = powArray[i - 1] * BASE % PRIME;
    }

    ll hashValue1 = 0;
    ll hashValue2 = 0;
    int j = sLen - 1;
    for (int i = 0; i <= sLen - 1; ++i)
    {
        //计算哈希
        hashValue1 = (BASE * hashValue1 + s[i]) % PRIME;
        hashValue2 = (BASE * hashValue2 + s[j]) % PRIME;

        hashArray1[i] = hashValue1;
        hashArray2[i] = hashValue2;
        --j;
    }

    //检查长度是len的前缀是否回文
    auto checkIsPalindrome = [=](int len) {
        ll has1 = subStrHash1(0, len - 1);
        ll has2 = subStrHash2(sLen - len, sLen - 1);
        if (has1 == has2)
        {
            return true;
        }

        return false;
    };

    int ans = 0;
    vector<int> degree(sLen + 1, 0);
    for (int len = 1; len <= sLen; ++len)
    {
        if (checkIsPalindrome(len))
        {
            degree[len] = degree[len / 2] + 1;
            ans += degree[len];
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_7D_PalindromeDegree.in", "r", stdin);
    //freopen("CF_7D_PalindromeDegree.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}