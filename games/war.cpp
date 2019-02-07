#include <bits/stdc++.h>
#include <windows.h>
#include "ConsoleColor.h"

using namespace std;

void cls()
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };
    std::cout.flush();
    if (!GetConsoleScreenBufferInfo(hOut, &csbi))
    {
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD written;
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);
    SetConsoleCursorPosition(hOut, topLeft);
}

class unit
{
    private:

    

    public:

    string team;
    string type;

    int y;
    int x;
    int health;
    int maxHealth;
    int attack;

    char direction;
};

struct point
{
    int y;
    int x;

    bool operator == (const point & temp) const
    {
        return y == temp.y && x == temp.x;
    }
};

bool g(int y, int x, int n, int m)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= m - 1;
}

unit _unit(string team, string type, int y, int x, int health, int maxHealth, int attack)
{
    unit temp{team, type, y, x, health, maxHealth, attack, '.'};

    return temp;
}

point _point(int y, int x)
{
    point temp{y, x};

    return temp;
}

char d
(
    bool healer,
    unit & u,
    vector<unit> & f,
    vector<string> & a,
    vector<vector<int>> & pos
)
{
    int n = a.size(), m = a[0].size();

    queue<point> q;
    q.push(_point(u.y, u.x));

    bool _find = false;
    vector<int> _p = {0, 1, 0, -1};
    vector<vector<point>> last(n, vector<point>(m, _point(-1, -1)));

    while (!q.empty())
    {
        point now = q.front();
        q.pop();

        if (g(now.y, now.x, n, m) == false)
        {
            continue;
        }
        else if (a[now.y][now.x] == '#')
        {
            continue;
        }
        else
        {
            if (pos[now.y][now.x] >= 0)
            {
                if ((healer == true && f[pos[now.y][now.x]].team == u.team) || (healer == false && f[pos[now.y][now.x]].team != u.team))
                {
                    while (true)
                    {
                        if (abs(now.y - u.y) + abs(now.x - u.x) == 1)
                        {
                            if      (now.y > u.y) return 'd';
                            else if (now.y < u.y) return 'u';
                            else if (now.x > u.x) return 'r';
                            else                  return 'l';
                        }
                        else if (now.y == -1 && now.x == -1)
                        {
                            return '.';
                        }

                        now = last[now.y][now.x];
                    }
                }
            }

            if ((a[now.y][now.x] != '.' && now.y != u.y && now.x == u.x))
            {
                continue;
            }
        }

        for (int p = 0; p <= 3; ++p)
        {
            int y = now.y + _p[p], x = now.x + _p[(p + 1) % 4];

            if (g(y, x, n, m) == false)
            {
                continue;
            }
            else if (!(last[y][x] == _point(-1, -1)))
            {
                continue;
            }
            
            last[y][x] = now;
            q.push(_point(y, x));
        }
    }

    return '.';
}

void out(vector<unit> & f, vector<string> & a, vector<vector<int>> & pos)
{
    int n = a.size(), m = a[0].size();

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= m - 1; ++x)
        {
            std::cout << white;
            if (a[y][x] == '.')
            {
                std::cout << '.';
            }
            else if (a[y][x] == '#')
            {
                std::cout << "#";
            }
            else if (pos[y][x] >= 0)
            {
                if (f[pos[y][x]].team == "blue")
                {
                    std::cout << blue;
                }
                else if (f[pos[y][x]].team == "red")
                {
                    std::cout << red;
                }
                else
                {
                    std::cout << yellow;
                }

                std::cout << a[y][x];
            }
        }
        std::cout << '\n';
    }
}

