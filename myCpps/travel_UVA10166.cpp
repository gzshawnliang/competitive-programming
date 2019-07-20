#include <bits/stdc++.h>

using namespace std;

ifstream fin("travel_UVA10166.in");
ofstream fout("travel_UVA10166.out");

struct route
{
    int t1;
    int t2;

    bool operator < (const route & temp) const
    {
        if (t2 != temp.t2) return t2 < temp.t2;
        else return t1 > temp.t1;
    }
    bool operator == (const route & temp) const
    {
        return t1 == temp.t1 && t2 == temp.t2;
    }
};
route _route(int t1, int t2)
{
    route temp{t1, t2}; return temp;
}

struct segment
{
    int u;
    int at;
    int st;

    bool operator < (const segment & temp) const
    {
        if (at != temp.at) return at > temp.at;
        else return st < temp.st;
    }
};
segment _segment(int u, int at, int st)
{
    segment temp{u, at, st}; return temp;
}

string toTime(int t)
{
    string s = to_string(t);
    while (s.size() < 4)
    {
        s.insert(s.begin(), '0');
    }

    return s;
}

int main()
{
    while (true)
    {
        int n = 0; fin >> n;
        if (n == 0) break;

        map<string, int> cton;
        for (int c1 = 0; c1 <= n - 1; ++c1)
        {
            string s; fin >> s;
            cton[s] = c1;
        }

        vector<vector<set<route>>> a(n, vector<set<route>>(n));

        int tc; fin >> tc;
        for (int c0 = 1; c0 <= tc; ++c0)
        {
            int cc; fin >> cc;
            int lastTime; string lastCity;
            for (int c1 = 1; c1 <= cc; ++c1)
            {
                if (c1 == 1)
                {
                    fin >> lastTime >> lastCity;
                }
                else
                {
                    int nowTime; string nowCity; fin >> nowTime >> nowCity;

                    a[cton[lastCity]][cton[nowCity]].insert(_route(lastTime, nowTime));
                    
                    lastTime = nowTime; lastCity = nowCity;
                }
            }
        }

        int earliestTime;
        string s_s, e_s;
        fin >> earliestTime >> s_s >> e_s;

        int s = cton[s_s], e = cton[e_s];

        int ansSTime = -1, ansETime = -1;
        vector<vector<int>> dp(n, vector<int>(2400, 9999));
        priority_queue<segment> pq;
        for (int v = 0; v <= n - 1; ++v)
        {
            if (a[s][v].empty() == false)
            {
                for (auto it = a[s][v].begin(); it != a[s][v].end(); ++it)
                {
                    if (it->t1 >= earliestTime)
                    {
                        pq.push(_segment(v, it->t2, it->t1));
                    }
                }
            }
        }

        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.at >= dp[now.u][now.st] || now.at < now.st) continue;
            dp[now.u][now.st] = now.at;

            if (now.u == e)
            {
                ansSTime = now.st; ansETime = now.at;
                break;
            }

            for (int v = 0; v <= n - 1; ++v)
            {
                if (a[now.u][v].empty() == false)
                {
                    for (auto it = a[now.u][v].begin(); it != a[now.u][v].end(); ++it)
                    {
                        if (now.at <= it->t1)
                        {
                            pq.push(_segment(v, it->t2, now.st));
                        }
                    }
                }
            }
        }

        if (ansSTime >= 0)
        {
            fout << toTime(ansSTime) << ' ' << toTime(ansETime) << '\n';
        }
        else
        {
            fout << "No connection\n";
        }
    }

    return 0;
}
