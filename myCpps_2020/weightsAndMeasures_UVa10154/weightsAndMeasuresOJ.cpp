#include <bits/stdc++.h>

using namespace std;


const int maxMS = 1500, inf = INT_MAX / 10;

struct turtle
{
    int m;
    int s;

    bool operator < (const turtle & temp) const
    {
        return s < temp.s;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<turtle> a;
    while (true)
    {
        turtle temp{0, 0};
        cin >> temp.m >> temp.s;

        if (temp.m == 0)
        {
            break;
        }
        else
        {
            a.push_back(temp);
        }
    }

    turtle temp{0, 0};
    a.push_back(temp);

    sort(a.begin(), a.end());

    int n = a.size() - 1, ans = 0;
    vector<int> dp(n + 1, inf); dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            if (dp[j] > dp[j - 1] + a[i].m && a[i].s >= dp[j - 1] + a[i].m)
            {
                dp[j] = dp[j - 1] + a[i].m;

                ans = max(ans, j);
            }
        }
    }

    cout << ans << '\n';

   	cout.flush();
   	return 0;
}

