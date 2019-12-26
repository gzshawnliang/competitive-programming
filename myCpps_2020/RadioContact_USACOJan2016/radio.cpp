#include <bits/stdc++.h>

using namespace std;

ifstream fin("radio.in");
ofstream fout("radio.out");

const int inf = INT_MAX / 2;

int disPow2(pair<int, int> &a, pair<int, int> &b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
    int n, m; fin >> n >> m;
    vector<pair<int, int>> p1(n + 1), p2(m + 1);

    fin >> p1[0].first >> p1[0].second >> p2[0].first >> p2[0].second;

    for (int i = 1; i <= n; ++i)
    {
        char ch; fin >> ch;
        if      (ch == 'N')
        {
            p1[i].first = p1[i - 1].first;
            p1[i].second = p1[i - 1].second + 1;
        }
        else if (ch == 'E')
        {
            p1[i].first = p1[i - 1].first + 1;
            p1[i].second = p1[i - 1].second;
        }
        else if (ch == 'S')
        {
            p1[i].first = p1[i - 1].first;
            p1[i].second = p1[i - 1].second - 1;
        }
        else if (ch == 'W')
        {
            p1[i].first = p1[i - 1].first - 1;
            p1[i].second = p1[i - 1].second;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        char ch; fin >> ch;
        if      (ch == 'N')
        {
            p2[i].first = p2[i - 1].first;
            p2[i].second = p2[i - 1].second + 1;
        }
        else if (ch == 'E')
        {
            p2[i].first = p2[i - 1].first + 1;
            p2[i].second = p2[i - 1].second;
        }
        else if (ch == 'S')
        {
            p2[i].first = p2[i - 1].first;
            p2[i].second = p2[i - 1].second - 1;
        }
        else if (ch == 'W')
        {
            p2[i].first = p2[i - 1].first - 1;
            p2[i].second = p2[i - 1].second;
        }
    }

    vector<vector<int>> f(n + 1, vector<int>(m + 1, inf));
    
    f[0][0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + disPow2(p1[i], p2[j]));
            if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + disPow2(p1[i], p2[j]));
            if (i > 0 && j > 0) f[i][j] = min(f[i][j], f[i - 1][j - 1] + disPow2(p1[i], p2[j]));
        }
    }

    fout << f[n][m] << '\n';

    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= m; ++j)
    //     {
    //         fout << "f[" << i << "][" << j << "] = " << f[i][j] << '\n';
    //     }
    // }

    return 0;
}
