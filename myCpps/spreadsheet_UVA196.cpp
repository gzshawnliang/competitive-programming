#include <bits/stdc++.h>

using namespace std;

ifstream fin("spreadsheet_UVA196.in");
ofstream fout("spreadsheet_UVA196.out");

const int inf = INT_MAX / 2;

struct pos
{
    int y;
    int x;
};
pos _pos(int y, int x)
{
    pos temp{y, x}; return temp;
}

int getPos_s(string s)
{
    int size = s.size(), ans = 0, x = 1;
    for (int i = size - 1; i >= 0; --i)
    {
        int toi = s[i] - 'A'; ++toi;
        ans += toi * x;

        x *= 26;
    }

    return ans;
}

pos getPos(string s)
{
    int size = s.size();
    string s0 = "", s1 = "";
    for (int i = 0; i <= size - 1; ++i)
    {
        if ('A' <= s[i] && s[i] <= 'Z') s0 += s[i];
        else s1 += s[i];
    }

    return _pos(stoi(s1), getPos_s(s0));
}

int getNum(int y, int x, vector<vector<int>> & a_int, vector<vector<string>> & a_string)
{
    if (a_int[y][x] < inf)
    {
        return a_int[y][x];
    }
    else if (a_string[y][x][0] != '=')
    {
        a_int[y][x] = stoi(a_string[y][x]);
        return a_int[y][x];
    }
    else
    {
        int size = a_string[y][x].size(), ans = 0;
        string temp = "";
        for (int i = 1; i <= size; ++i)
        {
            if (a_string[y][x][i] == '+' || i == size)
            {
                pos now = getPos(temp);
                ans += getNum(now.y, now.x, a_int, a_string);
                temp = "";
            }
            else
            {
                temp += a_string[y][x][i];
            }
        }

        a_int[y][x] = ans;
        return a_int[y][x];
    }
}

int main()
{
    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int xn, yn; fin >> xn >> yn;

        vector<vector<int>> a_int(yn + 1, vector<int>(xn + 1, inf));
        vector<vector<string>> a_string(yn + 1, vector<string>(xn + 1, "-"));
        for (int y = 1; y <= yn; ++y)
        {
            for (int x = 1; x <= xn; ++x)
            {
                fin >> a_string[y][x];
            }
        }

        for (int y = 1; y <= yn; ++y)
        {
            for (int x = 1; x <= xn; ++x)
            {
                if (y == 2 && x == 702)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }

                if (x > 1) fout << ' ';
                int now = getNum(y, x, a_int, a_string);
                fout << now;
            }
            fout << '\n';
        }
    }

    return 0;
}
