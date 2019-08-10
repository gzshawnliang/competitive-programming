#include <bits/stdc++.h>

using namespace std;

ofstream fout("aWalkThroughTheForest_UVA10917.in");

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
}

int main()
{
    int n = 5,
        m = 7,
        maxL = 20,
        tct = 100;

    for (int t = 1; t <= tct; ++t)
    {
        fout << n << ' ' << m << '\n';

        map<string, int> paths;
        for (int c = 1; c <= m; ++c)
        {
            int u = 0, v = 0;
            while (true)
            {
                u = getRand(1, n);
                v = getRand(1, n);

                string key0 = to_string(u) + " " + to_string(v),
                    key1 = to_string(v) + " " + to_string(u);

                if (u != v && paths.count(key0) == 0 && paths.count(key1) == 0)
                {
                    paths[key0] = 1;
                    paths[key1] = 1;

                    break;
                }
            }

            fout << u << ' ' << v << ' ' << getRand(1, maxL) << '\n';
        }
    }

    fout << "0\n";

    return 0;
}
