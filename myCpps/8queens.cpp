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

using namespace std;

ifstream fin("8queens.in");
ofstream fout("8queens.out");

int Y, X, count2;

bool g(int y, int x)
{
    return y >= 0 && y <= 7 && x >= 0 && x <= 7;
}

void outPut(vector<vector<bool>> a)
{
    for (int y = 0; y <= 7; ++y)
    {
        fout << "\t\t";
        for (int x = 0; x <= 7; ++x)
        {
            if (a[y][x] == true)
            {
                fout << 'O';
            }
            else
            {
                fout << '-';
            }
        }
        fout << '\n';
    }
}

void cross(vector<vector<bool>> & a, int Y, int X)
{
    int tempY, tempX;
    tempY = Y;
    tempX = X;
    while (g(tempY, tempX))
    {
        a[tempY][tempX] = true;
        --tempY;
        ++tempX;
    }

    tempY = Y;
    tempX = X;
    while (g(tempY, tempX))
    {
        a[tempY][tempX] = true;
        ++tempY;
        ++tempX;
    }
    a[Y][X] = false;
}

void solve(vector<vector<bool>> & a, vector<bool> & rows, int nowColumn, vector<int> ans)
{
    if (nowColumn == X)
    {
        vector<int> temp1 = ans;
        temp1.push_back(Y);
        if (a[Y][X] == false)
        {
            solve(a, rows, nowColumn + 1, temp1);
        }
    }
    else if (nowColumn == 8)
    {
        if (count2 <= 9)
        {
            fout << ' ';
        }
        fout << count2 << "     ";
        for (int i = 0; i <= 7; ++i)
        {
            fout << ' ' << ans[i] + 1;
        }
        fout << '\n';

        ++count2;
    }
    else
    {
        for (int y = 0; y <= 7; ++y)
        {
            
            if (rows[y] == false && a[y][nowColumn] == false)
            {
                vector<vector<bool>> temp1 = a;
                vector<bool> temp2 = rows;
                vector<int> temp3 = ans;

                cross(temp1, y, nowColumn);
                temp2[y] = true;
                temp3.push_back(y);
                solve(temp1, temp2, nowColumn + 1, temp3);
            }
        }
    }
}

int main()
{
    int count1;
    fin >> count1;
    for (int i = 1; i <= count1; ++i)
    {
        count2 = 1;
        vector<vector<bool>> a(8, vector<bool>(8, false));
        vector<bool> rows(8, false);
        vector<int> ans;

        fin >> Y >> X;

        --Y; --X;
        rows[Y] = true;

        cross(a, Y, X);

        //outPut(a);

        fout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";

        solve(a, rows, 0, ans);

        if (i != count1)
        {
            fout << '\n';
        }
    }

    return 0;
}