#include <bits/stdc++.h>
#include <windows.h>
#include "ConsoleColor.h"

using namespace std;

ifstream fin("paint.in");
ofstream fout("paint.out");

int yN, xN;
const vector<int> yp = {-1, 0, 1, 0}, xp = {0, 1, 0, -1};

struct grid
{
    int type; // 0 -> water; 1 -> road; 2 -> turret;
    int direction;
    int firingRate;
    int t;
};
grid _grid(int type, int direction, int firingRate, int t)
{
    grid temp{type, direction, firingRate, t}; return temp;
}

struct point
{
    int direction;
    int y;
    int x;
};
point _point(int direction, int y, int x)
{
    point temp{direction, y, x}; return temp;
}

bool g(int y, int x)
{
    return y >= 0 && y <= yN - 1 && x >= 0 && x <= xN - 1;
}

void gameFlush(vector<point> & bullets, vector<point> & turrets, vector<vector<int>> & isDanger, vector<vector<grid>> & a)
{
    int turretCount = turrets.size();
    for (int i = 0; i <= turretCount - 1; ++i)
    {
        int y = turrets[i].y, x = turrets[i].x;

        if (a[y][x].t > 0)
        {
            --a[y][x].t;
        }
        else
        {
            bullets.insert(bullets.begin(), _point(turrets[i].direction, y, x));
            a[y][x].t = a[y][x].firingRate;
        }
    }

    int size = bullets.size();
    for (int i = 0; i <= size - 1; ++i)
    {
        isDanger[bullets[i].y][bullets[i].x] = 0;
        bullets[i].y += yp[bullets[i].direction]; bullets[i].x += xp[bullets[i].direction];

        if (g(bullets[i].y, bullets[i].x) == false)
        {
            bullets.erase(bullets.begin() + i);
            --i;
            --size;
            continue;
        }

        isDanger[bullets[i].y][bullets[i].x] = 1;
    }
}

int main()
{
    fin >> yN >> xN;
    vector<vector<int>> isDanger(yN, vector<int>(xN, 0));
    vector<vector<grid>> a(yN, vector<grid>(xN));

    for (int y = 0; y <= yN - 1; ++y)
    {
        for (int x = 0; x <= yN - 1; ++x)
        {
            char ch; fin >> ch;
            if (ch == '.')
            {
                a[y][x] = _grid(0, 0, 0, 0);
            }
            else
            {
                a[y][x] = _grid(1, 0, 0, 0);
            }
        }
    }

    int turretCount; fin >> turretCount;
    vector<point> turrets;
    for (int c = 1; c <= turretCount; ++c)
    {
        int y, x, direction, firingRate, t; fin >> y >> x >> direction >> firingRate >> t;

        a[y][x] = _grid(2, direction, firingRate, t);
        turrets.push_back(_point(direction, y, x));
    }
    vector<point> bullets;
    
    for (int gen = 1; gen <= 1000; ++gen)
    {
        while (true)
        {
            system("cls");
            gameFlush(bullets, turrets, isDanger, a);

            for (int y = 0; y <= yN - 1; ++y)
            {
                for (int x = 0; x <= yN - 1; ++x)
                {
                    if (isDanger[y][x] == 1)
                    {
                        cout << red << 'O';
                    }
                    else if (a[y][x].type == 0)
                    {
                        cout << white << ' ';
                    }
                    else if (a[y][x].type == 1)
                    {
                        cout << white << '#';
                    }
                    else if (a[y][x].type == 2)
                    {
                        cout << yellow << '@';
                    }
                }
                cout << '\n';
            }

            Sleep(300);
        }
    }

    return 0;
}
