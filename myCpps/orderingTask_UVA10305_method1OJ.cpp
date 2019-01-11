#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        if (n == 0) break;

        vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));
        vector<int> counts(n + 1, 0); 
        for (int c = 1; c <= m; ++c)
        {
            int i, j;
            cin >> i >> j;
            a[i][j] = true;
            ++counts[j];
        }

        for (int c0 = 1; c0 <= n; ++c0)
        {
            int s = 1;
            while (s <= n && counts[s] != 0)
            {
                ++s;
            }

            if (s == n + 1) break;

            if (c0 > 1) cout << ' ';
            cout << s;

            counts[s] = -1;
            for (int c1 = 1; c1 <= n; ++c1)
            {
                if (a[s][c1] == true)
                {
                    --counts[c1];
                }
            }
        }

        cout << '\n';
    }

   	cout.flush();
   	return 0;
}
