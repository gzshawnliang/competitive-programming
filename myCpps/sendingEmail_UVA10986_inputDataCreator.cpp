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

ofstream fout("sendingEmail_UVA10986.in");

const int N = 20000;
const int M = 50000;

int genRand()
{
    //要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
    return (rand() % (9 - 0 + 1)) + 0;
}

int genRand2(int b,int a)
{
    //要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
    return (rand() % (b - a + 1)) + a;
}

int main()
{
    srand(time(NULL));

    fout << "1\n" << N << ' ' << M << genRand2(N,0) << genRand2(M,0) << '\n';
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