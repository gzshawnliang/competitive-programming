/*
===========================================================
* @Name:           533E Correcting Mistakes
* @Author:         Shawn
* @create Time:    2019/11/17 18:13:19
* @url:            https://codeforces.com/contest/533/problem/E
* @Description:    非哈希
                   两个长度相等的字符串S，T，S!=T，长度是N，W满足
                   1.长度是N+1，比S多一位
                   2.W删除一个字符x能变成S，W删除另外一个字符y能变成T,x!=y
                   求有多少个W
                   
                   S = A + x + B + C, 
                   T = A + B + y + C,
                   W = A + x + B + y + C, 

                   S =  x + B , 
                   T =  B + y ,
                   W =  x + B + y , 

                   S =  B  + x , 
                   T =  y + B ,
                   W =  y + B + x , 


Suppose that S is obtained from W by deleteing the earlier symbol than T. 
Then it is true that W = A + x + B + y + C, S = A + x + B + C, T = A + B + y + C, where x 
and y are deleted symbols and A, B и C are some (possibly, empty) strings.

Let's calculate A as a longest common prefix of S and T and C as a longest 
common suffix. Remove both of them from strings. Now we now that x and y 
are respectively the first letter of string S and last letter of string T. 
Remove them too. The only thing left is to check if remaining parts of strings 
are equal.

Perform such operation for S and T and for T and S.                   
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
    freopen("CF_533E_CorrectingMistakes.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}