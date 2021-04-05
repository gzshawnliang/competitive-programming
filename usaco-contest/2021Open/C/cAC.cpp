#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

struct Line {
    double x1;
    double y1;
    double x2;
    double y2;
};
Line _Line(pair<int, int> p1, pair<int, int> p2)
{
    Line tmp{p1.first, p1.second, p2.first, p2.second}; return tmp;
}
 
bool intersection(const Line &l1, const Line &l2)
{
    set<pair<int, int>> st;
    st.insert({l1.x1, l1.y1}); st.insert({l1.x2, l1.y2});
    st.insert({l2.x1, l2.y1}); st.insert({l2.x2, l2.y2});
    if (st.size() < 4)
    {
        if ((l1.y2 - l1.y1) * (l2.x2 - l2.x1) != (l2.y2 - l2.y1) * (l1.x2 - l1.x1))
        {
            return false;
        }
        else
        {
            return true;
        }
    } 

    //快速排斥实验
    if ((l1.x1 > l1.x2 ? l1.x1 : l1.x2) < (l2.x1 < l2.x2 ? l2.x1 : l2.x2) ||
        (l1.y1 > l1.y2 ? l1.y1 : l1.y2) < (l2.y1 < l2.y2 ? l2.y1 : l2.y2) ||
        (l2.x1 > l2.x2 ? l2.x1 : l2.x2) < (l1.x1 < l1.x2 ? l1.x1 : l1.x2) ||
        (l2.y1 > l2.y2 ? l2.y1 : l2.y2) < (l1.y1 < l1.y2 ? l1.y1 : l1.y2))
    {
        return false;
    }
    //跨立实验
    if ((((l1.x1 - l2.x1)*(l2.y2 - l2.y1) - (l1.y1 - l2.y1)*(l2.x2 - l2.x1))*
        ((l1.x2 - l2.x1)*(l2.y2 - l2.y1) - (l1.y2 - l2.y1)*(l2.x2 - l2.x1))) > 0 ||
        (((l2.x1 - l1.x1)*(l1.y2 - l1.y1) - (l2.y1 - l1.y1)*(l1.x2 - l1.x1))*
        ((l2.x2 - l1.x1)*(l1.y2 - l1.y1) - (l2.y2 - l1.y1)*(l1.x2 - l1.x1))) > 0)
    {
        return false;
    }

    return true;
}

double getNotPArea(pair<int, int> pointA, pair<int, int> pointB, pair<int, int> pointC)
{
    double x1 = pointA.first, y1 = pointA.second,
        x2 = pointB.first, y2 = pointB.second,
        x3 = pointC.first, y3 = pointC.second;

    double a, b, c, p, s;
    a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    b = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    c = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));

    p = (a + b + c) / 2;
    s = sqrt(p*(p - a)*(p - b)*(p - c));

    return s;

}

bool inside(pair<int, int> p, pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    double a1 = getNotPArea(p, a, b),
           a2 = getNotPArea(p, a, c),
           a3 = getNotPArea(p, b, c);
    return (abs(a1 + a2 + a3 - getNotPArea(a, b, c) < 1e-9));
}

class solution
{
  public:
    void solve()
    {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (auto &p:a) cin >> p.first >> p.second;
        //sort(a.begin(), a.end());

        vector<vector<vector<ill>>> f(n, vector<vector<ill>>(n, vector<ill>(n, 0))),
                                    vis(n, vector<vector<ill>>(n, vector<ill>(n, 0)));

        int maxI = -1, maxJ = -1, maxK = -1;
        double maxA = 0.0;
        queue<tuple<int, int, int>> qq;
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n - 1; ++j)
            {
                for (int k = j + 1; k <= n - 1; ++k)
                {
                    double nowA = getNotPArea(a[i], a[j], a[k]);
                    if (nowA > maxA)
                    {
                        maxI = i; maxJ = j; maxK = k;
                    }

                    bool flg = true;
                    for (int x = 0; x <= n - 1; ++x)
                    {
                        if (x == i || x == j || x == k) continue;
                        if (inside(a[x], a[i], a[j], a[k])) 
                        {
                            flg = false; break;
                        }
                    }

                    if (flg)
                    {
                        qq.push({i, j, k});
                        f[i][j][k] = 3;
                        vis[i][j][k] = 1;
                    }
                }
            }
        }

        while (!qq.empty())
        {
            tuple<int, int, int> now = qq.front(); qq.pop();
            int i = get<0>(now), j = get<1>(now), k = get<2>(now);
            vis[i][j][k] = 1;

            for (int x = 0; x <= n - 1; ++x)
            {
                if (x == i || x == j || x == k) continue; 

                bool flg = true;
                if (intersection(_Line(a[x], a[i]), _Line(a[j], a[k]))) flg = false;
                if (intersection(_Line(a[x], a[j]), _Line(a[i], a[k]))) flg = false;
                if (intersection(_Line(a[x], a[k]), _Line(a[i], a[j]))) flg = false;

                if (flg)
                {
                    double Axij = getNotPArea(a[x], a[i], a[j]),
                           Axik = getNotPArea(a[x], a[i], a[k]),
                           Axjk = getNotPArea(a[x], a[j], a[k]);
                    double maxA = max(Axij, max(Axik, Axjk));

                    if (Axij == maxA)
                    {
                        ill tmpV = f[i][j][k];
                        vector<int> tmpArr = {x, i, j};
                        sort(tmpArr.begin(), tmpArr.end());
                        x = tmpArr[0]; i = tmpArr[1]; j = tmpArr[2];

                        if (vis[x][i][j] == false) qq.push({x, i, j});
                        f[x][i][j] = (f[x][i][j] + tmpV) % (ill)(1e9 + 7);
                    }
                    else if (Axik == maxA)
                    {
                        ill tmpV = f[i][j][k];
                        vector<int> tmpArr = {x, i, k};
                        sort(tmpArr.begin(), tmpArr.end());
                        x = tmpArr[0]; i = tmpArr[1]; k = tmpArr[2];

                        if (vis[x][i][k] == false) qq.push({x, i, k});
                        f[x][i][k] = (f[x][i][k] + tmpV) % (ill)(1e9 + 7);
                    }
                    else
                    {
                        ill tmpV = f[i][j][k];
                        vector<int> tmpArr ={x, j, k};
                        sort(tmpArr.begin(), tmpArr.end());
                        x = tmpArr[0]; j = tmpArr[1]; k = tmpArr[2];

                        if (vis[x][j][k] == false) qq.push({x, j, k});
                        f[x][j][k] = (f[x][j][k] + tmpV) % (ill)(1e9 + 7);
                    }
                }
            }
        }

        cout << f[maxI][maxJ][maxK] << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}