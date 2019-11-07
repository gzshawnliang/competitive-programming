/*
-------------------------------------------------------------
 * @名称:    Replacing Digits
 * @作者:    Thomas 
 * @创建时间: 2019-11-07 12:02:26 
 * @修改人:   Thomas 
 * @修改时间: 2019-11-07 12:02:26 
 * @备注:    双指针，贪心
 * @题目来源： https://codeforces.com/problemset/problem/169/B
-------------------------------------------------------------
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_169B_ReplacingDigits.in", "r", stdin);
        freopen("CF_169B_ReplacingDigits.out", "w", stdout);
    #endif

    string a;
    cin >> a;
    string s;
    cin >> s;

    sort(s.begin(), s.end(), greater<int>());

    int aLen = a.length();
    int sLen = s.length();

    int i = 0;
    int j = 0;

    while (i <= aLen - 1 && j <= sLen - 1)
    {
        if (a[i] >= s[j])
        {
            ++i;
        }
        else
        {
            a[i] = s[j];
            ++i;
            ++j;
        }
    }

    cout << a << "\n";

    return 0;
}
