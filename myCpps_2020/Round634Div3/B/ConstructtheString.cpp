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
        int n, a, b; cin >> n >> a >> b;

        string nowS;
        for (int c = 1, nowC = 'a'; c <= b; ++c, ++nowC) nowS += nowC;
        for (int c = 1; c <= a - b; ++c) nowS += 'a';
        for (int i = a; i <= n - 1; ++i)
        {
            nowS.push_back(nowS[i - a]);
        }

        cout << nowS << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("ConstructtheString.in", "r", stdin);
        freopen("ConstructtheString.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}