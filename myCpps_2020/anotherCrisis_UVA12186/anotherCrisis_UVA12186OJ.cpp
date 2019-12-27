#include <bits/stdc++.h>

using namespace std;


const int inf = INT_MAX / 2;

void dfs(int u, int t, vector<int> &f, vector<vector<int>> &g)
{
    int size = g[u].size();
    if (size == 0)
    {
        f[u] = 1;
        return;
    }

    vector<int> all;
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = g[u][i];

        dfs(v, t, f, g);
        all.push_back(f[v]);
    }

    sort(all.begin(), all.end());
    int sizeNeed = ceil((double)size * (double)t / 100.0), ans = 0;
    for (int i = 0; i <= sizeNeed - 1; ++i)
    {
        ans += all[i];
    }

    f[u] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0, t = 0; cin >> n >> t;
        if (n + t == 0) break;

        ++n;

        vector<vector<int>> g(n);
        for (int i = 1; i <= n - 1; ++i)
        {
            int temp; cin >> temp;
            g[temp].push_back(i);
        }

        vector<int> f(n, inf);
        dfs(0, t, f, g);

        cout << f[0] << '\n';
    }

   	cout.flush();
   	return 0;
}

