/*
===========================================================
 * @名称:		离散化
 * @作者:		Shawn 
 * @创建时间: 2020-03-28 21:53:40 
 * @修改人:   Shawn 
 * @修改时间: 2020-03-28 21:53:40 
 * @备注:		https://oi-wiki.org/misc/discrete/
 * @题目来源： 
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{

    vector<int> a={1000,2000,3000,1800,2000,4600};
    vector<int> b=a;        //b 是 a 的一个副本
    int n=a.size();
    
    std::sort(a.begin(), a.end());

    a.erase(std::unique(a.begin(), a.end()), a.end());
    
    for (int i = 0; i <= n-1; ++i)
        b[i] = lower_bound(a.begin(), a.end(), b[i]) - a.begin();

    for (int i = 0; i <= n - 1; ++i)
        cout << b[i] << " ";
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        //freopen("discrete.in", "r", stdin);
        //freopen("discrete.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}