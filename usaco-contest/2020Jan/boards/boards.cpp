#include <bits/stdc++.h>

using namespace std;

ifstream fin("boards.in");
ofstream fout("boards.out");

using ill = long long;

const int maxP = 100005, inf = INT_MAX / 2;

int disfUV(int u, int v, vector<pair<int, int>> &p)
{
    return abs(p[u].first - p[v].first) + abs(p[u].second - p[v].second);
}

void dijkstra(int rot, vector<int> &jum, vector<int> &dis, set<int> &trueP, vector<pair<int, int>> &p)
{
    dis[rot] = 0;

    set<pair<int, int>> q;
    q.insert(make_pair(0, rot));

    vector<int> vtp;
    for (auto ite = trueP.begin(); ite != trueP.end(); ++ite)
    {
        vtp.push_back(*ite);
    }
    int sizP = vtp.size();

    while (q.empty() == false)
    {
        int u = q.begin()->second;
        q.erase(q.begin());

        int start = upper_bound(vtp.begin(), vtp.end(), u) - vtp.begin();

        for (auto i = start; i <= sizP - 1; ++i)
        {
            int v = vtp[i];

            int l = disfUV(u, v, p);
            if (dis[u] + l < dis[v])
            {
                dis[v] = dis[u] + l;
                q.insert(make_pair(dis[v], v));
            }
        }

        int v = jum[u];
        if (v < 0) continue;

        if (dis[u] < dis[v])
        {
            dis[v] = dis[u];
            q.insert(make_pair(dis[v], v));
        }
    }
}

int main()
{
    int endXY; fin >> endXY;

    int n = 1;
    set<int> trueP;
    vector<pair<int, int>> p(1);
    map<pair<int, int>, int> pmp;
    p[0] = {0, 0}; trueP.insert(0); pmp[{0, 0}] = 0;

    int cfp; fin >> cfp;
    vector<int> jum(maxP + 1, -1);
    
    for (int c = 1; c <= cfp; ++c)
    {
        pair<int, int> a, b;
        fin >> a.first >> a.second >> b.first >> b.second;

        if (pmp.count(a) == 0)
        {
            pmp[a] = n; ++n;
            p.push_back(a);
        }

        if (pmp.count(b) == 0)
        {
            pmp[b] = n; ++n;
            p.push_back(b);
        }

        trueP.insert(pmp[a]);
        jum[pmp[a]] = pmp[b];
    }

    p.push_back({endXY, endXY}); pmp[{endXY, endXY}] = n; ++n;
    trueP.insert(pmp[{endXY, endXY}]);

    vector<int> dis(n, inf);
    dijkstra(pmp[{0, 0}], jum, dis, trueP, p);

    fout << dis.back() << '\n';

    return 0;
}
