#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int n = 9;

void change(char &x)
{
    if (x == '1') x = '2';
    else        x = '1';
}

void solve()
{
    int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
        vector<string> a(n);
        for (int i = 0; i <= n - 1; ++i) cin >> a[i];

        change(a[0][0]);
        change(a[1][3]);
        change(a[2][6]);
        change(a[3][1]);
        change(a[4][4]);
        change(a[5][7]);
        change(a[6][2]);
        change(a[7][5]);
        change(a[8][8]);

        for (int i = 0; i <= n - 1; ++i) cout << a[i] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Anti-Sudoku.in", "r", stdin);
        freopen("Anti-Sudoku.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}