int main()
{
    vector<string> a;

    a.push_back(".............#..............");
    a.push_back(".............#..............");
    a.push_back(".......##.#..#.#............");
    a.push_back("...#...#.......#............");
    a.push_back("...#.........###............");
    a.push_back("......#......#..............");
    a.push_back("......###...................");
    a.push_back("........#....#......#.......");
    a.push_back(".............#......#.......");
    a.push_back("........#....#..............");
    a.push_back("............................");

    int n = a.size(), m = a[0].size();

    vector<unit> f;
    vector<vector<int>> _pos(n, vector<int>(m, -1));

    //f.push_back(_unit("red", "sword", 0, 0, 10, 10, 1));

    bool press = false;
    point mouse{0, 0}, p1{-1, -1};

    while (true)
    {
        press = false;

        if (GetAsyncKeyState(VK_UP))
        {
            mouse.y = (mouse.y - 1) % n;
            if (mouse.y < 0) mouse.y += n;
            press = true;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            mouse.y = (mouse.y + 1) % n;
            press = true;
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            mouse.x = (mouse.x - 1) % m;
            if (mouse.x < 0) mouse.x += m;
            press = true;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            mouse.x = (mouse.x + 1) % m;
            press = true;
        }
        if (GetAsyncKeyState((int)'P'))
        {
            if (p1.y >= 0)
            {
                std::cout << white << "selected area.\n";

                Sleep(100);

                std::cout << "input team:\n";

                string _team; cin >> _team;

                for (int y = min(mouse.y, p1.y); y <= max(mouse.y, p1.y); ++y)
                {
                    for (int x = min(mouse.x, p1.x); x <= max(mouse.x, p1.x); ++x)
                    {
                        if (a[y][x] == '.' && _pos[y][x] < 0)
                        {
                            _pos[y][x] = f.size();
                            f.push_back(_unit(_team, "sword", y, x, 1, 9, 1));
                        }
                    }
                }

                p1 = _point(-1, -1);
            }
            else
            {
                p1 = _point(mouse.y, mouse.x);
            }

            press = true;

        }
        if (GetAsyncKeyState((int)'O'))
        {
            p1 = _point(-1, -1);
            press = true;
        }
        if (GetAsyncKeyState((int)'F'))
        {
            break;
        }

        if (press == true)
        {
            cls();

            std::cout << white << mouse.y << ' ' << mouse.x << '\n';
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    std::cout << white;

                    if (mouse.y == y && mouse.x == x)
                    {
                        std::cout << red;
                    }
                    else if (p1.y == y && p1.x == x)
                    {
                        std::cout << green;
                    }

                    if (_pos[y][x] >= 0)
                    {
                        unit now = f[_pos[y][x]];

                        if (now.team == "blue")
                        {
                            std::cout << blue;
                        }
                        else if (now.team == "red")
                        {
                            std::cout << red;
                        }
                        else
                        {
                            std::cout << yellow;
                        }

                        char temp = '0';
                        if (now.health <= 9)
                        {
                            temp = now.health + '0';
                        }
                        else if (now.health <= 35)
                        {
                            temp = (now.health - 10) + 'a';
                        }
                        else if (now.health <= 61)
                        {
                            temp = (now.health - 36) + 'A';
                        }
                        else
                        {
                            temp = '$';
                        }

                        std::cout << temp;
                    }
                    else
                    {
                        std::cout << a[y][x];
                    }
                }
                std::cout << '\n';
            }

            Sleep(100);
        }
    }

    set<string> __tempSet;
    int __size = f.size();
    for (int i = 0; i <= __size - 1; ++i)
    {
        __tempSet.insert(f[i].team);
    }
    int TOTALTEAM = __tempSet.size();


    bool done = false;
    vector<int> _p = {0, 1, 0, -1};
   
    while (done == false)
    {
        cls();

        map<string, int> teamLeft;
        vector<vector<int>> pos(n, vector<int>(m, -1));
        vector<string> tempA = a;

        int size = f.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            if (f[i].health < 0)
            {
                f.erase(f.begin() + i);

                --size;
                --i;
            }
        }

        for (int i = 0; i <= size - 1; ++i)
        {
            unit now = f[i];

            ++teamLeft[now.team];

            now.health = min(now.health, now.maxHealth);

            char temp = '0';
            if (now.health <= 9)
            {
                temp = now.health + '0';
            }
            else if (now.health <= 35)
            {
                temp = (now.health - 10) + 'a';
            }
            else if (now.health <= 61)
            {
                temp = (now.health - 36) + 'A';
            }
            else
            {
                temp = '$';
            }

            tempA[now.y][now.x] = temp;

            pos[now.y][now.x] = i;
        }

        if (done == false)
        {
            for (int i = 0; i <= size - 1; ++i)
            {
                unit now = f[i];
                
                for (int p = 0; p <= 3; ++p)
                {
                    int y = now.y + _p[p], x = now.x + _p[(p + 1) % 4];

                    if (g(y, x, n, m) == false) continue;
                    else if (pos[y][x] == -1) continue;

                    unit aim = f[pos[y][x]];
                    
                    if (aim.team != now.team && aim.type != "healer")
                    {
                        f[i].health -= aim.attack;
                    }
                    else if (aim.team == now.team && aim.type == "healer")
                    {
                        f[i].health += aim.attack;
                        f[i].health = min(f[i].health, f[i].maxHealth);
                    }
                }

                f[i].direction = d(false, now, f, tempA, pos);
            }

            vector<unit> tempF = f;

            for (int i = 0; i <= size - 1; ++i)
            {
                unit now = tempF[i];
                
                int y = now.y, x = now.x;

                if (now.direction == 'u')
                {
                    --y;
                }
                else if (now.direction == 'd')
                {
                    ++y;
                }
                else if (now.direction == 'l')
                {
                    --x;
                }
                else if (now.direction == 'r')
                {
                    ++x;
                }

                if (tempA[y][x] == '.')
                {
                    f[i].y = y; f[i].x = x;
                }
            }
        }

        bool _find = false;

        int _outTeam = 0;
        std::cout << "team:\n";
        for (auto it = teamLeft.begin(); it != teamLeft.end(); ++it)
        {
            std::cout << it->first << ": " << it->second << '\n';
            ++_outTeam;

            if (it->second > 0)
            {
                _find = true;
            }
        }

        for (int c = _outTeam + 1; c <= TOTALTEAM; ++c)
        {
            std::cout << '\n';
        }

        done = !(_find);

        out(f, tempA, pos);

        Sleep(500);
    }

    while (true)
    {
        string in; cin >> in;
        if (in == "end")
        {
            break;
        }
    }

    return 0;
}
