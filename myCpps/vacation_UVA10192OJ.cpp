#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int t = 0;
    while (true)
    {
        string a = "#";
        getline(cin, a);
        if (a == "#") break;

        ++t;

        string b; getline(cin, b);

        a = ' ' + a;
        b = ' ' + b;

        int na = a.size() - 1, nb = b.size() - 1;
        vector<vector<int>> dp(na + 1, vector<int>(nb + 1, 0));
        for (int i = 1; i <= na; ++i)
        {
            for (int j = 1; j <= nb; ++j)
            {
                if (a[i] == b[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << "Case #" << t << ": you can visit at most " << dp[na][nb] << " cities.\n";
    }

   	cout.flush();
   	return 0;
}

