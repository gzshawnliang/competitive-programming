/*
===========================================================
* @Name:           1200E Compress Words
* @Author:         Shawn
* @create Time:    2019/11/18 9:45:43
* @url:            https://codeforces.com/contest/1200/problem/E
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>
 
using namespace std;
 
using ull = unsigned long long;
 
void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    string ans="";
    unordered_set<string> lastSuffix;
    for (int i = 0; i <= n - 1; ++i)
    {        
        cin >> a[i];
        if(i==0)
            ans=a[i];
 
        unordered_set<string> prefix;
        unordered_set<string> suffix;
        int len=a[i].length();
        string s;
        int maxJ=0;
        for (int j = 0; j <= len - 1; ++j)
        {
            s.push_back(a[i][j]);
            prefix.insert(s);
            suffix.insert(a[i].substr(j));
 
            if(lastSuffix.count(s))
                maxJ=j+1;
        }
        if(i>0)
            ans += a[i].substr(maxJ);
            
        lastSuffix=suffix;
       
    }
 
    cout << ans <<"\n";
    //cerr<< "";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1200E_CompressWords.in", "r", stdin);
        //freopen("CF_1200E_CompressWords.out", "w", stdout);
    #endif    
 
    solve();
 
 
    cout.flush();
    return 0;
}