/*
===========================================================
* @Name:           533E Correcting Mistakes
* @Author:         Shawn
* @create Time:    2019/11/17 18:13:19
* @url:            https://codeforces.com/contest/533/problem/E
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N;
    string S;
    string T;

    cin >> N;
    cin >> S;
    cin >> T;

    int lcp = 0;
    while (S[lcp] == T[lcp])
        ++lcp;

    int lcs = N - 1;
    while (S[lcs] == T[lcs])
        --lcs;

    //去掉首尾公共前后缀
    string s = S.substr(lcp, lcs - lcp + 1);
    string t = T.substr(lcp, lcs - lcp + 1);

    int ans = 0;

    //s的[1,R]等于t的[0,R-1]
    string s1 = s.substr(1);
    string t1 = t.substr(0, t.size() - 1);
    if (s1 == t1)
        ++ans;

    //s的[0,R-1]等于t的[1,R]
    string s2 = s.substr(0, s.size() - 1);
    string t2 = t.substr(1);
    if (s2 == t2)
        ++ans;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("CF_533E_CorrectingMistakes.in", "r", stdin);
    //freopen("CF_533E_CorrectingMistakes.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}