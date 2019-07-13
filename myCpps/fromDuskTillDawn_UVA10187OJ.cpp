#include <bits/stdc++.h>

using namespace std;


const int N = 100, inf = INT_MAX / 2;

struct edge
{
    int t1;
    int t2;
};
edge _edge(int t1, int t2)
{
    edge temp{t1, t2}; return temp;
}

struct segment
{
    int u;
    int t;
    int b;

    bool operator < (const segment & temp) const
    {
        return b > temp.b;
    }
};
segment _segment(int u, int t, int b)
{
    segment temp{u, t, b}; return temp;
}

int getNum(int & n, string str, map<string, int> & ston, vector<string> & ntos)
{
    if (ston.count(str) == 0)
    {
        ston[str] = n; ++n;
        ntos.push_back(str);
    }
    return ston[str];
}

int getDis(int t1, int t2)
{
    if (t1 <= t2)
    {
        return t2 - t1;
    }
    else
    {
        return t2 - t1 + 24;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n = 0, m; cin >> m;

        map<string, int> ston;
        vector<string> ntos;
        vector<vector<int>> g(N + 1);
        vector<vector<vector<edge>>> a(N + 1, vector<vector<edge>>(N + 1));
                            
        for (int c = 1; c <= m; ++c)
        {
            string u_s, v_s; cin >> u_s >> v_s;
            int u = getNum(n, u_s, ston, ntos), v = getNum(n, v_s, ston, ntos);
            int t1, tp, t2; cin >> t1 >> tp;
            t2 = (t1 + tp) % 24;

            
            bool ok = false;
            if (tp > 12)
            {
                ok = false;
            }
            else if (t1 >= 12 && t2 <= 12)
            {
                if (t1 >= 18 && t2 <= 6)
                {
                    ok = true;
                }
            }
            else if ((t1 >= 18 || t2 <= 6) && t1 <= t2)
            {
                ok = true;
            }

            if (ok == true)
            {
                if (t1 == 24) t1 = 0;
                if (t2 == 24) t2 = 0;

                if (a[u][v].size() == 0)
                {
                    g[u].push_back(v);
                }
                a[u][v].push_back(_edge(t1, t2));
            }
        }

        string s_s, e_s; cin >> s_s >> e_s;
        int s = getNum(n, s_s, ston, ntos), e = getNum(n, e_s, ston, ntos);

        if (t == 24)
        {
            for (int __s = 0; __s == 0; ++__s);
        }



        bool isFirst = true;
        int ans = -1;
        vector<vector<int>> d(n, vector<int>(24, inf));
        priority_queue<segment> pq; pq.push(_segment(s, 0, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (isFirst == false && now.b >= d[now.u][now.t]) continue;
            d[now.u][now.t] = now.b;

            if (now.u == 3)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            if (now.u == e)
            {
                ans = now.b;
                break;
            }

            int size0 = g[now.u].size();
            for (int i = 0; i <= size0 - 1; ++i)
            {
                int v = g[now.u][i];

                int size1 = a[now.u][v].size();
                for (int j = 0; j <= size1 - 1; ++j)
                {
                    edge nowEdge = a[now.u][v][j];
                    segment next;
                    next.u = v;
                    next.t = nowEdge.t2;

                    if (isFirst == true)
                    {
                        next.b = now.b;
                    }
                    else
                    {
                        bool find12 = 0;
                        for (int _t = now.t; _t != nowEdge.t1; _t = (_t + 1) % 24)
                        {
                            if (_t == 12)
                            {
                                find12 = 1;
                                break;
                            }
                        }
                        next.b = now.b + find12;
                    }

                    pq.push(next);
                }
            }

            isFirst = false;
        }

        cout << "Test Case " << t << ".\n";
        if (ans == -1)
        {
            cout << "There is no route Vladimir can take.\n";
        }
        else
        {
            cout << "Vladimir needs " << ans << " litre(s) of blood.\n";
        }
        
    }

   	cout.flush();
   	return 0;
}

