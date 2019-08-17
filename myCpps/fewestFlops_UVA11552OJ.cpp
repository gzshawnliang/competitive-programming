#include <bits/stdc++.h>

using namespace std;


const int inf = INT_MAX / 3;

int ctoi(char ch)
{
    return ch - 'a';
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int ac = 26;
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int k; cin >> k;
        string s; cin >> s;

        int n = s.size(), lastMin = inf, nowMin = inf;
        vector<vector<int>> dp(n / k, vector<int>(ac, inf));
        for (int i = 0; i <= n - 1; i += k)
        {
            string now = s.substr(i, k), allChar = "";
            vector<int> count(ac + 1, 0);

            for (int j = 0; j <= k - 1; ++j)
            {
                if (count[ctoi(now[j])] == 0)
                {
                    allChar += now[j];
                }
                ++count[ctoi(now[j])];
            }

            int tc = allChar.size();
            if (i == 0)
            {
                for (int j = 0; j <= tc - 1; ++j)
                {
                    dp[i / k][ctoi(allChar[j])] = tc;
                }
                lastMin = tc;
            }
            else
            {
                for (int p = 0; p <= tc - 1; ++p)
                {
                    for (int q = 0; q <= tc - 1; ++q)
                    {
                        if (p == q && tc > 1) continue;

                        char head = allChar[p], tail = allChar[q];

                        if (dp[i / k][ctoi(tail)] == inf) dp[i / k][ctoi(tail)] = lastMin + tc;

                        dp[i / k][ctoi(tail)] = min(dp[i / k][ctoi(tail)], dp[i / k - 1][ctoi(head)] + tc - 1);

                        nowMin = min(nowMin, dp[i / k][ctoi(tail)]);
                    }
                }

                lastMin = nowMin;
                nowMin = inf;
            }
        }

        cout << lastMin << '\n';
    }

   	cout.flush();
   	return 0;
}

