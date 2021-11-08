/*
-------------------------------------------------------------------
* @Name:           1374E2 Reading Books (hard version)
* @Author:         Shawn
* @Create Time:    2020/7/1 17:44:59  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1374/problem/E2
* @Description:    
-------------------------------------------------------------------
*/

#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const int N = 2e5 + 10;

class solution
{
  public:
    int n, m, k, res = 2e9 + 1, num;
    vector<pair<int, int>> v[4];
    vector<int> ans;

    int check(int mid)
    {
        if ((int)v[1].size() < k - mid)
            return 2e9 + 1;
        if ((int)v[2].size() < k - mid)
            return 2e9 + 1;
        if (mid + max(0, k - mid) * 2 > m)
            return 2e9 + 1;

        int nd = m - mid, res = 0;
        vector<pair<int, int>> vec;
        ans.clear();

        for (int i = 0; i < mid; i++)
            res += v[3][i].first, ans.push_back(v[3][i].second);
        for (int i = mid; i < v[3].size(); i++)
            vec.push_back(v[3][i]);
        for (int i = 0; i < k - mid; i++)
            res += v[1][i].first + v[2][i].first, nd -= 2,
                ans.push_back(v[1][i].second), ans.push_back(v[2][i].second);
        for (int i = max(0, k - mid); i < v[1].size(); i++)
            vec.push_back(v[1][i]);
        for (int i = max(0, k - mid); i < v[2].size(); i++)
            vec.push_back(v[2][i]);
        for (int i = 0; i < v[0].size(); i++)
            vec.push_back(v[0][i]);
        
        sort(vec.begin(), vec.end());

        for (int i = 0; i < nd && i < vec.size(); i++)
            res += vec[i].first, ans.push_back(vec[i].second);

        return res;
    }

    void solve()
    {
        cin >> n >> m >> k;

        for (int i = 1, t, a, b; i <= n; i++)
        {
            cin >> t >> a >> b;
            v[a * 2 + b].push_back({t, i});
        }
        for (int i = 0; i < 4; i++)
            sort(v[i].begin(), v[i].end());

        int l = 0, r = min(m, (int)v[3].size());

        while (r - l > 10)
        {
            int midl = l + (r - l) / 3;
            int midr = r - (r - l) / 3;

            if (check(midl) >= check(midr))
                l = midl;
            else
                r = midr;
        }

        for (int i = l; i <= r; i++)
        {
            int tmp = check(i);
            if (tmp < res)
                res = tmp, num = i;
        }
        if (res == 2e9 + 1)
        {
            cout << "-1";
            return;
        }
        cout << res << endl;
        check(num);
        for (int i : ans)
            cout << i << " ";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1374E2_ReadingBooks(hardversion).in", "r", stdin);
    //freopen("CF_1374E2_ReadingBooks(hardversion).out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}