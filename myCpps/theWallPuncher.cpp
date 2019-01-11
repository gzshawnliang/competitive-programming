#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

ifstream fin("theWallPuncher.in");
ofstream fout("theWallPuncher.out");

bool g(int y, int x)
{
    return (y <= 3 && y >= 0) && (x <= 5 && x >= 0);
}

struct square
{
    bool west;
    bool north;
    bool east;
    bool south;
};

string ans = "WWWWWWWWWWWWWWWWWWWWWWW";
void solve(vector<vector<square>> a, vector<vector<bool>> been, string out, int nowY, int nowX)
{
    if ((nowY == 0 && nowX == 0) || (nowY == 3 && nowX == 0) || (nowY == 3 && nowX == 5))
    {
        if (out.size() < ans.size())
        {
            ans = out;
            cout << out << '\n';
        }
    }
    int dy1[4] = {1, 0, -1, 0};
    int dx1[4] = {0, -1, 0, 1};
    int dy2[4] = {2, 0, -2, 0};
    int dx2[4] = {0, -2, 0, 2};
    for (int d = 0; d <= 3; ++d)
    {
        if (g(nowY + dy1[d], nowX + dx1[d]))
        {
            if (been[nowY + dy1[d]][nowX + dx1[d]] == false)
            {
                if (a[nowY + dy1[d]][nowX + dx1[d]].west == true && d == 1)
                {
                    if (g(nowY + dy2[d], nowX + dx2[d]) == true)
                    {
                        if (a[nowY + dy2[d]][nowX + dx2[d]].west == false)
                        {
                            vector<vector<square>> temp1 = a;
                            temp1[nowY + dy2[d]][nowX + dx2[d]].west = true;
                            temp1[nowY + dy1[d]][nowX + dx1[d]].west = false;
                            vector<vector<bool>> temp2 = been;
                            temp2[nowY + dy1[d]][nowX + dx1[d]] = true;
                            solve(temp1, temp2, out + 'W', nowY + dy1[d], nowX + dx2[d]);
                        }
                    }
                }
                else if (a[nowY + dy1[d]][nowX + dx1[d]].north == true && d == 0)
                {
                    if (g(nowY + dy2[d], nowX + dx2[d]) == true)
                    {
                        if (a[nowY + dy2[d]][nowX + dx2[d]].north == false)
                        {
                            vector<vector<square>> temp1 = a;
                            temp1[nowY + dy2[d]][nowX + dx2[d]].north = true;
                            temp1[nowY + dy1[d]][nowX + dx1[d]].north = false;
                            vector<vector<bool>> temp2 = been;
                            temp2[nowY + dy1[d]][nowX + dx1[d]] = true;
                            solve(temp1, temp2, out + 'N', nowY + dy1[d] + 1, nowX + dx2[d]);
                        }
                    }
                }
                else if (a[nowY + dy1[d]][nowX + dx1[d]].east == true && d == 3)
                {
                    if (g(nowY + dy2[d], nowX + dx2[d]) == true)
                    {
                        if (a[nowY + dy2[d]][nowX + dx2[d]].east == false)
                        {
                            vector<vector<square>> temp1 = a;
                            temp1[nowY + dy2[d]][nowX + dx2[d]].east = true;
                            temp1[nowY + dy1[d]][nowX + dx1[d]].east = false;
                            vector<vector<bool>> temp2 = been;
                            temp2[nowY + dy1[d]][nowX + dx1[d]] = true;
                            solve(temp1, temp2, out + 'E', nowY + dy1[d], nowX + dx2[d]);
                        }
                    }
                }
                else if (a[nowY + dy1[d]][nowX + dx1[d]].south == true && d == 2)
                {
                    if (g(nowY + dy2[d], nowX + dx2[d]) == true)
                    {
                        if (a[nowY + dy2[d]][nowX + dx2[d]].south == false)
                        {
                            vector<vector<square>> temp1 = a;
                            temp1[nowY + dy2[d]][nowX + dx2[d]].south = true;
                            temp1[nowY + dy1[d]][nowX + dx1[d]].south = false;
                            vector<vector<bool>> temp2 = been;
                            temp2[nowY + dy1[d]][nowX + dx1[d]] = true;
                            solve(temp1, temp2, out + 'S', nowY + dy1[d], nowX + dx2[d]);
                        }
                    }
                }
                else
                {
                    char move;
                    if (d == 1)
                    {
                        move = 'W';
                    }
                    else if (d == 0)
                    {
                        move = 'N';
                    }
                    else if (d == 3)
                    {
                        move = 'E';
                    }
                    else
                    {
                        move = 'S';
                    }

                    vector<vector<bool>> temp2 = been;
                    temp2[nowY + dy1[d]][nowX + dx1[d]] = true;
                    solve(a, temp2, out + move, nowY + dy1[d], nowX + dx2[d]);
                }
            }
        }
    }
}

int main()
{
    int startY, startX;
    fin >> startX >> startY;
    --startY;
    --startX;

    vector<vector<square>> a(4, vector<square>(6));
    vector<vector<bool>> been(4, vector<bool>(6, false));
    string putIn = "";

    for (int y = 0; y <= 3; ++y)
    {
        for (int x = 0; x <= 5; ++x)
        {
            int p;
            square temp{0, 0, 0, 0};
            fin >> p;
            if (p % 2 == 1)
            {
                temp.west = 1;
            }
            p /= 2;
            if (p % 2 == 1 && p != 0)
            {
                temp.north = 1;
            }
            p /= 2;
            if (p % 2 == 1 && p != 0)
            {
                temp.east = 1;
            }
            p /= 2;
            if (p % 2 == 1 && p != 0)
            {
                temp.south = 1;
            }
            a[y][x] = temp;
        }
    }

    // for (int y = 0; y <= 3; ++y)
    // {
    //     for (int x = 0; x <= 5; ++x)
    //     {
    //         square temp = a[y][x];
    //         fout << temp.west << ' ' << temp.north << ' ' << temp.east << ' ' << temp.south << '\n';
    //     }
    // }

    solve(a, been, putIn, startY, startX);

    fout << ans << '\n';

    return 0;
}