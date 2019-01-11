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

ifstream fin("largestBlock.in");
ofstream fout("largestBlock.out");

struct block
{
    int r1;
    int c1;
    int r2;
    int c2;
};

bool g(int y1, int x1, int y2, int x2, block & b)
{
    if (y1 <= b.r1 && b.r1 <= y2 && x1 <= b.c1 && b.c1 <= x2)
    {
        return false;
    }
    else if (y1 <= b.r1 && b.r1 <= y2 && x1 <= b.c2 && b.c2 <= x2)
    {
        return false;
    }
    else if (y1 <= b.r2 && b.r2 <= y2 && x1 <= b.c1 && b.c1 <= x2)
    {
        return false;
    }
    else if (y1 <= b.r2 && b.r2 <= y2 && x1 <= b.c2 && b.c2 <= x2)
    {
        return false;
    }
    else if (b.r1 <= y1 && b.r2 >= y2 && x1 <= b.c1 && b.c1 <= x2)
    {
        return false;
    }
    else if (b.r1 <= y1 && b.r2 >= y2 && x1 <= b.c2 && b.c2 <= x2)
    {
        return false;
    }
    else if (b.c1 <= x1 && b.c2 >= x2 && y1 <= b.r1 && b.r1 <= y2)
    {
        return false;
    }
    else if (b.c1 <= x1 && b.c2 >= x2 && y1 <= b.r2 && b.r2 <= y2)
    {
        return false;
    }

    return true;
}

int main()
{
    int testCase;
    fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int s, n;
        fin >> s >> n;
        vector<block> blocks(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            int a, b, c, d;
            fin >> a >> b >> c >> d;
            blocks[i].r1 = min(a, c);
            blocks[i].c1 = min(b, d);
            blocks[i].r2 = max(a, c);
            blocks[i].c2 = max(b, d);
        }

        int maxSize = 1;
        for (int y1 = 1; y1 <= s; ++y1)
        {
            for (int x1 = 1; x1 <= s; ++x1)
            {
                for (int y2 = y1; y2 <= s; ++y2)
                {
                    for (int x2 = x1; x2 <= s; ++x2)
                    {
                        bool ok = true;
                        for (int i = 0; i <= n - 1; ++i)
                        {
                            if (g(y1,x1,y2,x2,blocks[i]) == false)
                            {
                                ok = false;
                                break;
                            }
                        }

                        if (ok == true)
                        {
                            int size = (y2 - y1 + 1) * (x2 - x1 + 1);
                            
                            if (size > maxSize)
                            {
                                maxSize = size;
                                //fout << "*   " << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << '\n';
                            }
                        }
                    }
                }
            }
        }

        fout << maxSize << '\n';
    }

    return 0;
}