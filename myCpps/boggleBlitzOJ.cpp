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


struct derp
{
    bool operator()(const string &str1, const string &str2)
    {
        if (str1.size() != str2.size())
        {
            return str1.size() < str2.size();
        }
        else
        {
            return str1 < str2;
        }
    }
};

set<string,derp> ans;
int size;

bool g(int y, int x)
{
    return y >= 0 && y <= size - 1 && x >= 0 && x <= size - 1;
}

void find(int y, int x, vector<vector<char> > a, string now)
{
    if (now.size() >= 3)
    {
        ans.insert(now);
    }

    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    if (now == "do")
    {
        cout << "";
    }

    for (int d = 0; d <= 7; ++d)
    {
        int nowY = y + dy[d];
        int nowX = x + dx[d];
        if (g(nowY, nowX) == true)
        {
            char last = *(now.end() - 1);
            char nowChar = a[nowY][nowX];
            
            if (nowChar > last)
            {
                find(nowY, nowX, a, now + nowChar);
            }
        }
    }
}

int main()
{
    int totalTest;
    cin >> totalTest;

    for (int t = 1; t <= totalTest; ++t)
    {
        cin >> size;
        ans.clear();
        vector<vector<char>> a(size, vector<char>(size));
        for (int y = 0; y <= size - 1; ++y)
        {
            for (int x = 0; x <= size - 1; ++x)
            {
                cin >> a[y][x];
            }
        }

        for (int y = 0; y <= size - 1; ++y)
        {
            for (int x = 0; x <= size - 1; ++x)
            {
                string temp = "";
                temp.push_back(a[y][x]);
                find(y, x, a, temp);
            }
        }

        for (auto it = ans.begin(); it != ans.end(); ++it)
        {
            cout << *it << '\n';
        }

        if (t != totalTest)
        {
            cout << '\n';
        }
    }

    return 0;
}
