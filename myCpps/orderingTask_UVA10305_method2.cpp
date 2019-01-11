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

ifstream fin("orderingTask_UVA10305.in");
ofstream fout("orderingTask_UVA10305_method2.out");

vector<int> out;
int pos;
void dfs(int s, vector<vector<bool>> & a, vector<bool> & visit, int n)
{
    if (visit[s] == true)
    {
        return;
    }
    else
    {
        visit[s] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (a[s][i] == true)
            {
                dfs(i, a, visit, n);
            }
        }

        out[pos] = s;
        --pos;
    }
}

int main()
{
    while (true)
    {
        int n = 0, m = 0; out.clear();
        fin >> n >> m;
        if (n == 0) break;

        pos = n - 1;
        for (int i = 1; i <= n; ++i)
        {
            out.push_back(0);
        }

        vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));
        vector<bool> visit(n + 1, false);
        for (int c = 1; c <= m; ++c)
        {
            int i, j;
            fin >> i >> j;
            a[i][j] = true;
        }

        for (int s = 1; s <= n; ++s)
        {
            if (visit[s] == false)
            {
                dfs(s, a, visit, n);
            }
        }

        for (int i = 0; i <= n - 1; ++i)
        {
            if (i > 0) fout << ' ';
            fout << out[i]; 
        }
        fout << '\n';
    }

    return 0;
}