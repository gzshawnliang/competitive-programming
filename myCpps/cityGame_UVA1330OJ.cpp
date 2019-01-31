#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int n, m; cin >> n >> m;

        vector<vector<char>> a(n + 1, vector<char>(m + 1, 0));
        for (int y = 1; y <= n; ++y)
        {
            for (int x = 1; x <= m; ++x)
            {
                cin >> a[y][x];
            }
        }

        vector<vector<int>> maxH(n + 2, vector<int>(m + 2, 0)),
                            maxL(n + 2, vector<int>(m + 2, 0)),
                            maxR(n + 2, vector<int>(m + 2, 0));

        for (int x = 1; x <= m; ++x)
        {
            maxL[0][x] = INT_MAX;
            maxR[0][x] = INT_MAX;
        }

        for (int y = 1; y <= n; ++y)
        {
            int last = 0;

            for (int x = 1; x <= m; ++x)
            {
                if (a[y][x] == 'R')
                {
                    maxH[y][x] = 0;
                }
                else
                {
                    maxH[y][x] = maxH[y - 1][x] + 1;
                }
            }          

            last = 0;
            for (int x = 1; x <= m; ++x)
            {
                if (y == 1 && x == 1)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }

                if (a[y][x] == 'R')
                {
                    last = x;
                }
                else
                {
                    if (a[y - 1][x] == 'R')
                    {
                        maxL[y][x] = x - last - 1;
                    }
                    else
                    {
                        maxL[y][x] = min(maxL[y - 1][x], x - last - 1);
                    }
                }
            }

            last = m + 1;
            for (int x = m; x >= 1; --x)
            {
                if (a[y][x] == 'R')
                {
                    last = x;
                }
                else
                {
                    if (a[y - 1][x] == 'R')
                    {
                        maxR[y][x] = last - x - 1;
                    }
                    else
                    {
                        maxR[y][x] = min(maxR[y - 1][x], last - x - 1);
                    }
                }
            }
        }

        int ans = 0;
        for (int y = 1; y <= n; ++y)
        {
            for (int x = 1; x <= m; ++x)
            {
                int size = maxH[y][x] * (maxL[y][x] + maxR[y][x] + 1);
                ans = max(ans, size);
            }
        }

        cout << ans * 3 << '\n';
    }

   	cout.flush();
   	return 0;
}

