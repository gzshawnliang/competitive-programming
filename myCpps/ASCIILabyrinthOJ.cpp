#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;


bool g(int y, int x, int m, int n)
{
    return y >= 0 && y <= m - 1 && x >= 0 && x <= n - 1;
}

int solve(int nowY, int nowX, char lastDirection, vector<vector<char>> & a, int m, int n, vector<vector<bool>> path)
{
    if (lastDirection == '-')
    {
        path[nowY][nowX] = true;
        return solve(nowY + 1, nowX, 'd', a, m, n, path) + solve(nowY, nowX + 1, 'r', a, m, n, path);
    }
    else if (g(nowY, nowX, m, n) == false || a[nowY][nowX] == 'b' || path[nowY][nowX] == true)
    {
       	return 0;
    }
    else if (nowY == m - 1 && nowX == n - 1)
    {
        return 1;
    }
    else
    {
        path[nowY][nowX] = true;
        if (a[nowY][nowX] == 'l')
        {
            if (lastDirection == 'u')
            {
                return solve(nowY - 1, nowX, 'u', a, m, n, path);
            }
            else if (lastDirection == 'd')
            {
                return solve(nowY + 1, nowX, 'd', a, m, n, path);
            }
            else if (lastDirection == 'l')
            {
                return solve(nowY, nowX - 1, 'l', a, m, n, path);
            }
            else
            {
                return solve(nowY, nowX + 1, 'r', a, m, n, path);
            }
        }
        else
        {
            if (lastDirection == 'u' || lastDirection == 'd')
            {
                return solve(nowY, nowX - 1, 'l', a, m, n, path) + solve(nowY, nowX + 1, 'r', a, m, n, path);
            }
            else
            {
                return solve(nowY - 1, nowX, 'u', a, m, n, path) + solve(nowY + 1, nowX, 'd', a, m, n, path);
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase;
    cin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int m, n;
        cin >> m >> n;

        string in;
        getline(cin, in);
        vector<vector<char>> a(m, vector<char>(n));
        vector<vector<bool>> path(m, vector<bool>(n, false));
        for (int i = 0; i <= m - 1; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                getline(cin, in);
                if (j == 3)
                {
                    string temp = "";
                    int pos = 0;
                    for (int k = 1; k <= 4 * n; ++k)
                    {
                        if (in[k] == '|')
                        {
                            if (temp == "   ")
                            {
                                a[i][pos] = 'b';
                            }
                            else if (temp == "***")
                            {
                                a[i][pos] = 'l';
                            }
                            else
                            {
                                a[i][pos] = 'c';
                            }

                            temp = "";

                            ++pos;
                        }
                        else
                        {
                            temp += in[k];
                        }
                    }
                }
            }
        }
        getline(cin, in);

        if (m == 1 && n == 1)
        {
            cout << "Number of solutions: 2\n";
        }
        else
        {
            cout << "Number of solutions: " << solve(0, 0, '-', a, m, n, path) << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
