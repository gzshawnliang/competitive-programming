#include <bits/stdc++.h>

using namespace std;

ofstream fout("cityGame_UVA1330.in");

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
}

int main()
{
    srand(time(0));

    int k = 100, n = 10, m = 10;

    fout << k << '\n'; 
    for (int c = 1; c <= k; ++c)
    {
        fout << n << ' ' << m << '\n';
        for (int y = 1; y <= n; ++y)
        {
            for (int x = 1; x <= m; ++x)
            {
                if (x > 1) fout << ' ';

                if (getRand(1, 4) == 1)
                {
                    fout << 'R';
                }
                else
                {
                    fout << 'F';
                }
            }
            fout << '\n';
        }
    }
    
    return 0;
}
