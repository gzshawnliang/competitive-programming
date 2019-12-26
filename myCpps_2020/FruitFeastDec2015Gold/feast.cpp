#include <bits/stdc++.h>

using namespace std;

ifstream fin("feast.in");
ofstream fout("feast.out");

const int maxT = 5000000 + 1;

int main()
{
    int t, a, b; fin >> t >> a >> b;

    bitset<maxT> f(0);

    f[0] = 1;
    for (int i = 0; i <= t; ++i)
    {
        if (f[i] == 1)
        {
            f[i / 2] = 1;

            if (i + a <= t) f[i + a] = 1;
            if (i + b <= t) f[i + b] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i <= t; ++i)
    {
        if (f[i] == 1)
        {
            ans = i;

            if (i + a <= t) f[i + a] = 1;
            if (i + b <= t) f[i + b] = 1;
        }
    }

    fout << ans << '\n';

    return 0;
}
