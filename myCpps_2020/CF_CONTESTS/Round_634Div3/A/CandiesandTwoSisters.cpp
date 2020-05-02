#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
        int n; cin >> n;
        if (n % 2 == 0) --n;

        cout << max(n / 2, 0) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CandiesandTwoSisters.in", "r", stdin);
        freopen("CandiesandTwoSisters.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}