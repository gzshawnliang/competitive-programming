#include <bits/stdc++.h>

using namespace std;

ofstream fout("simpleMindedHashing_UVA10912.in");

const int maxL = 26, maxS = 351, n = 26;

int main()
{
    for (int i = 1; i <= maxL; ++i)
    {
        for (int j = (i + 1) * i / 2; j <= maxS; ++j)
        {
            fout << i << ' ' << j << '\n';
        }
    }
    fout << "0 0\n";

    return 0;
}
