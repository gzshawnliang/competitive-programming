/*
===========================================================
* @Name:           113B Petr#
* @Author:         Thomas
* @create Time:    2019/11/12 18:10:00
* @url:            https://codeforces.com/contest/113/problem/B
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ull R1 = 131; //质数

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
    ull h1 = hashcode(s1);
    //int len1 = s1.length();

    ull h2 = hashcode(s2);
    int len2 = s2.length();

    unordered_set<ull> ansMap;
    ull ans=0;

    int n = t.length();

    for (int i = 0; i <= n - 1; ++i)
    {
        bool findStartSub=false;

        ull hashValue1 = 0;
        ull hashTotal = 0;
        for (int j = i; j <= n - 1; ++j) //查找SubString
        {
            hashTotal = R1 * hashTotal + t[j];

            if (findStartSub==false)
            {
                hashValue1 = R1 * hashValue1 + t[j];

                if (hashValue1 == h1) //SubString:begin
                    findStartSub=true;

            }

            if(findStartSub==true && j-i+1>=len2)
            {
                ull hashValue2 = 0;
                for (int k = j-len2+1; k <= j; ++k)
                {
                    hashValue2 = R1 * hashValue2 + t[k];
                    if(hashValue2 == h2)
                    {
                        if(ansMap.count(hashTotal)==0)
                        {
                            ansMap.insert(hashTotal);
                            ++ans;
                        }
                        break;
                    }
                }                
            }
        }
    }
    cout << ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_113B_Petr#.in", "r", stdin);
    //freopen("CF_113B_Petr#.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}
