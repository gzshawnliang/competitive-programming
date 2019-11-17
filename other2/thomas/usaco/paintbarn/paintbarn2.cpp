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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2 - 1; ++i)
        {
            ++dp[i][y1];
            --dp[i][y2];
        }
    }
    int ans = 0;
    for (int i = 0; i < 1000; ++i)
    {
        for (int j = 0; j < 1000; ++j)
        {
            if (dp[i][j] == k)
                ++ans;
            
            dp[i][j+1] +=dp[i][j];
        }
    }
    cout << ans << endl;
}