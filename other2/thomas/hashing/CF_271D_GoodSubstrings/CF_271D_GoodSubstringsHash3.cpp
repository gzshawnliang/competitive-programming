/*
===========================================================
 * @名称:		D. Good Substrings
 * @作者:		Thomas 
 * @创建时间: 2019-10-09 16:38:22 
 * @修改人:   Thomas
 * @修改时间: 2019-10-09 16:38:22 
 * @备注:	 unordered_set   AC： 872 ms	         Memory:37500 KB
 *          unordered_map    AC: Time:1154 ms	Memory:45900 KB	
 * @题目来源： https://codeforces.com/contest/271/problem/D
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

//unsigned long long 最大值 18446744073709551615ULL 一千八百亿亿
const unsigned long long R = 10007;
const unsigned long long PRIME = 1000000007;

int idx(char c)
{
    return c - 'a';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("CF_271D_GoodSubstrings.in", "r", stdin);
    freopen("CF_271D_GoodSubstrings.out", "w", stdout);
#endif
    string s;
    cin >> s;

    string goobBadStr;
    cin >> goobBadStr;
    int k;
    cin >> k;

    reverse(goobBadStr.begin(), goobBadStr.end());
    bitset<27> isGood = bitset<27>(goobBadStr);
    
    int lenStr = s.length();

    //set<unsigned long long> goodStrSet;
    unordered_set<unsigned long long> goodStrSet;
    unsigned long long ans = 0;
    
    for (int i = 0; i <= lenStr - 1; ++i)
    {
        int badCout = 0;
        unsigned long long subStrHash = 0;      //子串哈希值
        for (int j = i; j <= lenStr - 1; ++j)
        {
            int c = idx(s[j]);
            if (isGood[c] == 0) //bad char
            {
                ++badCout;
            }
            if (badCout > k)
            {
                break;
            }
            
            /*计算方法  字母   哈希值 
                       1   = 1
                       12  = 1*10+2
                       123 = 12*10+3
            */
            subStrHash = (subStrHash * R + s[j]);
            
            if (goodStrSet.count(subStrHash) == 0)
            {
                //goodStrSet[subStrHash]=true;
                goodStrSet.insert(subStrHash);
                ++ans;
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}
