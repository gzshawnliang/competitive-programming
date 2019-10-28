#include <bits/stdc++.h>

using namespace std;

int dp[1000][1001];

int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i <= c - 1; ++i)
        {
            dp[i][b]++;
            dp[i][d]--;
        }
    }
    int ret = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (dp[i][j] == k)
                ret++;
            dp[i][j + 1] += dp[i][j];
        }
    }
    cout << ret << endl;
}