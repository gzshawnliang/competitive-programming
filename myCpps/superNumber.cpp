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
#include <ctime>

using namespace std;

ifstream fin("superNumber.in");
ofstream fout("superNumber.out");

int divide(vector<int> & a, int b)
{
    int size = a.size(), last = 0, pos = 0;
    while (pos <= size - 1)
    {
        int nowNum = a[pos] + last * 10;
        if (nowNum >= b)
        {
            last = nowNum % b;
        }
        else if (pos <= size - 2)
        {
            nowNum = a[pos + 1] + a[pos] * 10 + last * 100;
            if (nowNum >= b)
            {
                last = nowNum % b;
                ++pos;
            }
            else if (pos <= size - 3)
            {
                nowNum = a[pos + 2] + a[pos + 1] * 10 + a[pos] * 100;
                last = nowNum % b;
                pos += 2;
            }
            else
            {
                return nowNum % b;
            }
        }
        else
        {
            return nowNum % b;
        }
        ++pos;
    }

    return last % b;
}

vector<int> ans;
void solve(vector<int> a, int n, int m, int now)
{
    int size = a.size();

    if (ans.size() != 0)
    {
        return;
    }
    else if (now == m + 1)
    {
        ans = a;
    }
    else if (now < n)
    {
        if (now == 1)
        {
            for (int i = 1; i <= 9; ++i)
            {
                vector<int> temp0 = a;
                temp0.push_back(i);
                solve(temp0, n, m, now + 1);
            }
        }
        else
        {
            for (int i = 0; i <= 9; ++i)
            {
                vector<int> temp0 = a;
                temp0.push_back(i);
                solve(temp0, n, m, now + 1);
            }
        }
    }
    else if (a.size() == 0)
    {
        for (int i = 1; i <= 9; ++i)
        {
            vector<int> temp0;
            temp0.push_back(i);
            solve(temp0, n, m, now + 1);
        }
    }
    else
    {
        vector<int> temp0 = a;
        temp0.push_back(0);
        int left = divide(temp0, now);
        int want = 0;
        while (true)
        {
            if (want - left < 0)
            {
                // Do nothing
            }
            else if (want - left > 9)
            {
                break;
            }
            else
            {
                vector<int> temp1 = a;
                temp1.push_back(want - left);
                solve(temp1, n, m, now + 1);
            }
            want += now;
        }
    }
}

int main()
{
    int count0;
    fin >> count0;
    for (int c = 1; c <= count0; ++c)
    {
        ans.clear();
        int n, m;
        fin >> n >> m;

        vector<int> temp;
        solve(temp, n, m, 1);
        if (ans.size() == 0)
        {
            fout << "Case " << c << ": -1\n";
        }
        else
        {
            fout << "Case " << c << ": ";
            int size = ans.size();
            for (int i = 0; i <= size - 1; ++i)
            {
                fout << ans[i];
            }
            fout << '\n';
        }
    }

    return 0;
}