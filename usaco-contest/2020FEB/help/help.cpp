#include <bits/stdc++.h>

using namespace std;

ifstream fin("help.in");
ofstream fout("help.out");

const int N = 100;

int main()
{
    int n; fin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i].first >> a[i].second;
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        f[i][i] = 1;
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i].second < a[j].first)
            {
                f[i][j] = 2; f[j][i] = 2;
            }
            else
            {
                f[i][j] = 1; f[j][i] = 1;
            }
        }
    }

    vector<vector<int>> all(n + 1);
    for (int i = 0; i <= (1 << n); ++i)
    {
        bitset<N> b(i);

        all[b.count()].push_back(i);
    }

    return 0;
}
