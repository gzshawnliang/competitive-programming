#include <bits/stdc++.h>

using namespace std;


struct block
{
    int l;
    int m;

    bool operator < (const block & temp) const
    {
        if (l != temp.l) return l < temp.l;
        else return m < temp.m;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    
    while (true)
    {
        int n = 0; cin >> n;
        if (n == 0)
        {
            cout << "*\n";
            break;
        }

        vector<block> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].l >> a[i].m;
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

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

