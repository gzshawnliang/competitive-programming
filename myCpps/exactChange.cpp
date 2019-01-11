#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("exactChange.in");
ofstream fout("exactChange.out");

int main()
{
    int testCase;
    fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int total;
        fin >> total;
        int n;
        fin >> n;

        if (total == 0 && n == 0)
        {
            fout << "0 0\n";
        }

        vector<int> a(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        vector<int> dp(total + 10001, 10001);

        dp[0] = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = total + 10000; j >= a[i]; --j)
            {
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }

        int ans = total;
        while (ans <= total + 10000 && dp[ans] == 10001)
        {
            ++ans;
        }

        fout << ans << ' ' << dp[ans] << '\n';
    }

    return 0;
}