#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0, m = 0;
        cin >> n; if (n == 0) break;
        cin >> m;
        vector<vector<bool>> a(n, vector<bool>(n, false));
        vector<int> color(n, -1);
        for (int c = 1; c <= m; ++c)
        {
            int i, j;
            cin >> i >> j;
            a[i][j] = true;
            a[j][i] = true;
        }

        bool isBicolorable = true;
        queue<int> q;
        q.push(0);
        color[0] = 0;
        while (isBicolorable == true && !(q.empty()))
        {
            int s = q.front();
            q.pop();
            for (int i = 0; i <= n - 1; ++i)
            {
                if (a[s][i] == true)
                {
                    if (color[i] == -1)
                    {
                        q.push(i);
                        if (color[s] == 0)
                        {
                            color[i] = 1;
                        }
                        else
                        {
                            color[i] = 0;
                        }
                    }
                    else if (color[s] == color[i])
                    {
                        isBicolorable = false;
                        break;
                    }
                }
            }
        }

        if (isBicolorable == true)
        {
            cout << "BICOLORABLE.\n";
        }
        else
        {
            cout << "NOT BICOLORABLE.\n";
        }
    }

   	cout.flush();
   	return 0;
}
