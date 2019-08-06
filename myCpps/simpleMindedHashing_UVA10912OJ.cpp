#include <bits/stdc++.h>

using namespace std;


const int maxL = 26, maxS = 351, n = 26;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<vector<vector<int>>> dp(maxL + 1, vector<vector<int>>(maxS + 1, vector<int>(n + 1, 0))); dp[0][0][0] = 1;
    for (int k = 0; k <= 26; ++k)
    {
        dp[0][0][k] = 1;
    }

    for (int i = 1; i <= maxL; ++i)
    {
        for (int j = (i + 1) * i / 2; j <= maxS; ++j)
        {
            for (int k = 1; k <= j && k <= 26; ++k)
            {
                if (i == 1 && j == 1 && k == 1)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }

                for (int p = k; p <= 26; ++p)
                {
                    dp[i][j][p] += dp[i - 1][j - k][k - 1];
                }
            }
        }
    }

    int t = 0;
    while (true)
    {
        int l = 0, s = 0; cin >> l >> s;
        if (l + s == 0) break;
        ++t;

        if (l > 26 || s > 351)
        {
            cout << "Case " << t << ": 0\n";
        }
        else
        {
            cout << "Case " << t << ": " << dp[l][s][n] << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

