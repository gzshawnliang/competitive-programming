#include <bits/stdc++.h>

using namespace std;


int _abs(int x)
{
    if (x > 0) return x;
    else return -x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0, k = 0; cin >> n >> k;
        if (n + k == 0) break;

        vector<int> t(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            cin >> t[i];
        }

        string in; getline(cin, in);
        vector<vector<bool>> g(n + 1, vector<bool>(100, false));
        vector<vector<int>> a(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            getline(cin, in);

            int size = in.size();
            string temp = "";

            for (int j = 0; j <= size; ++j)
            {
                if (in[j] == ' ' || j == size)
                {
                    if (temp == "") continue;

                    int num = stoi(temp);
                    a[i].push_back(num);
                    g[i][num] = true;

                    temp = "";
                }
                else
                {
                    temp += in[j];
                }
            }
        }

        vector<int> dp(100, INT_MAX / 2);
        
        for (int i = 1; i <= n; ++i)
        {
            if (g[i][0] == false) continue;

            int sizeI = a[i].size();
            for (int q = 0; q <= sizeI - 1; ++q)
            {
                int f = a[i][q];

                dp[f] = min(dp[f], f * t[i]);
            }
        }

        for (int c = 1; c <= n; ++c)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    int sizeI = a[i].size();
                    for (int p = 0; p <= sizeI - 1; ++p)
                    {
                        int fl = a[i][p];
                        if (g[j][fl] == false) continue;

                        for (int q = 0; q <= sizeI - 1; ++q)
                        {
                            int f = a[i][q];

                            if (fl == 25 && f == 30)
                            {
                                for (int __s = 0; __s == 0; ++__s);
                            }

                            dp[f] = min(dp[f], dp[fl] + _abs(f - fl) * t[i] + 60);
                        }
                    }
                }
            }
        }

        if (dp[k] == INT_MAX / 2)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            cout << dp[k] << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

