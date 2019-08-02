#include <bits/stdc++.h>

using namespace std;


const int inf = INT_MAX / 2;

bool smaller(vector<int> & a, vector<int> & b)
{
    bool ans = false;
    int size = a.size();
    for (int i = 0; i <= size - 1; ++i)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
            break;
        }
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0, m = 0; cin >> n >> m;
        if (n + m == 0) break;

        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                cin >> a[y][x];
            }
        }

        vector<vector<int>> dp(n, vector<int>(m, inf));
        vector<vector<vector<int>>> path(n, vector<vector<int>>(m));

        for (int y = 0; y <= n - 1; ++y)
        {
            dp[y][0] = a[y][0];
            path[y][0].push_back(y); 
        }
        for (int x = 1; x <= m - 1; ++x)
        {
            for (int y = 0; y <= n - 1; ++y)
            {
                int up;
                if (y == 0) up = n - 1;
                else up = y - 1;
                int down;
                if (y == n - 1) down = 0;
                else down = y + 1;

                int _min = min(dp[up][x - 1], min(dp[y][x - 1], dp[down][x - 1]));
                vector<int> res(path[up][x - 1].size(), inf);

                if (dp[up][x - 1] == _min)
                    if (smaller(path[up][x - 1], res) == true)
                        res = path[up][x - 1];
                
                if (dp[y][x - 1] == _min)
                    if (smaller(path[y][x - 1], res) == true)
                        res = path[y][x - 1];

                if (dp[down][x - 1] == _min)
                    if (smaller(path[down][x - 1], res) == true)
                        res = path[down][x - 1];

                dp[y][x] = _min + a[y][x];
                path[y][x] = res; path[y][x].push_back(y);
            }
        }

        int ansD = inf;
        vector<int> ansP(m, inf);
        for (int y = 0; y <= n - 1; ++y)
        {
            if (ansD >= dp[y][m - 1])
            {
                if (ansD == dp[y][m - 1])
                {
                    if (smaller(ansP, path[y][m - 1]) == false)
                    {
                        ansP = path[y][m - 1];
                    }
                }
                else if (ansD > dp[y][m - 1])
                {
                    ansP = path[y][m - 1];
                }

                ansD = dp[y][m - 1];
            }
        }

        for (int i = 0; i <= m - 1; ++i)
        {
            if (i > 0) cout << ' ';
            cout << ansP[i] + 1;
        }
        cout << '\n' << ansD << '\n';
    }

   	cout.flush();
   	return 0;
}

