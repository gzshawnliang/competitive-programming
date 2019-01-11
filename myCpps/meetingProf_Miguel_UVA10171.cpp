#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("meetingProf_Miguel_UVA10171.in");
ofstream fout("meetingProf_Miguel_UVA10171.out");

const int INF = 1000000;

struct place
{
    char u;
    int W;

    bool operator < (const place temp) const
    {
        if (W == temp.W)
        {
            return u < temp.u;
        }
        else
        {
            return W < temp.W;
        }
    }
};

void trans(int & n, char chr, vector<int> & ctoi, vector<char> & itoc)
{
    if (ctoi[chr - 'A'] == -1)
    {
        ++n;
        ctoi[chr - 'A'] = n;
        itoc[n] = chr;
    }
}

int main()
{
    while (true)
    {
        int n = -1, m = 0; fin >> m;
        if (m == 0) break;
        
        vector<int> ctoi(26, -1);
        vector<char> itoc(26);
        vector<vector<int>> a0(26, vector<int>(26, INF)), a1(26, vector<int>(26, INF));
        for (int c = 1; c <= m; ++c)
        {
            char t0, t1, u, v;
            int w; fin >> t0 >> t1 >> u >> v >> w;
            trans(n, u, ctoi, itoc); trans(n, v, ctoi, itoc);

            if (t0 == 'Y')
            {
                a0[ctoi[u - 'A']][ctoi[v - 'A']] = w;
                if (t1 == 'B')
                {
                    a0[ctoi[v - 'A']][ctoi[u - 'A']] = w;
                }
            }
            else
            {
                a1[ctoi[u - 'A']][ctoi[v - 'A']] = w;
                if (t1 == 'B')
                {
                    a1[ctoi[v - 'A']][ctoi[u - 'A']] = w;
                }
            }
        }
        char ts, td; fin >> ts >> td;
        trans(n, ts, ctoi, itoc); trans(n, td, ctoi, itoc);
        int s = ctoi[ts - 'A'], d = ctoi[td - 'A'];
        ++n;

        vector<int> dis0(n, INF), dis1(n, INF);
        vector<bool> vis0(n, false), vis1(n, false);
        vis0[s] = true; vis1[d] = true;
        for (int i = 0; i <= n - 1; ++i)
        {
            a0[i][i] = 0; a1[i][i] = 0;
            dis0[i] = a0[s][i]; dis1[i] = a1[d][i];
        }

        for (int c = 1; c <= n - 1; ++c)
        {
            int _min0 = INF, u0;
            int _min1 = INF, u1;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (vis0[i] == false && dis0[i] < _min0)
                {
                    _min0 = dis0[i]; u0 = i;
                }

                if (vis1[i] == false && dis1[i] < _min1)
                {
                    _min1 = dis1[i]; u1 = i;
                }
            }

            vis0[u0] = true;
            vis1[u1] = true;
            for (int v = 0; v <= n - 1; ++v)
            {
                if (a0[u0][v] != INF)
                {
                     dis0[v] = min(dis0[v], dis0[u0] + a0[u0][v]);
                }

                if (a1[u1][v] != INF)
                {
                    dis1[v] = min(dis1[v], dis1[u1] + a1[u1][v]);
                }
            }
        }

        vector<place> p;
        for (int i = 0; i <= n - 1; ++i)
        {
            place temp{itoc[i], dis0[i] + dis1[i]};
            p.push_back(temp);
        }
        sort(p.begin(), p.end());

        if (p[0].W >= INF)
        {
            fout << "You will never meet.\n";
            continue;
        }

        fout << p[0].W << ' ' << p[0].u;

        int i = 1, size = p.size();
        while (p[i].W == p[i - 1].W && i <= size - 1)
        {
            fout << ' ' << p[i].u;
            ++i;
        }

        fout << '\n';
    }

    return 0;
}