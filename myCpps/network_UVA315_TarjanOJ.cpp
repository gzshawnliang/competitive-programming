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
#include <queue>

using namespace std;


void tarjan(int s, int & _count, int n, vector<vector<bool>> & a, vector<int> & dfn, vector<int> & low, vector<int> & parent)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[s][i] == true)
        {
            if (dfn[i] == -1)
            {
                ++_count;
                dfn[i] = _count;
                low[i] = _count;
                parent[i] = s;
                tarjan(i, _count, n, a, dfn, low, parent);

                if (low[i] < low[s])
                {
                    low[s] = low[i];
                }
            }
            else if (parent[s] != i && dfn[i] < low[s])
            {
                low[s] = dfn[i];
            }
        }
    }
}

int COUNT(int s, int n, vector<vector<bool>> & a)
{
    int res = 0;
    vector<bool> visit(n + 1, false);
    visit[s] = true;
    for (int c = 1; c <= n; ++c)
    {
        if (a[s][c] == true && visit[c] == false)
        {
            queue<int> q;
            q.push(c);
            visit[c] = true;
            while (!(q.empty()))
            {
                int k = q.front();
                q.pop();
                for (int i = 1; i <= n; ++i)
                {
                    if (a[k][i] == true && visit[i] == false)
                    {
                        q.push(i);
                        visit[i] = true;
                    }
                }
            }

            ++res;
        }
    }

    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n;
        cin >> n; if (n == 0) break;
        vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));

        string useless;
        getline(cin, useless);

        while (true)
        {
            string in = "0";
            getline(cin, in); if (in == "0") break;

            int size0 = in.size(), first = 0;
            string temp = " ";
            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (in[i] == ' ')
                {
                    if (first == 0)
                    {
                        first = stoi(temp);
                    }
                    else
                    {
                        int j = stoi(temp);
                        a[first][j] = true;
                        a[j][first] = true;
                    }

                    temp = "";
                }
                else
                {
                    temp += in[i];
                }
            }
            int j = stoi(temp);
            a[first][j] = true;
            a[j][first] = true;
        }

        vector<int> dfn(n + 1, -1), low(n + 1, -1), parent(n + 1, -1);
        dfn[1] = 1; low[1] = 1; parent[1] = -1;
        int _count = 1;
        tarjan(1, _count, n, a, dfn, low, parent);

        int ans = 0;
        for (int u = 2; u <= n; ++u)
        {
            for (int v = 1; v <= n; ++v)
            {
                if (parent[v] == u)
                {
                    if (low[v] >= dfn[u])
                    {
                        ++ans;
                        break;
                    }
                }
            }
        }

        if (COUNT(1, n, a) >= 2)
        {
            ++ans;
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
