#include <bits/stdc++.h>

using namespace std;

ofstream fout("theGreatEscape_UVA10967.in");

const int tcc = 1000;

long long getRand(long long l, long long r)
{
    return (rand() % (r - l + 1)) + l;
}

int main()
{
    srand(time(0));
    string pool = "............#NESW";

    int size = pool.size();

    fout << tcc << '\n';
    
    for (int t = 1; t <= tcc; ++t)
    {
        int n = getRand(4, 5),
            m = getRand(4, 5);

        fout << n << ' ' << m << '\n';

        int dc = 0;
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                char nowC = pool[getRand(0, size - 1)];
                if ((y == 0 && x == m - 1) || (y == n - 1 && x == 0))
                {
                    nowC = '.';
                }

                fout << nowC;

                if (nowC != '.' && nowC != '#')
                {
                    ++dc;
                }
            }
            fout << '\n';
        }

        for (int c = 1; c <= dc; ++c)
        {
            if (c > 1) fout << ' ';
            fout << getRand(1, 9);
        }
        fout << '\n';
    }

    return 0;
}
