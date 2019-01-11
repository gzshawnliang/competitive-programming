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


int _count(int s, int n, vector<vector<bool>> & a)
{
    int res = 0;
    vector<bool> visit(n + 1, false); visit[s] = true;
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

        int ans = 0;
        for (int s = 1; s <= n; ++s)
        {
            if (_count(s, n, a) >= 2)
            {
                ++ans;
            }
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
