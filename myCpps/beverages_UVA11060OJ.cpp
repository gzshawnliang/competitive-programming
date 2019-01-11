#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int C = 0;
    while (true)
    {
        ++C;

        int n = 0;
        cin >> n;
        if (n == 0) break;

        cout << "Case #" << C << ": Dilbert should drink beverages in this order:";

        map<string, int> _map;
        map<string, bool> check;
        vector<string> names(n);
        vector<vector<bool>> a(n, vector<bool>(n, false));
        vector<int> _count(n, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> names[i];
            _map[names[i]] = i;
        }

        int m; cin >> m;
        for (int c = 1; c <= m; ++c)
        {
            string u, v; cin >> u >> v;
            string _key = u + " " + v;

            if (check[_key] == false)
            {
                check[_key] = true;
                
                a[_map[u]][_map[v]] = true;
                ++_count[_map[v]];
            }
        }

        for (int c = 1; c <= n; ++c)
        {
            int s = 0;
            while (s <= n - 1 && _count[s] != 0)
            {
                ++s;
            }

            if (s == n) break;

            cout << ' ' << names[s];

            _count[s] = -1;
            for (int j = 0; j <= n - 1; ++j)
            {
                if (a[s][j] == true)
                {
                    --_count[j];
                    a[s][j] = false;
                }
            }
        }

        cout << ".\n\n";
    }

   	cout.flush();
   	return 0;
}
