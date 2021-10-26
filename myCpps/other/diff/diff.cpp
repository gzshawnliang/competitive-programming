/*
===========================================================
 * @名称:    简单差分
 * @作者:    Thomas 
 * @创建时间: 2020-01-11 11:01:23 
 * @修改人:   Thomas 
 * @修改时间: 2020-01-11 11:01:23 
 * @备注:    https://www.zybuluo.com/Junlier/note/1232395
 * @题目来源： 
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n,0);
    vector<int> diff(n+1,0);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i <= q - 1; ++i)
    {
        int l,r,v;
        cin >> l >> r >>v;
        diff[l] +=v;
        diff[r+1] -=v;
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        diff[i] += diff[i-1];
    }
    for (int i = 0; i <= n - 1; ++i)
    {
        a[i] +=diff[i];
        cout << a[i] << " ";
    }
}

void solve2()
{
    int n;
    cin >> n;
    vector<int> a(n,0);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i <= q - 1; ++i)
    {
        int l,r,v;
        cin >> l >> r >>v;
        for (int j = l; j <= r; ++j)
        {
            a[j] +=v;
        }
    }
    for (int i = 0; i <= n - 1; ++i)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
         freopen("diff.in", "r", stdin);
    //     //freopen("diff.out", "w", stdout);
    // #endif    

    //solve();        //7 18 24 23 31 20 22 9 3 3 11 6 2 
    //solve2();       //7 18 24 23 31 20 22 9 3 3 11 6 2   


    cout.flush();
    return 0;
}