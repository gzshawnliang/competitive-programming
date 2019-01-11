#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("biggestNumber.in");
ofstream fout("biggestNumber.out");

struct point
{
    int y;
    int x;
};

bool compare(string & string1, string & string2)
{
    int sizeA = string1.size(), sizeB = string2.size();
    if (sizeA == sizeB)
    {
        for (int i = 0; i <= sizeA - 1; ++i)
        {
            if (string1[i] != string2[i])
            {
                return string1[i] < string2[i];
            }
        }

        return true;
    }
    else
    {
        return sizeA < sizeB;
    }
}

bool g(int y, int x, int r, int c)
{
    return y >= 0 && y <= r - 1 && x >= 0 && x <= c - 1;
}

int deep(int nowY, int nowX, int r, int c, vector<vector<char>> & a, int count, vector<vector<bool>> path)
{
    if (g(nowY, nowX, r, c) == false)
    {
        return count;
    }
    else if (a[nowY][nowX] == '#' || path[nowY][nowX] == true)
    {
         return count;
    }
    else
    {
        path[nowY][nowX] = true;
        int maxDeepness = 0;
        maxDeepness = max(maxDeepness, deep(nowY + 1, nowX, r, c, a, count + 1, path));
        maxDeepness = max(maxDeepness, deep(nowY - 1, nowX, r, c, a, count + 1, path));
        maxDeepness = max(maxDeepness, deep(nowY, nowX + 1, r, c, a, count + 1, path));
        maxDeepness = max(maxDeepness, deep(nowY, nowX - 1, r, c, a, count + 1, path));

        return maxDeepness;
    }
}

int deep2(int nowY, int nowX, int r, int c, vector<vector<char>> & a,vector<vector<bool>> & path)
{
    vector<vector<bool>> visit(r, vector<bool>(c, false));
    visit[nowY][nowX] = true;
    queue<point> b;
    point l; 
    l.y = nowY; 
    l.x = nowX;
    b.push(l);

    int ans0 = 1;
    while (b.size() > 0)
    {
        point now = b.front();
        b.pop();

        vector<int> py = {0, 1, 0, -1};
        vector<int> px = {1, 0, -1, 0};
        for (int p = 0; p <= 3; ++p)
        {
            point temp; temp.y = now.y + py[p]; temp.x = now.x + px[p];
            if (g(temp.y, temp.x, r, c) == true)
            {
                if (visit[temp.y][temp.x] == false && a[temp.y][temp.x] != '#' && path[temp.y][temp.x] == false )
                {
                    b.push(temp);
                    visit[temp.y][temp.x] = true;

                    ++ans0;
                }
            }
        }
    }

    return ans0;
}

string ans;
void solve(int nowY, int nowX, int r, int c, vector<vector<char>> & a, string s, vector<vector<bool>> path)
{
    if (g(nowY, nowX, r, c) == false)
    {
        if (compare(ans, s) == true)
        {
            ans = s;
        }
    }
    else if (a[nowY][nowX] == '#' || path[nowY][nowX] == true)
    {
        if (compare(ans, s) == true)
        {
            ans = s;
        }
    }
    else if (s.size() + deep2(nowY, nowX, r, c, a,path) < ans.size())
    {
         return;
    }
    else
    {
        s += a[nowY][nowX];

        //fout << s << '\n';

        path[nowY][nowX] = true;
        solve(nowY + 1, nowX, r, c, a, s, path);
        solve(nowY - 1, nowX, r, c, a, s, path);
        solve(nowY, nowX + 1, r, c, a, s, path);
        solve(nowY, nowX - 1, r, c, a, s, path);
    }
}

int main2()
{
    while (true)
    {
        ans = "0";
        int r = 0, c = 0;

        fin >> r >> c;

        if (r == 0)
        {
            break;
        }

        vector<vector<char>> a(r, vector<char>(c));
        vector<vector<bool>> path(r, vector<bool>(c, false));
        for (int y = 0; y <= r - 1; ++y)
        {
            for (int x = 0; x <= c - 1; ++x)
            {
                fin >> a[y][x];
            }
        }

        fout << deep2(1, 1, r, c, a,path) << '\n';
    }
}

int main()
{
    while (true)
    {
        ans = "0";
        int r = 0, c = 0;

        fin >> r >> c;

        if (r == 0)
        {
            break;
        }

        vector<vector<char>> a(r, vector<char>(c));
        vector<vector<bool>> path(r, vector<bool>(c, false));
        for (int y = 0; y <= r - 1; ++y)
        {
            for (int x = 0; x <= c - 1; ++x)
            {
                fin >> a[y][x];
            }
        }

        for (int y = 0; y <= r - 1; ++y)
        {
            for (int x = 0; x <= c - 1; ++x)
            {
                if (a[y][x] != '#')
                {
                    solve(y, x, r, c, a, "", path);
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}