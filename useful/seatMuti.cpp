#include <bits/stdc++.h>

using namespace std;

ifstream fin("seat.in");
ofstream fout("seat.out");

const int yt = 5, xt = 6, st = yt * xt;

const bool brick2canTurn = true;

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
}

template <typename any>
void shuffle(int count, vector<any> & a)
{
    int size = a.size();
    for (int c = 1; c <= count; ++c)
    {
        swap(a[getRand(0, size - 1)], a[getRand(0, size - 1)]);
    }
}

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

void spaceOut(int sml, string & s)
{
    int size = s.size();
    fout << s;
    for (int c = 1; c <= sml - size; ++c) fout << ' ';
}

int main()
{
    srand(time(0));

    int sml = 0;
    vector<vector<vector<string>>> a(5);

    while (true)
    {
        string in = ""; getline(fin, in);
        if (in == "") break;

        stringstream gin(in);
        vector<string> res;

        while (true)
        {
            string temp = ""; gin >> temp;
            if (temp == "") break;

            sml = max(sml, (int)temp.size());

            res.push_back(temp);
        }

        a[res.size()].push_back(res);
    }

    // vector<string> a40 = {"a1","a2","a3","a4"};
    // a[4].push_back(a40);

    // vector<string> a20 = {"b1","b2"};
    // a[2].push_back(a20);

    // vector<string> a21 = {"c1","c2"};
    // a[2].push_back(a21);

    // vector<string> a22 = {"d1","d2"};
    // a[2].push_back(a22);

    // vector<string> a10 = {"e1"};
    // a[1].push_back(a10);

    // vector<string> a11 = {"f1"};
    // a[1].push_back(a11);

    vector<int> typeCount(5, 0);
    for (int c = 1; c <= 4; ++c)
    {
        typeCount[c] = a[c].size();
    }

    static vector<vector<brick>> dp[yt + 1]
                                 [xt + 1]
                                 [st / 1 + 1]
                                 [st / 2 + 1]
                                 [st / 4 + 1];

    vector<brick> temp;

    temp.clear(); temp.push_back(_brick(0, 0, "1x1"));
    dp[1][1][1][0][0].push_back(temp);

    temp.clear(); temp.push_back(_brick(0, 0, "1x2"));
    dp[1][2][0][1][0].push_back(temp);

    if (brick2canTurn == true)
    {
        temp.clear(); temp.push_back(_brick(0, 0, "2x1"));
        dp[2][1][0][1][0].push_back(temp);
    }

    temp.clear(); temp.push_back(_brick(0, 0, "2x2"));
    dp[2][2][0][0][1].push_back(temp);

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
                            int size = dp[y][x][c1][c2][c4].size();

                            for (int i = 0; i <= size - 1; ++i)
                            {
                                vector<brick> now = dp[y][x][c1][c2][c4][i];

                                if (y == 4 && x == 2 && c1 == 2 && c2 == 1 && c4 == 1)
                                {
                                    for (int __s = 0; __s == 0; ++__s);
                                }

                                if (c1 + y <= typeCount[1] && x + 1 <= xt)
                                {
                                    temp.clear(); temp = now;
                                    for (int p = 0; p <= y - 1; ++p)
                                    {
                                        temp.push_back(_brick(p, x, "1x1"));
                                    }

                                    dp[y][x + 1][c1 + y][c2][c4].push_back(temp);
                                }

                                if (c1 + x <= typeCount[1] && y + 1 <= yt)
                                {
                                    temp.clear(); temp = now;
                                    for (int p = 0; p <= x - 1; ++p)
                                    {
                                        temp.push_back(_brick(y, p, "1x1"));
                                    }

                                    dp[y + 1][x][c1 + x][c2][c4].push_back(temp);
                                }

                                if (c2 + y <= typeCount[2] && x + 2 <= xt)
                                {
                                    temp.clear(); temp = now;
                                    for (int p = 0; p <= y - 1; ++p)
                                    {
                                        temp.push_back(_brick(p, x, "1x2"));
                                    }
                                    dp[y][x + 2][c1][c2 + y][c4].push_back(temp);
                                }

                                if (c2 + x / 2 <= typeCount[2] && y + 1 <= yt && x % 2 == 0)
                                {
                                    temp.clear(); temp = now;
                                    for (int p = 0; p <= x - 1; p += 2)
                                    {
                                        temp.push_back(_brick(y, p, "1x2"));
                                    }
                                    dp[y + 1][x][c1][c2 + x / 2][c4].push_back(temp);
                                }

                                if (brick2canTurn == true)
                                {
                                    if (c2 + y / 2 <= typeCount[2] && x + 1 <= xt && y % 2 == 0)
                                    {
                                        temp.clear(); temp = now;
                                        for (int p = 0; p <= y - 1; p += 2)
                                        {
                                            temp.push_back(_brick(p, x, "2x1"));
                                        }
                                        dp[y][x + 1][c1][c2 + y / 2][c4].push_back(temp);
                                    }

                                    if (c2 + x <= typeCount[2] && y + 2 <= yt)
                                    {
                                        temp.clear(); temp = now;
                                        for (int p = 0; p <= x - 1; ++p)
                                        {
                                            temp.push_back(_brick(y, p, "2x1"));
                                        }
                                        dp[y + 2][x][c1][c2 + x][c4].push_back(temp);
                                    }
                                }

                                if (c4 + y / 2 <= typeCount[4] && x + 2 <= xt && y % 2 == 0)
                                {
                                    temp.clear(); temp = now;
                                    for (int p = 0; p <= y - 1; p += 2)
                                    {
                                        temp.push_back(_brick(p, x, "2x2"));
                                    }
                                    dp[y][x + 2][c1][c2][c4 + y / 2].push_back(temp);
                                }

                                if (c4 + x / 2 <= typeCount[4] && y + 2 <= yt && x % 2 == 0)
                                {
                                    temp.clear(); temp = now;
                                    for (int p = 0; p <= x - 1; p += 2)
                                    {
                                        temp.push_back(_brick(y, p, "2x2"));
                                    }
                                    dp[y + 2][x][c1][c2][c4 + x / 2].push_back(temp);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // for (int y = 1; y <= yt; ++y)
    // {
    //     for (int x = 1; x <= xt; ++x)
    //     {
    //         for (int c1 = 0; c1 <= typeCount[1]; ++c1)
    //         {
    //             for (int c2 = 0; c2 <= typeCount[2]; ++c2)
    //             {
    //                 for (int c4 = 0; c4 <= typeCount[4]; ++c4)
    //                 {
    //                     if (dp[y][x][c1][c2][c4].size() > 0)
    //                     {
    //                         fout << "dp[" << y << "][" << x << "] [" << c1 << "][" << c2 << "][" << c4 << "]:\n";

    //                         int size = dp[y][x][c1][c2][c4].size();
    //                         for (int i = 0; i <= size - 1; ++i)
    //                         {
    //                             fout << "   #" << i << ": ";

    //                             bool first = true;
    //                             for (auto k : dp[y][x][c1][c2][c4][i])
    //                             {
    //                                 if (first == true) first = false;
    //                                 else fout << ", ";

    //                                 fout << '(' << k.y << ", " << k.x << ')' << ' ' << k.type;
    //                             }
    //                             fout << '\n';
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    vector<vector<brick>> ans = dp[yt][xt][typeCount[1]][typeCount[2]][typeCount[4]];
    int sizeAns = ans.size();

    for (int _i = 0; _i <= sizeAns - 1; ++_i)
    {
        vector<brick> final = ans[_i];
        int sizeFinal = final.size();
        vector<vector<string>> g(yt, vector<string>(xt, "~"));

        for (int c = 1; c <= 4; ++c)
        {
            if (c == 3 || a[c].size() == 0) continue;
            shuffle(500, a[c]);
        }

        vector<int> is(5, 0);
        vector<vector<string>> out(yt, vector<string>(xt));
        for (int i = 0; i <= sizeFinal - 1; ++i)
        {
            brick nowBrick = final[i];
            int y = nowBrick.y, x = nowBrick.x;

            if (nowBrick.type == "1x1")
            {
                vector<string> nowG = a[1][is[1]];
                //shuffle(20, nowG);

                out[y][x] = nowG[0];

                ++is[1];
            }
            else if (nowBrick.type == "1x2")
            {
                vector<string> nowG = a[2][is[2]];
                shuffle(20, nowG);

                out[y][x] = nowG[0];
                out[y][x + 1] = nowG[1];

                ++is[2];
            }
            else if (nowBrick.type == "2x1")
            {
                vector<string> nowG = a[2][is[2]];
                shuffle(20, nowG);

                out[y][x] = nowG[0];
                out[y + 1][x] = nowG[1];

                ++is[2];
            }
            else if (nowBrick.type == "2x2")
            {
                vector<string> nowG = a[4][is[4]];
                shuffle(20, nowG);

                out[y][x] = nowG[0];
                out[y][x + 1] = nowG[1];
                out[y + 1][x] = nowG[2];
                out[y + 1][x + 1] = nowG[3];

                ++is[4];
            }
        }

        // if
        // (
        //     out[2][0] != "Shawn" &&
        //     out[2][1] != "Shawn" &&
        //     out[2][2] != "Shawn" &&
        //     out[2][3] != "Shawn" &&
        //     out[2][4] != "Shawn" &&
        //     out[2][5] != "Shawn"
        // )
        // {
        //     continue;
        // }

        for (int y = 0; y <= yt - 1; ++y)
        {
            for (int x = 0; x <= xt - 1; ++x)
            {
                if (x > 0) fout << ' ';
                spaceOut(sml, out[y][x]);
            }
            fout << '\n';
        }

        fout << '\n';
    }

    return 0;
}
