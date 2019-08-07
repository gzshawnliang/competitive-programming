#include <bits/stdc++.h>

using namespace std;

ifstream fin("main.in");
ofstream fout("main.out");

const int ny = 6, nx = 6;
const vector<int>   yp = {-1, 0, 1, 0},
                    xp = {0, 1, 0, -1};

vector<int> _vector
(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f
)

{
    vector<int> temp = {a, b, c, d, e, f}; return temp;
}

bool g(int y, int x)
{
    return y >= 0 && y <= ny - 1 && x >= 0 && x <= nx - 1;
}

char ptoc(int y, int x)
{
    char ch = 32 + y * nx + x; return ch;
}

string convert(vector<vector<int>> & a)
{
    string ans = "";
    
    int appleY = -1, appleX = -1;
    for (int y = 0; y <= ny - 1 && appleY < 0; ++y)
    {
        for (int x = 0; x <= nx - 1 && appleY < 0; ++x)
        {
            if (a[y][x] == -1)
            {
                appleY = y; appleX = x;
            }
        }
    }
    if (appleY == -1)
    {
        cout << "No apple...\n";
    }

    int nowY = -1, nowX = -1;
    for (int y = 0; y <= ny - 1 && nowY < 0; ++y)
    {
        for (int x = 0; x <= nx - 1 && nowY < 0; ++x)
        {
            if (a[y][x] == 1)
            {
                nowY = y; nowX = x;
                ans = ptoc(nowY, nowX) + ans;
            }
        }
    }
    if (nowY == -1)
    {
        cout << "No snake...\n";
    }

    int i = 1;
    while (true)
    {
        bool flag = false;

        for (int p = 0; p <= 3; ++p)
        {
            int nextY = nowY + yp[p], nextX = nowX + xp[p];
            
            if (g(nextY, nextX) == true)
            {
                if (a[nextY][nextX] == i + 1)
                {
                    nowY = nextY; nowX = nextX;
                    ans = ptoc(nowY, nowX) + ans;
                    ++i;

                    flag = true;
                }
            }
        }

        if (flag == false)
        {
            break;
        }
    }

    ans = ptoc(appleY, appleX) + ans;
    return ans;
}

int main()
{
    vector<vector<int>> a;
    a.push_back(_vector(0,  0,  0,  0,  0,  0));
    a.push_back(_vector(0,  0,  0,  0,  0,  0));
    a.push_back(_vector(1,  0,  0,  0,  0,  0));
    a.push_back(_vector(2,  3,  4,  0,  0,  0));
    a.push_back(_vector(0,  0,  5,  0,  0,  0));
    a.push_back(_vector(0,  0,  0,  0,  0, -1));

    fout << convert(a) << '\n';

    return 0;
}
