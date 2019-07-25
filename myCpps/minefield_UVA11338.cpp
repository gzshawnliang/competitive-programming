#include <bits/stdc++.h>

using namespace std;

ifstream fin("minefield_UVA11338.in");
ofstream fout("minefield_UVA11338.out");

const double eps = 1e-9, inf = 20000.0;

bool equal(double a, double b)
{
    return abs(a - b) < eps;
}

struct point
{
    double x;
    double y;

    bool operator < (const point & temp) const
    {
        if (equal(x, temp.x) == false)
        {
            return x < temp.x;
        }
        else
        {
            return y < temp.y && equal(y, temp.y) == false;
        }
    }
};
point _point(double x, double y)
{
    point temp{x, y}; return temp;
}
double distance(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

struct segment
{
    int u;
    double d;

    bool operator < (const segment & temp) const
    {
        return d > temp.d;
    }
};
segment _segment(int u, double d)
{
    segment temp{u, d}; return temp;
}

int main()
{
    while (true)
    {
        double w = -1.0, h = -1.0; fin >> w >> h;
        if (h == -1.0) break;

        int n; fin >> n;
        set<point> p;
        for (int c = 1; c <= n; ++c)
        {
            double x, y; fin >> x >> y;

            p.insert(_point(x, y));
        }
        p.insert(_point(0.0, 0.0));
        p.insert(_point(w, h));
        n = p.size();

        double maxD; fin >> maxD;
        
        int _i = -1;
        vector<point> ntop(n);
        map<point, int> pton;
        for (auto it = p.begin(); it != p.end(); ++it)
        {
            ++_i;
            auto u = *it;

            ntop[_i] = u;
            pton[u] = _i;
        }

        vector<vector<double>> a(n, vector<double>(n, inf));
        vector<vector<int>> g(n);
        for (int u = 0; u <= n - 1; ++u)
        {
            for (int v = u + 1; v <= n - 1; ++v)
            {
                point p1 = ntop[u], p2 = ntop[v];
                double d = distance(p1, p2);

                if (d < 1.5 || equal(d, 1.5) == true)
                {
                    a[u][v] = d; a[v][u] = a[u][v];
                    g[u].push_back(v); g[v].push_back(u);
                }
            }
        }
        
        bool ok = false;
        vector<double> d(n, inf);
        priority_queue<segment> pq; pq.push(_segment(0.0, 0.0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.d > d[now.u] || equal(now.d, d[now.u]) == true)
            {
                continue;
            }
            d[now.u] = now.d;

            if (now.d > maxD && equal(now.d, maxD) == false)
            {
                continue;
            }

            if (equal(ntop[now.u].x, w) == true && equal(ntop[now.u].y, h) == true)
            {
                ok = true;
                break;
            }

            int size = g[now.u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g[now.u][i];

                pq.push(_segment(v, now.d + a[now.u][v]));
            }
        }

        if (ok == true) fout << "I am lucky!\n";
        else fout << "Boom!\n";
    }

    return 0;
}
