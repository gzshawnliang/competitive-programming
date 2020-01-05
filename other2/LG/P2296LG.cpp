#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m, s, t; cin >> n >> m;
 
    vector<vector<int>> g0(n + 1), g1(n + 1);

    for (int c = 1; c <= m; ++c)
    {
        int u, v; cin >> u >> v;
        g0[u].push_back(v);
        g1[v].push_back(u);
    }

    cin >> s >> t;

    vector<bool> get(n + 1, false);
    queue<int> q0;
    q0.push(t);

    while (!q0.empty())
    {
        int u = q0.front();
        q0.pop();

        get[u] = true;

        int size = g1[u].size();
        for (int i = 0; i <= size - 1; ++i)
        {
            int v = g1[u][i];
            if (get[v] == false)
            {
                get[v] = true;
                q0.push(v);
            }
        }
    }

    vector<int> path(n + 1, -1);
    queue<int> q1;
    q1.push(s);
    path[s] = 0;

    while (!q1.empty())
    {
        int u = q1.front();
        q1.pop();

        if (u == t)
        {
            cout << path[u] << '\n';

           	cout.flush();
           	return 0;
        }

        bool flag = false;
        int size0 = g0[u].size();
        for (int i = 0; i <= size0 - 1 && flag == false; ++i)
        {
            int v = g0[u][i];
            if (get[v] == false)
            {
                flag = true;
            }
        }

        if (flag == true)
        {
            continue;
        }

        int size1 = g0[u].size();
        for (int i = 0; i <= size1 - 1; ++i)
        {
            int v = g0[u][i];
            if (path[v] == -1)
            {
                path[v] = path[u] + 1;
                q1.push(v);
            }
        }
    }

    cout << "-1\n";

   	cout.flush();
   	return 0;
}
