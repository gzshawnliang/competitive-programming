/*
===========================================================
 * @名称:    633C Spy Syndrome 2
 * @作者:    Thomas 
 * @创建时间: 2019-11-09 11:53:46 
 * @修改人:   Thomas 
 * @修改时间: 2019-11-09 11:53:46 
 * @备注:     哈希+动态规划
 * @题目来源： https://codeforces.com/contest/633/problem/C
===========================================================
*/

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
            //计算哈希                      转成小写
            hashValue1 = R1 * hashValue1 + tolower(w[i]);
        
        wordHashMap[hashValue1] = w;
    }

    // //dpHash[i]表示从截止到第i个字符为止的单词是什么，这个数组存储哈希值,查看CF_633C_SpySyndrome2.xlsx
    // vector<ll> dpHash(n + 1, -1);

    //dpHash[i]表示从截止到第i个字符为止的单词是什么，这个数组存单词，查看CF_633C_SpySyndrome2.xlsx
    vector<string> dpString(n + 1, "");

    int i = 0;
    //dpHash[0] = 0;
    dpString[0] = "-1";
    while (i <= n - 1)
    {
        ull hashValue1 = 0;
        for (int j = i; j >= 0; --j) //反向查找
        {
            hashValue1 = R1 * hashValue1 + t[j]; //反向计算j-i字符的哈希

            //dpHash[j].empty() == false表示这个单词前面已经有了单词了，保证不间断
            //                                  wordHashMap.count(hashValue1)确保有这个单词
            if (dpString[j].empty() == false && wordHashMap.count(hashValue1) == 1)
            {
                //dpString[i + 1] = wordHashMap[hashValue1];
                dpString[i+1] = wordHashMap[hashValue1];
                break;
            }
        }
        ++i;
    }

    i = n;
    vector<string> ans;
    while (i > 0)
    {
        string w = dpString[i];
        ans.push_back(w);
        i -= w.size();
    }

    for (auto it = ans.rbegin(); it < ans.rend(); ++it)
        cout << *it << " ";

    //递归输出
    //print(n,wordHashMap,dpHash);

    return 0;
}
