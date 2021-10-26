/*
===========================================================
 * @名称:		D. Good Substrings
 * @作者:		Thomas 
 * @创建时间: 2019-10-09 16:38:22 
 * @修改人:   Thomas
 * @修改时间: 2019-10-09 16:38:22 
 * @备注:	    AC: Time:1560 ms	Memory:35300 KB	
 * @题目来源： https://codeforces.com/contest/271/problem/D
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

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
    vector<unsigned long long> ex(lenStr+1,0);

    ex[0] = 1;
    for (int i = 1; i <= lenStr-1; ++i)
        ex[i] = ex[i-1] * R;
    

    vector<unsigned long long> hashCode(lenStr+1,0);
    hashCode[0] = s[0];
    for (int i = 1; i <= lenStr-1; ++i)
        hashCode[i] = (hashCode[i - 1] * R + s[i]);    

    set<unsigned long long> goodStrSet;
    unsigned long long ans = 0;
    
    for (int i = 0; i <= lenStr - 1; ++i)
    {
        int badCout = 0;
        
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

            //h = (h * R + (unsigned long long)s[j]) % PRIME;
            //h = (h * R + (unsigned long long)s[j]);
            unsigned long long h;
            if(i==0)
            {
                h = hashCode[j];
            }
            else
            {
                h = hashCode[j] - hashCode[i-1] * ex[j - i + 1];
            }
            
            
            if (goodStrSet.count(h) == 0)
            {
                goodStrSet.insert(h);
                ++ans;
            }

            //cout << h << '\n';
        }
    }

    std::cout << ans << '\n';

    return 0;
}
