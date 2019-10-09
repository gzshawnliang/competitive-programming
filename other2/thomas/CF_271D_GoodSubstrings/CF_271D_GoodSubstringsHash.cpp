/*
===========================================================
 * @名称:		D. Good Substrings
 * @作者:		Thomas 
 * @创建时间: 2019-10-09 16:38:22 
 * @修改人:   Thomas
 * @修改时间: 2019-10-09 16:38:22 
 * @备注:		
 * @题目来源： https://codeforces.com/contest/271/problem/D
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

const unsigned long long R = 26;
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

    
    set<int> goodStrSet;

    int lenStr =s.length();
    for (int i = 0; i <= lenStr - 1; ++i)
    {
        int badCout = 0;
        unsigned long long h=s[i] % PRIME;
        for (int j = 0; i+j <= lenStr - 1; ++j)
        {
            int c = idx(s[i + j]);
            if (isGood[c] == 0) //bad char
            {
                ++badCout;
            }
            if (badCout > k)
            {
                break;
            }
            if(j>0)
                h = (h * R + (unsigned long long)s[i + j]) % PRIME;

            goodStrSet.insert(h);
            //cout << h << '\n';
        }        
    }
    cout << goodStrSet.size() << '\n';
    return 0;
}
