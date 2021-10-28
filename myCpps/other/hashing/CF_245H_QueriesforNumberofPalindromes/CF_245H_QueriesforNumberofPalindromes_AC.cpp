/*
===========================================================
* @Name:           245H Queries for Number of Palindromes
* @Author:         Shawn
* @create Time:    2019/11/24 21:03:07
* @url:            https://codeforces.com/contest/245/problem/H
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

int ans[5001][5001];

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

    ll hashValue1 = 0;
    ll hashValue2 = 0;

    int sLen = s.length();
    hashArray1.assign(sLen, 0);
    hashArray2.assign(sLen, 0);

    int j = sLen - 1;
    for (int i = 0; i <= sLen - 1; ++i)
    {
        //计算哈希
        hashValue1 = (BASE * hashValue1 + s[i]) % PRIME;
        hashValue2 = (BASE * hashValue2 + s[j]) % PRIME;

        hashArray1[i] = hashValue1;
        hashArray2[i] = hashValue2;
        --j;

        ans[i][i] = 1;
    }

    powArray.assign(sLen, 0);
    powArray[0] = 1;
    for (int i = 1; i <= sLen - 1; ++i)
    {
        powArray[i] = powArray[i - 1] * BASE % PRIME;
    }

    for (int len = 2; len <= sLen; ++len)
    {
        for (int i = 0; i <= sLen - 1; ++i)
        {
            int j = i + len - 1;
            if (j > sLen - 1)
                break;

            int isPalindromes_I_J = 0;               //子串i-j是不是回文，0不是，1是
            ll has1 = subStrHash1(i, j);

            int i2 = sLen - 1 - j;
            int j2 = sLen - 1 - i;
            ll has2 = subStrHash2(i2, j2);

            if (has1 == has2)
                isPalindromes_I_J = 1;

            ans[i][j] = ans[i + 1][j] + ans[i][j - 1] - ans[i + 1][j - 1] + isPalindromes_I_J;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;

        cout << ans[l][r] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_245H_QueriesforNumberofPalindromes.in", "r", stdin);
    //freopen("CF_245H_QueriesforNumberofPalindromes.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}