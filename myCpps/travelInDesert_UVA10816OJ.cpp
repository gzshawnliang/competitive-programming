#include <bits/stdc++.h>

using namespace std;


const int inf = INT_MAX / 2;

struct road
{
    int tem;
    int dis;
};

struct segment
{
    int u;
    int d;
    int lastU;
    int lastJ;

    bool operator < (const segment & temp) const
    {
        return d > temp.d;
    }
};
segment _segment(int u, int d, int lastU, int lastI)
{
    segment temp{u, d, lastU, lastI}; return temp;
}

struct nextNode
{
    int u;
    int j;
};
nextNode _nextNode(int u, int j)
{
    nextNode temp{u, j}; return temp;
}

bool canReach(int mid, int s, int t, vector<nextNode> & f_RETURN, vector<vector<int>> & g, vector<vector<vector<road>>> & a)
{
    int n = g.size() - 1;

    if (mid == 383)
    {
        for (int __s = 0; __s == 0; ++__s);
    }

    vector<int> dp(n + 1, inf);
    priority_queue<segment> pq; pq.push(_segment(s, 0, 0, 0));
    while (pq.empty() == false)
    {
        segment now = pq.top(); pq.pop();

        if (now.d >= dp[now.u])
        {
            continue;
        }

        f_RETURN[now.u] = _nextNode(now.lastU, now.lastJ);
        dp[now.u] = now.d;

        if (now.u == t)
        {
            return true;
        }

        int sizeGnowu = g[now.u].size();
        for (int i = 0; i <= sizeGnowu - 1; ++i)
        {
            int v = g[now.u][i];

            int sizeAnowuv = a[now.u][v].size();
            for (int j = 0; j <= sizeAnowuv - 1; ++j)
            {
                road nowRoad = a[now.u][v][j];

                if (nowRoad.tem > mid)
                {
                    continue;
                }

                pq.push(_segment(v, now.d + nowRoad.dis, now.u, j));
            }
        }
    }

    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(1);

    int tcc = 0;
    while (true)
    {
        int n = 0, m = 0; cin >> n >> m;
        if (n + m == 0) break;

        ++tcc;

        vector<vector<int>> g(n + 1);
        vector<vector<vector<road>>> a(n + 1, vector<vector<road>>(n + 1));

        int s, t; cin >> s >> t;

        int l = 0, r = 0;
        for (int c = 1; c <= m; ++c)
        {
            int u, v;
            double tem_d, dis_d;
            cin >> u >> v >> tem_d >> dis_d;

            road temp;
            temp.tem = (int)(tem_d * 10.0 + 0.5);
            temp.dis = (int)(dis_d * 10.0 + 0.5);

            r = max(r, temp.tem);

            a[u][v].push_back(temp); a[v][u].push_back(temp);
            g[u].push_back(v); g[v].push_back(u);
        }

        vector<nextNode> ansF;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            vector<nextNode> f(n + 1);

            if (canReach(mid, s, t, f, g, a) == true)
            {
                ansF = f;

                if (l == r)
                {
                    break;
                }

                r = mid;
            }
            else
            {
                if (l == r)
                {
                    break;
                }

                l = mid + 1;
            }
        }

        int ansDis = 0, nowU = t;
        vector<int> ansPath = {t};
        while (ansF[nowU].u != 0)
        {
            ansDis += a[ansF[nowU].u][nowU][ansF[nowU].j].dis;
            ansPath.push_back(ansF[nowU].u);

            nowU = ansF[nowU].u;
        }

        int size = ansPath.size();
        for (int i = size - 1; i >= 0; --i)
        {
            if (i < size - 1) cout << ' ';
            cout << ansPath[i];
        }
        cout << '\n';

        double ansDis_d = (double)(ansDis) / 10.0,
               l_d = (double)(l) / 10.0;

        ansDis_d = (int)(ansDis_d * 10.0 + 0.5) / 10.0;
        l_d = (int)(l_d * 10.0 + 0.5) / 10.0;
        
        cout << ansDis_d << ' ' << l_d << '\n';
    }

   	cout.flush();
   	return 0;
}

