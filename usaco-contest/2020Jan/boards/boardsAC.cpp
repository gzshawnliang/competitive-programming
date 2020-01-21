#include <bits/stdc++.h>

using namespace std;

ifstream fin("boards.in");
ofstream fout("boards.out");

using ill = long long;

const int inf = INT_MAX / 2;

int disfUV(int u, int v, vector<pair<int, int>> &itp)
{
    return abs(itp[u].first - itp[v].first) + abs(itp[u].second - itp[v].second);
}

main()
{
    int xye; fin >> xye;

    set<pair<int, int>> p;
    p.insert({0, 0}); p.insert({xye, xye});

    int cfp; fin >> cfp;
    vector<pair<pair<int, int>, pair<int, int>>> qs;
    for (int c = 1; c <= cfp; ++c)
    {
        pair<int, int> a, b;
        fin >> a.first >> a.second >> b.first >> b.second;

        p.insert(a); p.insert(b);

        qs.push_back({a, b});
    }

    int n = 0;
    vector<pair<int, int>> itp;
    map<pair<int, int>, int> pti;
    for (auto ite = p.begin(); ite != p.end(); ++ite)
    {
        itp.push_back(*ite); pti[*ite] = n;
        ++n;
    }

    vector<int> jum(n, -1);
    for (auto ite = qs.begin(); ite != qs.end(); ++ite)
    {
        jum[pti[ite->first]] = pti[ite->second];
    }

    vector<int> dp(n, inf); dp[0] = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n - 1; ++j)
        {
            dp[j] = min(dp[j], dp[i] + disfUV(i, j, itp));
        }

        if (jum[i] > 0 && jum[i] <= n) dp[jum[i]] = dp[i];
    }

    fout << dp[n - 1] << '\n';

    return 0;
}