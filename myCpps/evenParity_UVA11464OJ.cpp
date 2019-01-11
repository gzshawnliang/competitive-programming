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



const int INF = 300;

int ans;
vector<int> dy = {-1, 0, 1, 0}, dx = {0, -1, 0, 1};

bool g(int y, int x, int n)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
}

int add(int y, int x, vector<vector<int>> & a)
{
    if (a[0][0] == 1 && a[0][1] == 0 && a[0][2] == 1 && y == 0 && x == 1)
    {
        cout << "";
    }

    int n = a.size(), res = 0;
    for (int d = 0; d <= 3; ++d)
    {
        int _y = y + dy[d], _x = x + dx[d];
        if (g(_y, _x, n))
        {
            res += a[_y][_x];
        }
    }

    return res;
}

void out(vector<vector<int>> & a)
{
    int n = a.size();

    for (int y0 = 0; y0 <= n - 1; ++y0)
    {
        for (int x0 = 0; x0 <= n - 1; ++x0)
        {
            if (x0 > 0)
                cout << ' ';
            cout << a[y0][x0];
        }
        cout << '\n';
    }
    cout << '\n';
}

void f(int _count, int y, int x, vector<vector<int>> & a)
{
    int n = a.size();

    if (x >= n)
    {
        x = 0;
        ++y;

        if (y >= n)
        {
            ans = min(ans, _count);


            return;
        }
    }

    if (a[y][x] == 1)
    {
        if (add(y - 1, x, a) % 2 == 0)
        {
            f(_count, y, x + 1, a);
        }
    }
    else
    {
        for (int i = 0; i <= 1; ++i)
        {
            a[y][x] = i;
            if (add(y - 1, x, a) % 2 != 0)
            {
                a[y][x] = 0;
                continue;
            }
            a[y][x] = 0;
        
            a[y][x] = i;
            f(_count + i, y, x + 1, a);
            a[y][x] = 0;
        }
    }
}

void solve(int change, int _count, string & s, vector<vector<int>> & a)
{
    if (_count == 0)
    {
        int j = 0, n = a.size();
        vector<int> temp1 = a[0], temp2 = a[0];

        for (int i = 0; i <= n - 1; ++i)
        {
            if (temp1[i] == 0)
            {
                if (s[j] == '1')
                {
                    temp1[i] = 1;
                }

                ++j;
            }
        }

        a[0] = temp1;

        f(change, 1, 0, a);

        a[0] = temp2;
    }
    else
    {
        string temp1 = s;

        s.push_back('0');
        solve(change, _count - 1, s, a);

        s = temp1;
        s.push_back('1');
        solve(change + 1, _count - 1, s, a);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        ans = INF;

        int n, _count = 0;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                cin >> a[y][x];

                if (y == 0)
                    _count += 1 - a[y][x];
            }
        }

        cout << "Case " << t << ": ";
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }

        string s = "";
        solve(0, _count, s, a);

        if (ans == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
