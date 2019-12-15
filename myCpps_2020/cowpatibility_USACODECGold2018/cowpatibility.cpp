#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");

const int m = 5, maxN = 50000;

int main()
{
    int n; fin >> n;
    
    map<int, bitset<maxN>> a;
    vector<vector<int>> allFlavor(n, vector<int>(m, 0));
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = 0; j <= m - 1; ++j)
        {
            fin >> allFlavor[i][j];
            a[allFlavor[i][j]][i] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        bitset<maxN> b;
        for (int j = 0; j <= m - 1; ++j)
        {
            b |= a[allFlavor[i][j]];
        }

        ans += (n - b.count());
    }
    ans /= 2;

    fout << ans << '\n';

    return 0;
}
