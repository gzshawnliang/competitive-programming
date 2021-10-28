/*
===========================================================
* @Name:           113B Petr#
* @Author:         Shawn
* @create Time:    2019/11/12 18:10:00
* @url:            https://codeforces.com/contest/113/problem/B
* @Description:    优化版
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ull R1 = 137; //质数

ull hashcode(const string & x)
{
    int len = x.length();
    ull hashValue1 = 0;
    for (int i = 0; i <= len - 1; ++i)
        //计算哈希
        hashValue1 = R1 * hashValue1 + x[i];
    return hashValue1;
}

void solve()
{
    string t, s1, s2;
    cin >> t >> s1 >> s2;
    ull hBegin = hashcode(s1);
    int lenBegin = s1.length();

    ull hEnd = hashcode(s2);
    int lenEnd = s2.length();

    unordered_set<ull> ansMap;
    ull ans = 0;

    int n = t.length();
    int sumCount =0;
    for (int i = 0; i <= n - 1; ++i)
    {
        bool findStartSub = false;

        ull hashBegin = 0;                  //SubString:begin的哈希值
        ull hashIJ = 0;                     //i~j字符串的哈希值
        for (int j = i; j <= n - 1; ++j)    //查找SubString
        {
            if (findStartSub==false && j - i + 1 > lenBegin) //超出SubString:begin的长度仍未找到前缀
                break;

            hashIJ = R1 * hashIJ + t[j];

            if (findStartSub == false)
            {
                hashBegin = R1 * hashBegin + t[j];

                if (hashBegin == hBegin) //SubString:begin
                    findStartSub = true;
            }

            if (findStartSub == true && j - i + 1 >= lenEnd)
            {
                ull hashEnd = 0; //SubString:end的哈希值
                for (int k = j - lenEnd + 1; k <= j; ++k)
                {
                    hashEnd = R1 * hashEnd + t[k];
                    ++sumCount;
                    if (hashEnd == hEnd)
                    {
                        if (ansMap.count(hashIJ) == 0) //找到答案，放入唯一的set
                        {
                            ansMap.insert(hashIJ);
                            ++ans;
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    //cout << sumCount << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_113B_Petr#.in", "r", stdin);
    freopen("CF_113B_Petr#.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}
