#include <bits/stdc++.h>

using namespace std;


struct segment
{
    bool wait;
    int u;
    int f;
    int p;

    bool operator<(const segment & temp) const
    {
        return p > temp.p;
    }
};
segment _segment(bool wait, int u, int f, int p)
{
    segment temp{wait, u, f, p}; return temp;
}

const int inf = INT_MAX / 2;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m; cin >> n >> m;

    vector<int> fp(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> fp[i];
    }

    vector<vector<int>> a(n, vector<int>(n, inf)),
                        g(n);
    for (int c = 1; c <= m; ++c)
    {
        int u, v, d; cin >> u >> v >> d;

        a[u][v] = d; a[v][u] = a[u][v];
        g[u].push_back(v); g[v].push_back(u);
    }

    int que; cin >> que;
    for (int c = 1; c <= que; ++c)
    {
        int fm, s, e; cin >> fm >> s >> e;

        bool isFirst = true;
        vector<vector<int>> pm(n, vector<int>(fm + 1, inf)); pm[s][0] = 0;
        priority_queue<segment> pq; pq.push(_segment(false, s, 0, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.u == 2 && now.f == 7)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            if (now.p >= pm[now.u][now.f] && now.wait == false)
            {
                if (isFirst == true)
                {
                    isFirst = false;
                }
                else
                {
                    continue;
                }
            }

            pm[now.u][now.f] = now.p;
            
            if (now.u == e)
            {
                break;
            }

            int size = g[now.u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g[now.u][i];

                if (now.f >= a[now.u][v])
                {
                    pq.push(_segment(false, v, now.f - a[now.u][v], now.p));
                }
            }

            if (now.wait == false)
            {
                for (int fpl = 1; now.f + fpl <= fm; ++fpl)
                {
                    pq.push(_segment(true, now.u, now.f + fpl, now.p + fp[now.u] * fpl));
                }
            }
        }

        if (pm[e][0] < inf)
        {
            cout << pm[e][0] << '\n';
        }
        else
        {
            cout << "impossible\n";
        }
    }

   	cout.flush();
   	return 0;
}

