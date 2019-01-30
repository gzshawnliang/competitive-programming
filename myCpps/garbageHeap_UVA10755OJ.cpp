#include <bits/stdc++.h>

using namespace std;


const int N = 21;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        if (t > 1) cout << '\n';

        int A, B, C; cin >> A >> B >> C;

        vector<vector<vector<long long>>> g(A + 1, vector<vector<long long>>(B + 1, vector<long long>(C + 1, 0)));
        vector<vector<vector<vector<long long>>>> s(B + 1, vector<vector<vector<long long>>>(B + 1, vector<vector<long long>>(C + 1, vector<long long>(C + 1, 0)))),
                                                  dp(B + 1, vector<vector<vector<long long>>>(B + 1, vector<vector<long long>>(C + 1, vector<long long>(C + 1, 0))));

        for (int a = 1; a <= A; ++a)
        {
            for (int b = 1; b <= B; ++b)
            {
                for (int c = 1; c <= C; ++c)
                {
                    cin >> g[a][b][c];
                }
            }
        }

        long long ans = INT_MIN;
        for (int a = 1; a <= A; ++a)
        {
            for (int i = 1; i <= B; ++i)
            {
                for (int j = i; j <= B; ++j)
                {
                    for (int n = 1; n <= C; ++n)
                    {
                        long long res = 0;
                        for (int m = n; m <= C; ++m)
                        {
                            res += g[a][j][m];
                            s[i][j][n][m] = s[i][j - 1][n][m] + res;
                            if (a == 1)
                            {
                                dp[i][j][n][m] = s[i][j][n][m];
                            }
                            else
                            {
                                dp[i][j][n][m] = max(s[i][j][n][m], s[i][j][n][m] + dp[i][j][n][m]);
                            }

                            ans = max(ans, dp[i][j][n][m]);
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

