#include <bits/stdc++.h>

using namespace std;

ifstream fin("Subway_UVA10389.in");
ofstream fout("Subway_UVA10389.out");

const long long inf = LLONG_MAX / 2;

struct point
{
    long long x;
    long long y;

    bool operator<(const point & temp) const
    {
        return x < temp.x || y < temp.y;
    }

    bool operator==(const point & temp) const
    {
        return x == temp.x && y == temp.y;
    }
};
point _point(long long x, long long y)
{
    point temp{x, y}; return temp;
}

struct segment
{
    long long u;
    double d;

    bool operator<(const segment & temp) const
    {
        return d > temp.d;
    }
};
segment _segment(long long u, double d)
{
    segment temp{u, d}; return temp;
}

long long distance(point & p1, point & p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main()
{
    long long testCase; fin >> testCase;
    for (long long t = 1; t <= testCase; ++t)
    {
        if (t > 1) fout << '\n';

        vector<vector<long long>> a_2(250, vector<long long>(250, inf));

        point start, end; fin >> start.x >> start.y >> end.x >> end.y;

        vector<point> itop = {start, end};
        map<point, long long> ptoi;
        ptoi[start] = 0; ptoi[end] = 1;

        a_2[0][1] = distance(start, end) * 16; a_2[1][0] = a_2[0][1];

        string in = "";
        getline(fin, in);
        while (true)
        {
            getline(fin, in);
            if (in == "") break;

            istringstream inIn(in);
            vector<long long> line;

            while (true)
            {
                long long x, y;
                inIn >> x >> y;
                if (x == -1 && y == -1) break;

                point temp{x, y};
                if (ptoi.count(temp) == 0)
                {
                    //ptoi[temp] = itop.size();

                    long long size = itop.size();
                    ptoi.insert(pair<point,long long>(temp, size));
                    itop.push_back(temp);
                }

                line.push_back(itop.size() - 1);
            }

            long long size = line.size();
            for (long long i = 0; i <= size - 2; ++i)
            {
                a_2[line[i]][line[i + 1]] = distance(itop[line[i]], itop[line[i + 1]]);
                a_2[line[i + 1]][line[i]] = a_2[line[i]][line[i + 1]];
            }
        }

        long long n = itop.size();
        for (long long u = 0; u <= n - 1; ++u)
        {
            a_2[u][u] = 0;
            for (long long v = u + 1; v <= n - 1; ++v)
            {
                a_2[u][v] = min(a_2[u][v], distance(itop[u], itop[v]) * 16);
                a_2[v][u] = a_2[u][v];
            }
        }

        vector<vector<double>> a(250, vector<double>(250, (double)inf));
        for (long long u = 0; u <= n - 1; ++u)
        {
            for (long long v = 0; v <= n - 1; ++v)
            {
                a[u][v] = sqrt((double)a_2[u][v]); 
            }
        }

        vector<double> d(n, inf); d[0] = 0.0;
        priority_queue<segment> pq; pq.push(_segment(0, 0.0));
        while (!pq.empty())
        {
            segment now = pq.top(); pq.pop();

            if (d[now.u] < now.d) continue;

            for (long long v = 0; v <= n - 1; ++v)
            {
                if (v == now.u) continue;
                else if (now.d + a[now.u][v] < d[v])
                {
                    d[v] = now.d + a[now.u][v];
                    pq.push(_segment(v, d[v]));
                }
            }
        }

        double ans = d[1] / 1000.0 / 40.0 * 60.0;

        fout << round(ans) << '\n';
    }

    return 0;
}
