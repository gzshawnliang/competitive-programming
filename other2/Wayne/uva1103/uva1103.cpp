#include <algorithm>
//#include <cmath>
//#include <cstdio>
#include <cstdlib>
#include <fstream>
//#include <iomanip>
#include <iostream>
//#include <set>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

ifstream fin("uva1103.in");
ofstream fout("uva1103.out");

vector<string> trans;
string t(char in)
{
    if (in <= '9')
    {
        return trans[in - '0'];
    }
    else
    {
        return trans[10 + (in - 'a')];
    }
}

struct point
{
    int y;
    int x;
};

bool g(int y, int x, int h, int w)
{
    return y >= 0 && y <= h - 1 && x >= 0 && x <= w - 1;
}

void bfsClear(int y, int x, int h, int w, vector<string> & a)
{
    vector<int> yPlus = {1, 0, -1, 0};
    vector<int> xPlus = {0, 1, 0, -1};

    queue<point> q;
    point start = {y, x};
    a[y][x] = '.';
    q.push(start);
    
    while (!(q.empty()))
    {
        point s = q.front();
        q.pop();
        for (int p = 0; p <= 3; ++p)
        {
            point now = {s.y + yPlus[p], s.x + xPlus[p]};
            if (g(now.y, now.x, h, w) == false)
            {
                continue;
            }
            else if (a[now.y][now.x] != '0')
            {
                continue;
            }
            else
            {
                a[now.y][now.x] = '.';
                q.push(now);
            }
        }
    }
}

int dfsCount(int y, int x, int h, int w, vector<string> & a)
{
    if (g(y, x, h, w) == false)
    {
        return 0;
    }
    else if (a[y][x] == '.')
    {
        return 0;
    }
    else if (a[y][x] == '0')
    {
        bfsClear(y, x, h, w, a);

        return 1;
    }
    else
    {
        a[y][x] = '.';

        int res = 0;
        res += dfsCount(y + 1, x, h, w, a);
        res += dfsCount(y - 1, x, h, w, a);
        res += dfsCount(y, x + 1, h, w, a);
        res += dfsCount(y, x - 1, h, w, a);
        return res;
    }
}

int main()
{
    string str = "0000";
    trans.push_back(str);
    for (int i = 1; i <= 15; ++i)
    {
        ++str[3];

        if (str[3] == '2')
        {
            str[3] = '0';
            ++str[2];

            if (str[2] == '2')
            {
                str[2] = '0';
                ++str[1];
                
                if (str[1] == '2')
                {
                    str[1] = '0';
                    ++str[0];
                }
            }
        }
        trans.push_back(str);
    }

    int _case = 0;
    while (true)
    {
        ++_case;

        int h = 0, w = 0;
        fin >> h >> w; if (h == 0) break;
        string blank = "";
        for (int c = 1; c <= w * 4 + 2; ++c)
        {
            blank.push_back('0');
        }
        
        vector<string> a(h + 2, "0");
        a[0] = blank;
        for (int y = 1; y <= h; ++y)
        {
            for (int c = 1; c <= w; ++c)
            {
                char in; fin >> in;
                a[y] += t(in);
            }

            a[y] += '0';
        }
        a[h + 1] = blank;
        
        h += 2;
        w = w * 4 + 2;
        
        bfsClear(0, 0, h, w, a);

        // for (int y = 0; y <= h - 1; ++y)
        // {
        //     for (int x = 0; x <= w - 1; ++x)
        //     {
        //         fout << a[y][x];
        //     }
        //     fout << '\n';
        // }
        // fout << '\n';

        string hieroglyphs = "ADJKSW";
        vector<int> out(6, 0);
        for (int y = 0; y <= h - 1; ++y)
        {
            for (int x = 0; x <= w - 1; ++x)
            {
                if (a[y][x] == '1')
                {
                    int _count = dfsCount(y, x, h, w, a);
                    if (_count == 1)
                    {
                        ++out[0];
                    }
                    else if (_count == 5)
                    {
                        ++out[1];
                    }
                    else if (_count == 3)
                    {
                        ++out[2];
                    }
                    else if (_count == 2)
                    {
                        ++out[3];
                    }
                    else if (_count == 4)
                    {
                        ++out[4];
                    }
                    else
                    {
                        ++out[5];
                    }
                }
            }
        }

        fout << "Case " << _case << ": ";
        for (int i = 0; i <= 5; ++i)
        {
            for (int c = 1; c <= out[i]; ++c)
            {
                fout << hieroglyphs[i];
            }
        }
        fout << '\n';
    }
    
    return 0;
}