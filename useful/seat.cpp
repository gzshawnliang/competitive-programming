#include <bits/stdc++.h>

using namespace std;

ifstream fin("seat.in");
ofstream fout("seat.out");

const int yt = 4, xt = 3, st = yt * xt;

const bool brick2canTurn = false;

struct brick
{
    int y;
    int x;
    string type;
};
brick _brick(int y, int x, string type)
{
    brick temp{y, x, type}; return temp;
}

struct student
{
    string name;
    int team;
};
student _student(string name, int team)
{
    student temp{name, team}; return temp;
}

int main()
{
    vector<student> theClass;

    theClass.push_back(_student("c1", 0));
    theClass.push_back(_student("c2", 0));
    theClass.push_back(_student("c3", 0));
    theClass.push_back(_student("c4", 0));

    theClass.push_back(_student("a1", 1));
    theClass.push_back(_student("a2", 1));

    theClass.push_back(_student("b3", 2));
    theClass.push_back(_student("b4", 2));

    theClass.push_back(_student("f3", 3));
    theClass.push_back(_student("f4", 3));

    theClass.push_back(_student("d4", 4));

    theClass.push_back(_student("e4", 5));

    int size = theClass.size();
    vector<int> typeCount(5, 0), groupCount(st + 1, 0);
    for (int i = 0; i <= size - 1; ++i)
    {
        ++groupCount[theClass[i].team];
    }

    for (int i = 0; i <= st; ++i)
    {
        ++typeCount[groupCount[i]];
    }

    int n = (1 << st);

    static vector<brick> dp[yt + 1]
                    [xt + 1]
                    [st / 1 + 1]
                    [st / 2 + 1]
                    [st / 4 + 1];

    dp[1][1][1][0][0].push_back(_brick(0, 0, "1x1"));
    dp[1][2][0][1][0].push_back(_brick(0, 0, "1x2"));
    if (brick2canTurn == true) dp[2][1][0][1][0].push_back(_brick(0, 0, "2x1"));
    dp[2][2][0][0][1].push_back(_brick(0, 0, "2x2"));

    for (int y = 1; y <= yt; ++y)
    {
        for (int x = 1; x <= xt; ++x)
        {
            for (int c1 = 0; c1 <= typeCount[1]; ++c1)
            {
                for (int c2 = 0; c2 <= typeCount[2]; ++c2)
                {
                    for (int c4 = 0; c4 <= typeCount[4]; ++c4)
                    {
                        if (dp[y][x][c1][c2][c4].size() > 0)
                        {
                            if (y == 4 && x == 2 && c1 == 2 && c2 == 1 && c4 == 1)
                            {
                                for (int __s = 0; __s == 0; ++__s);
                            }

                            if (c1 + y <= typeCount[1] && x + 1 <= xt)
                            {
                                dp[y][x + 1][c1 + y][c2][c4] = dp[y][x][c1][c2][c4];
                                for (int p = 0; p <= y - 1; ++p)
                                {
                                    dp[y][x + 1][c1 + y][c2][c4].push_back(_brick(p, x, "1x1"));
                                }
                            }

                            if (c1 + x <= typeCount[1] && y + 1 <= yt)
                            {
                                dp[y + 1][x][c1 + x][c2][c4] = dp[y][x][c1][c2][c4];
                                for (int p = 0; p <= x - 1; ++p)
                                {
                                    dp[y + 1][x][c1 + x][c2][c4].push_back(_brick(y, p, "1x1"));
                                }
                            }

                            if (c2 + y <= typeCount[2] && x + 2 <= xt)
                            {
                                dp[y][x + 2][c1][c2 + y][c4] = dp[y][x][c1][c2][c4];
                                for (int p = 0; p <= y - 1; ++p)
                                {
                                    dp[y][x + 2][c1][c2 + y][c4].push_back(_brick(p, x, "1x2"));
                                }
                            }

                            if (c2 + x / 2 <= typeCount[2] && y + 1 <= yt && x % 2 == 0)
                            {
                                dp[y + 1][x][c1][c2 + x / 2][c4] = dp[y][x][c1][c2][c4];
                                for (int p = 0; p <= x - 1; p += 2)
                                {
                                    dp[y + 1][x][c1][c2 + x / 2][c4].push_back(_brick(y, p, "1x2"));
                                }
                            }

                            if (brick2canTurn == true)
                            {
                                if (c2 + y / 2 <= typeCount[2] && x + 1 <= xt && y % 2 == 0)
                                {
                                    dp[y][x + 1][c1][c2 + y / 2][c4] = dp[y][x][c1][c2][c4];
                                    for (int p = 0; p <= y - 1; p += 2)
                                    {
                                        dp[y][x + 1][c1][c2 + y / 2][c4].push_back(_brick(p, x, "2x1"));
                                    }
                                }

                                if (c2 + x <= typeCount[2] && y + 2 <= yt)
                                {
                                    dp[y + 2][x][c1][c2 + x][c4] = dp[y][x][c1][c2][c4];
                                    for (int p = 0; p <= x - 1; ++p)
                                    {
                                        dp[y + 2][x][c1][c2 + x][c4].push_back(_brick(y, p, "2x1"));
                                    }
                                }
                            }

                            if (c4 + y / 2 <= typeCount[4] && x + 2 <= xt && y % 2 == 0)
                            {
                                dp[y][x + 2][c1][c2][c4 + y / 2] = dp[y][x][c1][c2][c4];
                                for (int p = 0; p <= y - 1; p += 2)
                                {
                                    dp[y][x + 2][c1][c2][c4 + y / 2].push_back(_brick(p, x, "2x2"));
                                }
                            }

                            if (c4 + x / 2 <= typeCount[4] && y + 2 <= yt && x % 2 == 0)
                            {
                                dp[y + 2][x][c1][c2][c4 + x / 2] = dp[y][x][c1][c2][c4];
                                for (int p = 0; p <= x - 1; p += 2)
                                {
                                    dp[y + 2][x][c1][c2][c4 + x / 2].push_back(_brick(y, p, "2x2"));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int y = 1; y <= yt; ++y)
    {
        for (int x = 1; x <= xt; ++x)
        {
            for (int c1 = 0; c1 <= typeCount[1]; ++c1)
            {
                for (int c2 = 0; c2 <= typeCount[2]; ++c2)
                {
                    for (int c4 = 0; c4 <= typeCount[4]; ++c4)
                    {
                        if (dp[y][x][c1][c2][c4].size() > 0)
                        {
                            fout << "dp[" << y << "][" << x << "] [" << c1 << "][" << c2 << "][" << c4 << "]: ";

                            bool first = true;
                            for (auto k : dp[y][x][c1][c2][c4])
                            {
                                if (first == true) first = false;
                                else fout << ", ";

                                fout << '(' << k.y << ", " << k.x << ')' << ' ' << k.type;
                            }
                            fout << '\n';
                        }
                    }
                }
            }
        }
    }

    return 0;
}
