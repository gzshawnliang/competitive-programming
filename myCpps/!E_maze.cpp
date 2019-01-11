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

ifstream fin("!E_maze.in");
ofstream fout("!E_maze.out");

struct point
{
    int y;
    int x;
};

bool g(int y, int x, int n, int m)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
}

int main()
{
    int n, m;
    point start;
    fin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= m - 1; ++x)
        {
            fin >> maze[y][x];
            if (maze[y][x] == 'S')
            {
                start.y = y;
                start.x = x;
            }
        }
    }

    vector<int> Yplus = {1, 0, -1, 0, 1, -1, 1, -1}, Xplus = {0, 1, 0, -1, -1, 1, 1, -1};
    vector<vector<int>> distance(n, vector<int>(m, 0));
    vector<vector<vector<point>>> path(n, vector<vector<point>>(m, vector<point>()));
    path[start.x][start.y].push_back(start);
    queue<point> a;
    a.push(start);

    bool ok = true;
    while (ok == true)
    {
        point now = a.front();
        a.pop();
        for (int p = 0; p <= 3; ++p)
        {
            point temp;
            temp.y = now.y + Yplus[p];
            temp.x = now.x + Xplus[p];
            if (g(temp.y, temp.x, n, m) == true)
            {
                if ((distance[temp.y][temp.x] == 0) && maze[temp.y][temp.x] != '#' && !(temp.y == start.y && temp.x == start.x))
                {
                    a.push(temp);
                    distance[temp.y][temp.x] = distance[now.y][now.x] + 1;

                    path[temp.y][temp.x] = path[now.y][now.x];
                    path[temp.y][temp.x].push_back(temp);

                    if (maze[temp.y][temp.x] == 'G')
                    {
                        fout << distance[temp.y][temp.x] << '\n';
                        
                        vector<vector<char>> out = maze;
                        int size = path[temp.y][temp.x].size();
                        for (int i = 0; i <= size - 1; ++i)
                        {
                            out[path[temp.y][temp.x][i].y][path[temp.y][temp.x][i].x] = '+';
                        }

                        for (int y = 0; y <= n - 1; ++y)
                        {
                            for (int x = 0; x <= m - 1; ++x)
                            {
                                fout << out[y][x];
                            }
                            fout << '\n';
                        }

                        ok = false;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}