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


bool g(int y, int x, int h, int w)
{
    return y >= 0 && y <= h - 1 && x >= 0 && x <= w - 1;
}

void delDot(int nowY, int nowX, vector<vector<char>> & a, int h, int w)
{
    if (g(nowY, nowX, h, w) == false)
    {
        return;
    }
    else if (a[nowY][nowX] != 'X')
    {
        return;
    }
    else
    {
        a[nowY][nowX] = '*';

        delDot(nowY + 1, nowX, a, h, w);
        delDot(nowY - 1, nowX, a, h, w);
        delDot(nowY, nowX + 1, a, h, w);
        delDot(nowY, nowX - 1, a, h, w);
    }
}

int delDice(int nowY, int nowX, vector<vector<char>> & a, int h, int w)
{
    if (g(nowY, nowX, h, w) == false)
    {
       	cout.flush();
       	return 0;
    }
    else if (a[nowY][nowX] == '.')
    {
       	cout.flush();
       	return 0;
    }
    else if (a[nowY][nowX] == 'X')
    {
        delDot(nowY, nowX, a, h, w);

        int count = 1;
        count += delDice(nowY + 1, nowX, a, h, w);
        count += delDice(nowY - 1, nowX, a, h, w);
        count += delDice(nowY, nowX + 1, a, h, w);
        count += delDice(nowY, nowX - 1, a, h, w);
        a[nowY][nowX] = '.';
        return count;
    }
    else
    {
        a[nowY][nowX] = '.';

        int count = 0;
        count += delDice(nowY + 1, nowX, a, h, w);
        count += delDice(nowY - 1, nowX, a, h, w);
        count += delDice(nowY, nowX + 1, a, h, w);
        count += delDice(nowY, nowX - 1, a, h, w);
        return count;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int throws = 0;

    while (true)
    {
        ++throws;

        int w = 0, h = 0; cin >> w >> h;
        if (h == 0) break;

        vector<vector<char>> a(h, vector<char>(w));
        for (int y = 0; y <= h - 1; ++y)
        {
            for (int x = 0; x <= w - 1; ++x)
            {
                cin >> a[y][x];
            }
        }

        vector<int> ans;
        for (int y = 0; y <= h - 1; ++y)
        {
            for (int x = 0; x <= w - 1; ++x)
            {
                if (a[y][x] != '.')
                {
                    ans.push_back(delDice(y, x, a, h, w));
                }
            }
        }
        sort(ans.begin(), ans.end());


        cout << "Throw " << throws << '\n';

        int size = ans.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            if (i > 0)
            {
                cout << ' ';
            }
            cout << ans[i];
        }
        cout << "\n\n";
    }

   	cout.flush();
   	return 0;
}
