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

ifstream fin("vertex_UVA280.in");
ofstream fout("vertex_UVA280.out");

int main()
{
    while (true)
    {
        int n = 0; fin >> n;
        vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));

        if (n == 0) break;

        while (true)
        {
            int i = 0; fin >> i;
            if (i == 0) break;

            while (true)
            {
                int j = 0; fin >> j;
                if (j == 0) break;

                a[i][j] = true;
            }
        }

        int m; fin >> m;
        for (int c = 1; c <= m; ++c)
        {
            int start; fin >> start;
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

            fout << total;
            for (int i = 0; i <= total - 1; ++i)
            {
                fout << ' ' << out[i];
            }
            fout << '\n';
        }
    }

    return 0;
}