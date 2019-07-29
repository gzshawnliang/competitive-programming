#include <bits/stdc++.h>

using namespace std;

ifstream fin("theTollRevisited_UVA10537.in");
ofstream fout("theTollRevisited_UVA10537.out");

const long long N = 52, inf = LLONG_MAX / 2;

long long ctoi(char ch)
{
    if ('A' <= ch && ch <= 'Z') return (ch - 'A');
    else return (ch - 'a') + 26;
}

char itoc(long long x)
{
    if (x <= 25)
    {
        char ch = 'A' + x;
        return ch;
    }
    else
    {
        char ch = 'a' + (x - 26);
        return ch;
    }
}

struct segment
{
    long long u;
    long long lastU;
    long long t;

    bool operator < (const segment & temp) const
    {
        if (t != temp.t) return t > temp.t;
        else if (u != temp.u) return u > temp.u;
        else return lastU > temp.lastU;
    }
};
segment _segment(long long u, long long lastU, long long t)
{
    segment temp{u, lastU, t}; return temp;
}

int main()
{
    long long _t = 0;
    while (true)
    {
        long long m = -1; fin >> m;
        if (m == -1) break;

        ++_t;

        vector<vector<long long>> g(N);
        for (long long c = 1; c <= m; ++c)
        {
            char u_c, v_c; fin >> u_c >> v_c;
            long long u = ctoi(u_c), v = ctoi(v_c);
            g[u].push_back(v); g[v].push_back(u);
        }

        char s_c, e_c;
        long long p;
        fin >> p >> s_c >> e_c;
        long long s = ctoi(s_c), e = ctoi(e_c);

        vector<long long> dp(N, inf), f(N, inf);
        priority_queue<segment> pq; pq.push(_segment(e, -1, p));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.t >= dp[now.u]) continue;
            else if (now.lastU >= f[now.u]) continue;
            
            dp[now.u] = now.t;
            f[now.u] = now.lastU; 

            if (now.u == s)
            {
                break;
            }

            long long size = g[now.u].size();
            for (long long i = 0; i <= size - 1; ++i)
            {
                long long v = g[now.u][i], nextT = 0;;

                if (now.u <= 25)
                {
                    double nextT_D = (double)now.t / 19.0 * 20.0;
                    nextT = ceil(nextT_D);
                }
                else
                {
                    nextT = now.t + 1;
                }
                
                pq.push(_segment(v, now.u, nextT));
            }
        }

        fout << "Case " << _t << ":\n";
        fout << dp[s] << '\n';

        long long u = s;

        fout << itoc(u);
        while (f[u] != -1)
        {
            u = f[u];
            fout << '-' << itoc(u);
        }
        fout << '\n';
    }

    return 0;
}
