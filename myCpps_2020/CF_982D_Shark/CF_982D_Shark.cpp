/*
===========================================================
* @Name:           982D Shark
* @Author:         Shawn
* @create Time:    2020/1/27 20:37:10
* @url:            https://codeforces.com/contest/982/problem/D
* @Description:    
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int fnd(int x, vector<int> &f)
{
    if (f[x] == x) return x;
    else return f[x] = fnd(f[x], f);
}

void uni(int x, int y, int &cnt, vector<int> &f, vector<int> &len, vector<int> &sumLen)
{
    x = fnd(x, f); y = fnd(y, f);

    --sumLen[len[x]]; --sumLen[len[y]];
    len[x] += len[y];
    f[y] = x;

    ++sumLen[len[x]];
    --cnt;
}

void solve()
{
    int n; cin >> n;

    vector<int> org(n), f(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> org[i];
        a[i].first = org[i]; a[i].second = i;

        f[i] = i;
    }

    sort(a.begin(), a.end());

    int cnt = 0, maxCnt = 0, ans = 0;
    vector<int> len(n + 1, 0), sumLen(n + 1, 0);
    for (int i = 0; i <= n - 1; ++i)
    {
        int num = a[i].second;

        len[num] = 1;
        ++sumLen[1];
        ++cnt;

        if (num != n - 1)
            if (org[num + 1] < org[num]) uni(num, num + 1, cnt, f, len, sumLen);

        if (num != 0)
            if (org[num - 1] < org[num]) uni(num - 1, num, cnt, f, len, sumLen);

        if (cnt == sumLen[len[fnd(num, f)]])
        {
            if (cnt > maxCnt)
            {
                maxCnt = cnt;
                ans = a[i].first + 1;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_982D_Shark.in", "r", stdin);
        freopen("CF_982D_Shark.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}