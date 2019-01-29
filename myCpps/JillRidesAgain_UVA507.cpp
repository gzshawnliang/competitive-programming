#include <bits/stdc++.h>

using namespace std;

ifstream fin("JillRidesAgain_UVA507.in");
ofstream fout("JillRidesAgain_UVA507.out");

struct solution
{
    int l;
    int r;
    int v;
};

int main()
{
    int testCase; fin >> testCase;
    for (int r = 1; r <= testCase; ++r)
    {
        int s; fin >> s;
        vector<int> a(s, 0);
        for (int i = 1; i <= s - 1; ++i)
        {
            fin >> a[i];
        }

        solution ans{1, 2, a[1]}, _null{0, 0, 0};

        vector<solution> dp(s, _null);
        dp[1] = ans;

        for (int i = 2; i <= s - 1; ++i)
        {
            dp[i].r = i + 1;

            if (dp[i - 1].v >= 0)
            {
                dp[i].v = dp[i - 1].v + a[i];

                dp[i].l = dp[i - 1].l;
            }
            else
            {
                dp[i].v = a[i];

                dp[i].l = i;
            }

            if (dp[i].v > ans.v)
            {
                ans = dp[i];
            }
            else if (dp[i].v == ans.v)
            {
                if (dp[i].r - dp[i].l > ans.r - ans.l)
                {
                    ans = dp[i];
                }
                else if (dp[i].r - dp[i].l == ans.r - ans.l)
                {
                    if (dp[i].l < ans.l)
                    {
                        ans = dp[i];
                    }
                }
            }
        }

        if (ans.v < 0)
        {
            fout << "Route " << r << " has no nice parts\n";
        }
        else
        {
            fout << "The nicest part of route " << r << " is between stops " << ans.l << " and " << ans.r << '\n';
        }
    }

    return 0;
}
