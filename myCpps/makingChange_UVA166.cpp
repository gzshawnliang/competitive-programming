#include <bits/stdc++.h>

using namespace std;

ifstream fin("makingChange_UVA166.in");
ofstream fout("makingChange_UVA166.out");

const int inf = INT_MAX / 2, N = 1000, ctc = 6;

int main()
{
    vector<int> coins = {inf, 5, 10, 20, 50, 100, 200};
    vector<vector<int>> dp_infc(ctc + 1, vector<int>(N + 1, inf)); dp_infc[0][0] = 0;
    for (int i = 1; i <= ctc; ++i)
    {
        for (int j = N; j >= 0; --j)
        {
            for (int c = 0; coins[i] * c <= j; ++c)
            {
                dp_infc[i][j] = min(dp_infc[i - 1][j], dp_infc[i - 1][j - coins[i] * c] + c);
            }
        }
    }
    
    while (true)
    {
        vector<int> cc(ctc + 1, inf);
        for (int i = 1; i <= ctc; ++i)
        {
            fin >> cc[i];
        }
        
        bool canBreak = true;
        for (int i = 1; i <= ctc; ++i)
        {
            if (cc[i] > 0)
            {
                canBreak = false;
                break;
            }
        }
        if (canBreak == true) break;

        double pay_d; fin >> pay_d;
        int pay = (int)(pay_d * 100.0 + 0.5);

        vector<vector<int>> dp(ctc + 1, vector<int>(N + 1, inf)); dp[0][0] = 0;
        for (int i = 1; i <= ctc; ++i)
        {
            for (int j = N; j >= 0; --j)
            {
                for (int c = 0; coins[i] * c <= j && c <= cc[i]; ++c)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - coins[i] * c] + c);
                }
            }
        }

        int ans = inf;
        for (int p = pay; p <= N; ++p)
        {
            if (ans > dp[ctc][p] + dp_infc[ctc][p - pay])
            {
                ans = dp[ctc][p] + dp_infc[ctc][p - pay];
            }
        }

        fout << setw(3) << ans << '\n';
    }

    return 0;
}
