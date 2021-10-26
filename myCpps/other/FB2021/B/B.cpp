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

class solution
{
    const int inf = 3000;

    bool isEq(vector<int> &v1, vector<int> &v2)
    {
        vector<int> mp(inf, 0);
        for (auto x:v1) mp[x] = 1;

        for (auto x:v2)
            if (mp[x] == 0) return false;
        return true;
    }

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            vector<vector<int>> a(n, vector<int>(n, 0));
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= n - 1; ++x)
                {
                    char ch; cin >> ch;
                    if      (ch == 'X') a[y][x] = 1;
                    else if (ch == 'O') a[y][x] = 2;
                }
            }

            int curLen = n + 1;
            vector<vector<int>> curAnsV;

            //Row
            for (int y = 0; y <= n - 1 ; ++y)
            {
                bool flg = true;
                vector<int> tmpAns;
                for (int x = 0; x <= n - 1 && flg == true; ++x)
                {
                    if      (a[y][x] == 0) tmpAns.push_back(y * n + x);
                    else if (a[y][x] == 2) flg = false;
                }

                if (flg)
                {
                    int sizT = tmpAns.size();
                    if (sizT < curLen)
                    {
                        curLen = sizT;
                        curAnsV.clear();
                        curAnsV.push_back(tmpAns);
                    }
                    else if (sizT == curLen)
                    {
                        curAnsV.push_back(tmpAns);
                    }
                }
            }

            //Col
            for (int x = 0; x <= n - 1; ++x)
            {
                bool flg = true;
                vector<int> tmpAns;
                for (int y = 0; y <= n - 1 && flg == true; ++y)
                {
                    if      (a[y][x] == 0) tmpAns.push_back(y * n + x);
                    else if (a[y][x] == 2) flg = false;
                }

                if (flg)
                {
                    int sizT = tmpAns.size();
                    if (sizT < curLen)
                    {
                        curLen = sizT;
                        curAnsV.clear();
                        curAnsV.push_back(tmpAns);
                    }
                    else if (sizT == curLen)
                    {
                        curAnsV.push_back(tmpAns);
                    }
                }
            }

            vector<vector<int>> ansV;

            for (auto &ansT : curAnsV)
            {
                bool flg = true;
                for (auto &ansL : ansV)
                {
                    if (isEq(ansT, ansL) == true)
                    {
                        flg = false;
                        break;
                    }
                }

                if (flg) ansV.push_back(ansT);
            }

            cout << "Case #" << tcc << ": ";
            if (ansV.empty())
                cout << "Impossible\n";
            else
                cout << curLen << ' ' << ansV.size() << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
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