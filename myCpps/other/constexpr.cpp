#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int fac(int n) //递归
{
    return n == 1 ? 1 : n * fac(n - 1);
}


void solve()
{
    constexpr int r=fac(5);
    cout << r << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("constexpr.in", "r", stdin);
        //freopen("constexpr.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}