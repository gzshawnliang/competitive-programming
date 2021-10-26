#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    cout << (35 / 5) % 3 << "\n";

    cout << (5 * 2) % 3 << "\n";

    cout << (35 * 2) % 3 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        //freopen("1.in", "r", stdin);
        //freopen("1.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}