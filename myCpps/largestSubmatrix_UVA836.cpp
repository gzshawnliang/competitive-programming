#include <bits/stdc++.h>

using namespace std;

ifstream fin("largestSubmatrix_UVA836.in");
ofstream fout("largestSubmatrix_UVA836.out");

void skip()
{
    string s; getline(fin, s);
}

int main()
{
    int testCase; fin >> testCase;
    skip();
    
    for (int t = 1; t <= testCase; ++t)
    {
        if (t > 1) fout << '\n';

        skip();

        string in; getline(fin, in);

        int n = in.size();
        vector<vector<long long>> a(n + 1, vector<long long>(n + 1, 0)), dp(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n - 1; ++i)
        {
            a[1][i + 1] = in[i] - '0';
            if (a[1][i + 1] == 0) a[1][i + 1] = INT_MIN;

            dp[1][i + 1] = dp[1][i] + a[1][i + 1];
        }

        for (int y = 2; y <= n; ++y)
        {
            getline(fin, in);
            for (int i = 0; i <= n - 1; ++i)
            {
                a[y][i + 1] = in[i] - '0';;
                if (a[y][i + 1] == 0) a[y][i + 1] = INT_MIN;

                dp[y][i + 1] = dp[y][i] + a[y][i + 1];
            }
        }

        long long ans = 0;
        for (int x1 = 1; x1 <= n; ++x1)
        {
            for (int x2 = x1; x2 <= n; ++x2)
            {
                for (int y1 = 1; y1 <= n; ++y1)
                {
                    long long sum = 0;
                    for (int y2 = y1; y2 <= n; ++y2)
                    {
                        sum += dp[y2][x2] - dp[y2][x1 - 1];
                        ans = max(ans, sum);
                    }
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}
