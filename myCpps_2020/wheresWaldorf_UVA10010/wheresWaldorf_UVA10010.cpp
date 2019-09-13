#include <bits/stdc++.h>

using namespace std;

ifstream fin("wheresWaldorf_UVA10010.in");
ofstream fout("wheresWaldorf_UVA10010.out");

vector<int> yp = {-1, -1, 0, 1, 1, 1, 0, -1},
            xp = {0, 1, 1, 1, 0, -1, -1, -1};

struct line
{
    int y;
    int x;
    int d;
    string s;
};
line _line(int y, int x, int d, string s)
{
    line temp{y, x, d, s}; return temp;
}

bool isIn(int y, int x, int yn, int xn)
{
    return y >= 0 && y <= yn - 1 && x >= 0 && x <= xn - 1;
}

void add(int y, int x, int yn, int xn, vector<string> & a, vector<line> & g)
{
    for (int d = 0; d <= 7; ++d)
    {
        int tempY = y, tempX = x;

        string res = "";
        while (isIn(tempY, tempX, yn, xn) == true)
        {
            res += a[tempY][tempX];
            tempY += yp[d]; tempX += xp[d];
        }

        if (res.size() > 1)
        {
            g.push_back(_line(y, x, d, res));
        }
    }
}

string ctos(char ch)
{
    string temp = ""; temp += ch;
    return temp;
}

int main()
{
    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int yn, xn; fin >> yn >> xn;
        vector<string> a;

        for (int c = 1; c <= yn; ++c)
        {
            string in; fin >> in;
            a.push_back(in);
        }

        for (int y = 0; y <= yn - 1; ++y)
        {
            for (int x = 0; x <= xn - 1; ++x)
            {
                if ('A' <= a[y][x] && a[y][x] <= 'Z')
                {
                    char ch = 'a' + (a[y][x] - 'A');
                    a[y][x] = ch;
                }
            }
        }

        vector<line> g;
        for (int y = 0; y <= yn - 1; ++y)
        {
            add(y, 0, yn, xn, a, g);
            add(y, xn - 1, yn, xn, a, g);
        }
        for (int x = 0; x <= xn - 1; ++x)
        {
            add(0, x, yn, xn, a, g);
            add(yn - 1, x, yn, xn, a, g);
        }
        g.push_back(_line(0, 0, 0, ctos(a[0][0])));
        g.push_back(_line(0, xn - 1, 0, ctos(a[0][xn - 1])));
        g.push_back(_line(yn - 1, 0, 0, ctos(a[yn - 1][0])));
        g.push_back(_line(yn - 1, xn - 1, 0, ctos(a[yn - 1][xn - 1])));
        int sizeG = g.size();

        int k; fin >> k;
        if (t > 1) fout << '\n';
        for (int c = 1; c <= k; ++c)
        {
            string target; fin >> target;
            int sizeT = target.size();

            for (int it = 0; it <= sizeT - 1; ++it)
            {
                if ('A' <= target[it] && target[it] <= 'Z')
                {
                    char ch = 'a' + (target[it] - 'A');
                    target[it] = ch;
                }
            }

            int _i = 0, _j = -1;
            vector<int> next(sizeT + 1, 0); next[0] = -1;
            while (_i <= sizeT - 1)
            {
                while (_j >= 0 && target[_i] != target[_j])
                {
                    _j = next[_j];
                }

                ++_i; ++_j;
                next[_i] = _j;
            }

            int ansY = yn, ansX = xn;
            for (int ig = 0; ig <= sizeG - 1; ++ig)
            {
                int i = 0,
                    j = 0,
                    tempY = g[ig].y,
                    tempX = g[ig].x,
                    tempD = g[ig].d;
                string s = g[ig].s; int sizeS = s.size();

                if (sizeS < sizeT) continue;

                while (i <= sizeS - 1)
                {
                    while (j >= 0 && s[i] != target[j])
                    {
                        j = next[j];
                    }
                    
                    ++i; ++j;
                    if (j == sizeT)
                    {
                        int pos = i - sizeT,
                            nowY = tempY + pos * yp[tempD],
                            nowX = tempX + pos * xp[tempD];

                        if (nowY < ansY)
                        {
                            ansY = nowY; ansX = nowX;
                        }
                        else if (nowY == ansY && nowX < ansX)
                        {
                            ansY = nowY; ansX = nowX;
                        }

                        j = next[j];
                    }
                }
            }

            fout << ansY + 1 << ' ' << ansX + 1 << '\n';
        }
    }

    return 0;
}
