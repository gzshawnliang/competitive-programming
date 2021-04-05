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

class solution
{
  public:
    void solve()
    {
        int n; cin >> n;
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