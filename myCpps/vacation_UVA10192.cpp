#include <bits/stdc++.h>

using namespace std;

ifstream fin("vacation_UVA10192.in");
ofstream fout("vacation_UVA10192.out");

int main()
{
    int t = 0;
    while (true)
    {
        string a = "#";
        getline(fin, a);
        if (a == "#") break;

        ++t;

        string b; getline(fin, b);

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

        fout << "Case #" << t << ": you can visit at most " << dp[na][nb] << " cities.\n";
    }

    return 0;
}
