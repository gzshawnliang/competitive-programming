#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

ofstream fout("numberMaze_UVA929.in");

const int N = 999;
const int M = 999;

int genRand()
{
    //要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
    return (rand() % (9 - 0 + 1)) + 0;
}

int main()
{
    srand(time(NULL));

    fout << "1\n" << N << ' ' << M << '\n';
    for (int c0 = 1; c0 <= N; ++c0)
    {
        for (int c1 = 1; c1 <= M; ++c1)
        {
            if (c1 > 1)
            {
                fout << ' ';
            }
            fout << genRand();
        }
        fout << '\n';
    }

    return 0;
}