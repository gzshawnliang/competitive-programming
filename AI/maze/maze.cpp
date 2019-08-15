#include <bits/stdc++.h>

using namespace std;

ifstream fin("maze.in");
ofstream fout("maze.out");

int yN, xN, sy, sx;
const int maxT = 10, N = 1000, mutationChance = 1000;

struct point
{
    int y;
    int x;
};
point _point(int y, int x)
{
    point temp{y, x}; return temp;
}

struct movement
{
    int u;
    int r;
    int d;
    int l;
};
movement _movement(int u, int r, int d, int l)
{
    movement temp{u, r, d, l}; return temp;
}

bool g(int y, int x)
{
    return y >= 0 && y <= yN - 1 && x >= 0 && x <= xN - 1;
}

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
}

int main()
{
    fin >> yN >> xN;

    vector<vector<char>> a(yN, vector<char>(xN, '.'));
    movement _null{-1, -1, -1, -1};
    vector<vector<vector<movement>>> AI(yN, vector<vector<movement>>(xN, vector<movement>(maxT + 1, _null)));
    
    for (int y = 0; y <= yN - 1; ++y)
        for (int x = 0; x <= xN - 1; ++x)
            fin >> a[y][x];

    for (int y = 0; y <= yN - 1; ++y)
    {
        for (int x = 0; x <= xN - 1; ++x)
        {
            if (a[y][x] == 'S')
            {
                sy = y; sx = x;
            }
        }
    }

    int lastScore = 0, score = 0;
    for (int gen = 1; gen <= 1000; ++gen)
    {
        vector<vector<vector<movement>>> nowAI = AI;
        if (gen == 1)
        {
            for (int y = 0; y <= yN - 1; ++y)
            {
                for (int x = 0; x <= xN - 1; ++x)
                {
                    for (int t = 0; t <= maxT; ++t)
                    {
                        vector<int> vis(N, 0);
                        vector<int> block;
                        for (int c = 1; c <= 5 - 1; ++c)
                        {
                            int i = getRand(0, N - 1);

                            if (vis[i] == false)
                            {
                                block.push_back(i);
                                vis[i] = true;
                            }
                            else
                            {
                                --c;
                            }
                        }

                        sort(block.begin(), block.end());
                        nowAI[y][x][t].u = block[0];
                        nowAI[y][x][t].r = block[1];
                        nowAI[y][x][t].d = block[2];
                        nowAI[y][x][t].l = block[3];
                    }
                }
            }
        }
        else
        {
            for (int y = 0; y <= yN - 1; ++y)
            {
                for (int x = 0; x <= xN - 1; ++x)
                {
                    for (int t = 0; t <= maxT; ++t)
                    {
                        if (getRand(0, mutationChance - 1) == 0)
                        {
                            vector<int> vis(N, 0);
                            vector<int> block;
                            for (int c = 1; c <= 5 - 1; ++c)
                            {
                                int i = getRand(0, N - 1);

                                if (vis[i] == false)
                                {
                                    block.push_back(i);
                                    vis[i] = true;
                                }
                                else
                                {
                                    --c;
                                }
                            }

                            sort(block.begin(), block.end());
                            nowAI[y][x][t].u = block[0];
                            nowAI[y][x][t].r = block[1];
                            nowAI[y][x][t].d = block[2];
                            nowAI[y][x][t].l = block[3];
                        }
                    }
                }
            }
        }

        vector<point> p;
        vector<vector<int>> vis(yN, vector<int>(xN, 0));

        int y = sy, x = sx;
        for (int t = 0; t <= maxT; ++t)
        {
            if (a[y][x] == 'T' && vis[y][x] == 0)
            {
                ++score;
            }

            p.push_back(_point(y, x));

            vis[y][x] = 1;
            
            int i = getRand(0, N - 1);
            if (i <= nowAI[y][x][t].u)
            {
                --y;
                if (g(y, x) == false)
                {
                    ++y;
                }
                else if (a[y][x] == 'W')
                {
                    ++y;
                }
            }
            else if (i <= nowAI[y][x][t].r)
            {
                ++x;
                if (g(y, x) == false)
                {
                    --x;
                }
                else if (a[y][x] == 'W')
                {
                    --x;
                }
            }
            else if (i <= nowAI[y][x][t].d)
            {
                ++y;
                if (g(y, x) == false)
                {
                    --y;
                }
                else if (a[y][x] == 'W')
                {
                    --y;
                }
            }
            else if (i <= nowAI[y][x][t].l)
            {
                --x;
                if (g(y, x) == false)
                {
                    ++x;
                }
                else if (a[y][x] == 'W')
                {
                    ++x;
                }
            }
        }

        if (score > 0)
        {
            fout << "Gen " << gen << ":\n";
            fout << "Score: " << score << '\n';
            for (int t = 0; t <= maxT; ++t)
            {
                fout << p[t].y << ' ' << p[t].x << '\n';
            }
            fout << '\n';

        }
        
        if (score > lastScore)
        {
            lastScore = score;
            AI = nowAI;
        }
    }

    for (int y = 0; y <= yN - 1; ++y)
    {
        for (int x = 0; x <= xN - 1; ++x)
        {
            for (int t = 0; t <= maxT; ++t)
            {
                fout << AI[y][x][t].u << ' '
                     << AI[y][x][t].r << ' '
                     << AI[y][x][t].d << ' '
                     << AI[y][x][t].l << ' '
                     << AI[y][x][t].d << '\n';
            }
        }
    }

    return 0;
}
