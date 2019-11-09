#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ull R1 = 131; //质数

void print(int len, unordered_map<ull, string> & wordHashMap, const vector<ll> & dp)
{
    if (len == 0)
        return;

    ull currHash = dp[len];
    int len2 = len - wordHashMap[currHash].size();
    print(len2, wordHashMap, dp);

    cout << wordHashMap[currHash] << " ";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_633C_SpySyndrome2.in", "r", stdin);
        //freopen("CF_182D_CommonDivisors.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    string t;
    cin >> t;

    int m;
    cin >> m;
    unordered_map<ull, string> wordHashMap;

    for (int i = 0; i <= m - 1; ++i)
    {
        string w;
        cin >> w;
        int len = w.length();
        ull hashValue1 = 0;
        for (int i = 0; i <= len - 1; ++i)
        {
            //计算哈希                      转成小写
            hashValue1 = R1 * hashValue1 + tolower(w[i]);
        }
        wordHashMap[hashValue1] = w;
    }

    vector<ll> dp(n + 1, -1); //dp[i]表示从第i个字符

    int i = 0;
    dp[0] = 0;
    while (i <= n - 1)
    {
        ull hashValue1 = 0;
        for (int j = i; j >= 0; --j) //反向查找
        {
            hashValue1 = R1 * hashValue1 + t[j]; //反向计算j-i字符的哈希

            if (dp[j] != -1 && wordHashMap.count(hashValue1) == 1)
            {
                dp[i + 1] = hashValue1;
                break;
            }
        }
        ++i;
    }

    i = n;
    vector<string> ans;
    while (i > 0)
    {
        string w = wordHashMap[dp[i]];
        ans.push_back(w);
        i -= w.size();
    }
    for (auto it = ans.rbegin(); it < ans.rend(); ++it)
    {
        cout << *it;

        if (it != ans.rend()-1 )
            cout << " ";
    }

    //递归输出
    //print(n,wordHashMap,dp);

    return 0;
}
