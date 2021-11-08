/*
===========================================================
* @Name:           835D Palindromic characteristics
* @Author:         Shawn
* @create Time:    2019/12/13 16:03:49
* @url:            https://codeforces.com/contest/835/problem/D
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll BASE = 131;
const ll PRIME = 1e9 + 7;

vector<ll> hashArray1;
vector<ll> hashArray2;
vector<ll> powArray;
vector<vector<int>> isPalindromic; //isPalindromic[i][j]代表i-j是不是回文数

//O(1)取出子串的哈希值，使用之前注意测试
ll subStrHash1(int l, int r)
{
    if (l == 0)
        return (hashArray1[r] % PRIME + PRIME) % PRIME;
    else
        return ((hashArray1[r] - hashArray1[l - 1] * powArray[r - l + 1]) % PRIME + PRIME) % PRIME;
}

//O(1)取出反向子串的哈希值，使用之前注意测试
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
    int n = s.length();

    hashArray1.assign(n, 0); //存储s的哈希
    hashArray2.assign(n, 0); //存储s的反向哈希
    powArray.assign(n, 0);

    isPalindromic.assign(n, vector<int>(n, 0));

    powArray[0] = 1;
    for (int i = 1; i <= n - 1; ++i)
    {
        powArray[i] = powArray[i - 1] * BASE % PRIME;
    }

    ll hashValue1 = 0;
    ll hashValue2 = 0;
    int j = n - 1;
    for (int i = 0; i <= n - 1; ++i)
    {
        //计算哈希
        hashValue1 = (BASE * hashValue1 + s[i]) % PRIME;
        hashValue2 = (BASE * hashValue2 + s[j]) % PRIME;

        hashArray1[i] = hashValue1;
        hashArray2[i] = hashValue2;
        --j;
    }

    //检查长度是len的前缀是否回文
    auto checkIsPalindrome = [=](int i, int j) {
        ll has1 = subStrHash1(i, j);
        ll has2 = subStrHash2(n - j - 1, n - i - 1);
        if (has1 == has2)
        {
            return true;
        }

        return false;
    };
    
    auto getHash = [=](int i, int j) {
        return subStrHash1(i, j);
    };

    int ans = 0;

    //从长度1开始查找回文字符
    vector<int> degree(n + 1, 0);

    for (int i = 0; i <= n -1; ++i)
    {
        for (int len = 1; len <= n-i; ++len)
        {
            int j = i + len - 1;
            if (checkIsPalindrome(i, j))
            {
                isPalindromic[i][j] = 1;
                ++degree[isPalindromic[i][j]];
                //++degree[1];
                if (j > i)
                {
                    int m = i+(j - i) / 2;
                    int k=0;
                    if ((j - i) % 2 == 0)
                    {
                        
                        if (getHash(i, m - 1) == getHash(m + 1, j))
                        {
                            k=isPalindromic[i][m-1]+1;
                            isPalindromic[i][j]=k;
                            ++degree[k];
                            //cout << s.substr(i,j-i+1) << ":" << k << "\n";
                        }
                    }
                    else
                    {
                        if (getHash(i, m) == getHash(m + 1, j))
                        {
                            k=isPalindromic[i][m]+1;
                            isPalindromic[i][j]=k;
                            ++degree[k];
                            //cout << s.substr(i,j-i+1) << ":" << k << "\n";
                        }
                    }

                    while (k>0)
                    {
                        --k;
                        if(k>1)
                            ++degree[k];
                    }
                }
                ++ans;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << degree[i] << " ";

}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_835D_Palindromiccharacteristics.in", "r", stdin);
    //freopen("CF_835D_Palindromiccharacteristics.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}