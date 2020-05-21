/*
===========================================================
* @Name:           1010211 Guess the Number
* @Author:         Thomas
* @create Time:    2020/5/16 11:54:33
* @url:            https://codeforces.com/gym/101021/problem/1
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    int l = 1, r = 1000000;
    while (l != r)
    {
        int mid = (l + r + 1) / 2;
        cout << mid << "\n";
        cout.flush();

        string response;
        cin >> response;
        if (response == "<")
            r = mid - 1;
        else
            l = mid;
    }
    cout << "! " << l << "\n";
    cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1010211_GuesstheNumber.in", "r", stdin);
    //freopen("CF_1010211_GuesstheNumber.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}
