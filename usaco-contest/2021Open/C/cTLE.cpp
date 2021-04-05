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

double getDist_P2L(pair<int, int> pointP, pair<int, int> pointA, pair<int, int> pointB)
{
    int A = 0, B = 0, C = 0;
    A = pointA.second - pointB.second;
    B = pointB.first - pointA.first;
    C = pointA.first * pointB.second - pointA.second * pointB.first;

    double distance = 0;
    distance = ((double)abs(A * pointP.first + B * pointP.second + C)) / ((double)sqrtf(A * A + B * B));
    return distance;
}

int getNotPArea(pair<int, int> pointA, pair<int, int> pointB, pair<int, int> pointC)
{
    int ans = pointA.first * pointB.second + pointB.first * pointC.second + pointC.first * pointA.second;
    ans -= (pointA.second * pointB.first + pointB.second * pointC.first + pointC.second * pointA.first);
    return abs(ans);
}


class solution
{
  public:
    void solve()
    {
        int n; cin >> n;

        if (n <= 8)
        {
            vector<pair<int, int>> a(n);
            for (auto &p:a) cin >> p.first >> p.second;
            sort(a.begin(), a.end());

            int ans = 0;
            do
            {
                vector<Line> allL;
                allL.push_back(_Line(a[0], a[1]));
                allL.push_back(_Line(a[1], a[2]));
                allL.push_back(_Line(a[2], a[0]));

                bool flg = true;
                for (int i = 3; i <= n - 1; ++i)
                {
                    int tmp = 0;

                    for (int j = 0; j <= i - 1; ++j)
                    {
                        Line nowL = _Line(a[i], a[j]);
                        bool isInters = false;
                        for (auto l:allL)
                        {
                            if (intersection(l, nowL) == true)
                            {
                                isInters = true;
                                break;
                            }
                        }

                        if (isInters == false)
                        {
                            ++tmp;
                            allL.push_back(nowL);
                        }
                    }

                    if (tmp != 3)
                    {
                        flg = false;
                        break;
                    }
                }

                if (flg)
                {
                    ++ans;
                }
            }
            while (next_permutation(a.begin(), a.end()));

            cout << ans << '\n';
        }
        else
        {
            vector<pair<int, int>> a(n);
            for (auto &p:a) cin >> p.first >> p.second;
            sort(a.begin(), a.end());

            cout << "0\n";

            // int maxI = -1, maxJ = -1, maxD = 0;
            // for (int i = 0; i <= n - 1; ++i)
            // {
            //     for (int j = i + 1; j <= n - 1; ++j)
            //     {
            //         int nowD = (a[i].first - a[j].first) * (a[i].first - a[j].first) +
            //                    (a[i].second - a[j].second) * (a[i].second - a[j].second);
            //         if (nowD > maxD)
            //         {
            //             maxI = i; maxJ = j; maxD = nowD;
            //         }
            //     }
            // }

            // double maxD2 = 0.0;
            // int maxP = -1;
            // for (int i = 0; i <= n - 1; ++i)
            // {
            //     double nowD = getDist_P2L(a[i], a[maxI], a[maxJ]);
            //     if (nowD > maxD2)
            //     {
            //         maxD2 = nowD;
            //         maxP = i;
            //     }
            // }

            // bool flg = true;
            // for (auto &p:a)
            // {
            //     int a1 = getNotPArea(p, a[maxI], a[maxJ]),
            //         a2 = getNotPArea(p, a[maxI], a[maxP]),
            //         a3 = getNotPArea(p, a[maxI], a[maxP]);
            //     if (a1 + a2 + a3 != getNotPArea(a[maxP], a[maxI], a[maxJ]))
            //     {
            //         flg = false;
            //         break;
            //     }
            // }

            // if (flg == false)
            // {
            //     cout << "0\n";
            // }
            // else
            // {
            //     cout << "-1\n";
            // }
        }
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