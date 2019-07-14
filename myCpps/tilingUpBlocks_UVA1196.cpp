#include <bits/stdc++.h>

using namespace std;

ifstream fin("tilingUpBlocks_UVA1196.in");
ofstream fout("tilingUpBlocks_UVA1196.out");

struct block
{
    int l;
    int m;

    bool operator < (const block & temp) const
    {
        if (l != temp.l) return l < temp.l;
        else return m < temp.m;
        //return l < temp.l || m < temp.m;
    }
};

int main()
{
    
    while (true)
    {
        int n = 0; fin >> n;
        if (n == 0)
        {
            fout << "*\n";
            break;
        }

        vector<block> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i].l >> a[i].m;
        }

        sort(a.begin(), a.end());

        int ans = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int j = 0; j <= i - 1; ++j)
            {
                if (a[j].m <= a[i].m)
                {   
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}
