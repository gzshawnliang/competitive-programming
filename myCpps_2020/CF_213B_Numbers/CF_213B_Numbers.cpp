/*
===========================================================
* @Name:           213B Numbers
* @Author:         Shawn
* @create Time:    2020/1/21 20:53:25
* @url:            https://codeforces.com/contest/213/problem/B
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

void solve()
{
    int n; cin >> n;

    int sum = 0;
    vector<int> a(10, 0);
    for (int i = 0; i <= 9; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_213B_Numbers.in", "r", stdin);
        //freopen("CF_213B_Numbers.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}