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
#include <stack>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0; cin >> n;
        vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));

        if (n == 0) break;

        while (true)
        {
            int i = 0; cin >> i;
            if (i == 0) break;

            while (true)
            {
                int j = 0; cin >> j;
                if (j == 0) break;

                a[i][j] = true;
            }
        }

        int m; cin >> m;
        for (int c = 1; c <= m; ++c)
        {
            int start; cin >> start;
            stack<int> s;
            s.push(start);
            vector<bool> visit(n + 1, false);
            
            while (!s.empty())
            {
                int top = s.top();
                bool _find = false;

                for (int i = 1; i <= n; ++i)
                {
                    if (a[top][i] == true && visit[i] == false)
                    {
                        visit[i] = true;
                        _find = true;
                        s.push(i);
                    }
                }

                if (_find == false)
                {
                    s.pop();
                }
            }

            int total = 0;
            vector<int> out;

            for (int i = 1; i <= n; ++i)
            {
                if (visit[i] == false)
                {
                    ++total;
                    out.push_back(i);
                }
            }

            cout << total;
            for (int i = 0; i <= total - 1; ++i)
            {
                cout << ' ' << out[i];
            }
            cout << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
