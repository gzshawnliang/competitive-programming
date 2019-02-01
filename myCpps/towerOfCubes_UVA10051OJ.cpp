#include <bits/stdc++.h>

using namespace std;


struct cube
{
    int front;
    int back;
    int left;
    int right;
    int top;
    int bottom;
};

struct pos
{
    int p;
    int sp;

    bool operator == (const pos & temp) const
    {
        return p == temp.p && sp == temp.sp;
    };
};

int color(int side, cube & c)
{
    if (side == 1)
    {
        return c.front;
    }
    else if (side == 2)
    {
        return c.back;
    }
    else if (side == 3)
    {
        return c.left;
    }
    else if (side == 4)
    {
        return c.right;
    }
    else if (side == 5)
    {
        return c.top;
    }
    else if (side == 6)
    {
        return c.bottom;
    }
}

int opposite(int side, cube & c)
{
    if (side % 2 == 1)
    {
        return color(side + 1, c);
    }
    else
    {
        return color(side - 1, c);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int t = 0;
    while (true)
    {
        ++t;

        int n = 0; cin >> n;
        if (n == 0) break;

        if (t > 1) cout << '\n';

        vector<cube> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].front >> a[i].back >> a[i].left >> a[i].right >> a[i].top >> a[i].bottom;
        }

        int total = 0;
        pos ans{0, 1};

        vector<vector<int>> dp(n, vector<int>(7, 1));

        vector<vector<pos>> f(n, vector<pos>(7));
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int si = 1; si <= 6; ++si)
            {
                f[i][si].p = i; f[i][si].sp = si;
            }
        }

        for (int i = 0; i <= n - 1; ++i)
        {
            for (int si = 1; si <= 6; ++si)
            {
                if (i == 0)
                {
                    dp[i][si] = 1;
                }
                else
                {
                    for (int j = 0; j <= i - 1; ++j)
                    {
                        for (int sj = 1; sj <= 6; ++sj)
                        {
                            if (color(si, a[i]) == opposite(sj, a[j]))
                            {
                                if (dp[i][si] < dp[j][sj] + 1)
                                {
                                    dp[i][si] = dp[j][sj] + 1;
                                    f[i][si].p = j; f[i][si].sp = sj;
                                }

                                if (total < dp[i][si])
                                {
                                    total = dp[i][si];
                                    ans.p = i; ans.sp = si;
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << "Case #" << t << '\n' << total << '\n';

        vector<pos> out;
        vector<string> _side = {"shawnLOL", "front", "back", "left", "right", "top", "bottom"};

        while (!(f[ans.p][ans.sp] == ans))
        {
            out.push_back(ans);
            ans = f[ans.p][ans.sp];
        }
        out.push_back(ans);

        int size = out.size();
        for (int i = size - 1; i >= 0; --i)
        {
            cout << out[i].p + 1 << ' ' << _side[out[i].sp] << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

