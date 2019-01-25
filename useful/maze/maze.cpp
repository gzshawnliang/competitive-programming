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
#include <set>
#include <map>

using namespace std;

//ifstream fin("maze.in");
ofstream fout("maze.out");

vector<string> image(int x)
{
    vector<string> ans;

    if (x == 1)
    {
        ans.push_back("#.#");
        ans.push_back("...");
        ans.push_back("#.#");
    }
    else if (x == 2)
    {
        ans.push_back("###");
        ans.push_back("###");
        ans.push_back("###");
    }
    else if (x == 3)
    {
        ans.push_back("###");
        ans.push_back("...");
        ans.push_back("###");
    }
    else if (x == 4)
    {
        ans.push_back("#.#");
        ans.push_back("#.#");
        ans.push_back("#.#");
    }
    else if (x == 5)
    {
        ans.push_back("###");
        ans.push_back("..#");
        ans.push_back("#.#");
    }
    else if (x == 6)
    {
        ans.push_back("#.#");
        ans.push_back("..#");
        ans.push_back("###");
    }
    else if (x == 7)
    {
        ans.push_back("#.#");
        ans.push_back("#..");
        ans.push_back("###");
    }
    else if (x == 8)
    {
        ans.push_back("###");
        ans.push_back("#..");
        ans.push_back("#.#");
    }

    return ans;
}

int getRand(int a,int b)
{
    int c=b-a+1;
    return rand() % c + a;
}

bool g(int y, int x, int n)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
}

bool check(char d, int y, int x, vector<vector<int>> & a, string & path)
{
    int n = a.size();

    if (g(y, x, n) == false)
    {
        return false;
    }
    else if (a[y][x] == 0)
    {
        return false;
    }
    else
    {
        path += d;

        bool ans = false;

        vector<string> res = image(a[y][x]);


        if (d == 'u' && res[2][1] == '#')
        {
            return false;
        }
        else if (d == 'd' && res[0][1] == '#')
        {
            return false;
        }
        else if (d == 'l' && res[1][2] == '#')
        {
            return false;
        }
        else if (d == 'r' && res[1][0] == '#')
        {
            return false;
        }
        else if (y == n - 1 && x == n - 1)
        {
            return true;
        }


        a[y][x] = 0;

        string temp = path;

        if (res[0][1] == '.')
        {
            ans = check('u', y - 1, x, a, path);
            if (ans == false)
            {
                path = temp;
            }
        }
        if (res[2][1] == '.' && ans == false)
        {
            ans = check('d', y + 1, x, a, path);
            if (ans == false)
            {
                path = temp;
            }
        }
        if (res[1][0] == '.' && ans == false)
        {
            ans = check('l', y, x - 1, a, path);
            if (ans == false)
            {
                path = temp;
            }
        }
        if (res[1][2] == '.' && ans == false)
        {
            ans = check('r', y, x + 1, a, path);
            if (ans == false)
            {
                path = temp;
            }
        }

        return ans;
    }
}

void outPut(vector<vector<char>> & m)
{
    int n = m.size() / 3;

    for (int y = 0; y <= 3 * n - 1; ++y)
    {
        for (int x = 0; x <= 3 * n - 1; ++x)
        {
            if (y == 1 && x == 1)
            {
                fout << "OP";
            }
            else if (y == 3 * n - 2 && x == 3 * n - 2)
            {
                fout << "ED";
            }
            else if (m[y][x] == '.')
            {
                fout << "  ";
            }
            else if (m[y][x] == '#' || m[y][x] == 'x')
            {
                fout << "██";
            }
            else if (m[y][x] == 'p')
            {
                fout << "▒▒";
                //fout << "░";
            }
        }
        fout << '\n';
    }
}

int main()
{
    srand(time(0));

    int n = 30, tries = 0;

    n = max(n, 2);
    n = min(n, 30);
     
    vector<vector<int>> a(n, vector<int>(n, 1));

    while (true)
    {
        ++tries; 

        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                if (getRand(1, 3) == 1)
                {
                    a[y][x] = 1;
                }
                else
                {
                    a[y][x] = getRand(2, 8);
                }
            }
        }

        string path = "";
        vector<vector<int>> temp = a;

        bool ans = check(' ', 0, 0, temp, path);

        path.erase(path.begin());

        if (ans == true)
        {
            fout << tries << '\n' << path << '\n';

            fout << '\n';
            for (int c = 1; c <= (n * 6 - 4) / 2; ++c)
            {
                fout << '-';
            }
            fout << "maze";
            for (int c = 1; c <= n * 6 - 4 - (n * 6 - 4) / 2; ++c)
            {
                fout << '-';
            }
            fout << "\n\n";

            vector<vector<char>> m(n * 3, vector<char>(n * 3, '.'));

            for (int y = 0; y <= 3 * n - 1; y += 3)
            {
                for (int x = 0; x <= 3 * n - 1; x += 3)
                {
                    vector<string> res = image(a[y / 3][x / 3]);

                    for (int dy = 0; dy <= 2; ++dy)
                    {
                        for (int dx = 0; dx <= 2; ++dx)
                        {
                            m[y + dy][x + dx] = res[dy][dx];
                        }
                    }
                }
            }

            vector<int> yP = {-1, 0, 1, 0};
            vector<int> xP = {0, -1, 0, 1};
            for (int y = 0; y <= 3 * n - 1; ++y)
            {
                for (int x = 0; x <= 3 * n - 1; ++x)
                {
                    int _count = 0;
                    for (int p = 0; p <= 3; ++p)
                    {
                        int nowY = y + yP[p], nowX = x + xP[p];

                        if (g(nowY, nowX, n * 3) == false)
                        {
                            _count = 3;
                            break;
                        }
                        else if (m[nowY][nowX] == '#')
                        {
                            ++_count;
                        }
                    }

                    if (_count == 3)
                    {
                        m[y][x] = 'x';
                    }
                }
            }

            outPut(m);

            fout << '\n';
            for (int c = 1; c <= (n * 6 - 6) / 2; ++c)
            {
                fout << '-';
            }
            fout << "answer";
            for (int c = 1; c <= n * 6 - 6 - (n * 6 - 6) / 2; ++c)
            {
                fout << '-';
            }
            fout << "\n\n";

            int size = path.size(), nowY = 1, nowX = 1;
            for (int i = 0; i <= size - 1; ++i)
            {
                if (path[i] == 'u')
                {
                    for (int c = 1; c <= 3; ++c)
                    {
                        --nowY;
                        m[nowY][nowX] = 'p';
                    }
                }
                else if (path[i] == 'd')
                {
                    for (int c = 1; c <= 3; ++c)
                    {
                        ++nowY;
                        m[nowY][nowX] = 'p';
                    }
                }
                else if (path[i] == 'l')
                {
                    for (int c = 1; c <= 3; ++c)
                    {
                        --nowX;
                        m[nowY][nowX] = 'p';
                    }
                }
                else if (path[i] == 'r')
                {
                    for (int c = 1; c <= 3; ++c)
                    {
                        ++nowX;
                        m[nowY][nowX] = 'p';
                    }
                }
            }

            outPut(m);

            break;
        }
    }

    return 0;
}
