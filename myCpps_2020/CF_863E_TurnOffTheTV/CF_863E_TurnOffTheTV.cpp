/*
===========================================================
* @Name:           863E Turn Off The TV
* @Author:         Shawn
* @create Time:    2020/3/21 23:05:05
* @url:            https://codeforces.com/contest/863/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int query(int l, int r, vector<int> &a, vector<vector<int>> &f)
{
    int log2Len = log2(r - l + 1);
    return min(a[f[l][log2Len]], a[f[r - (1 << log2Len) + 1][log2Len]]);
}

void solve()
{
    int n; cin >> n;
    
    vector<int> hitol;
    map<int, int> hltoi;

    set<int> allInts;
    vector<pair<int, int>> orgAllLins(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> orgAllLins[i].first >> orgAllLins[i].second;
        ++orgAllLins[i].second;

        allInts.insert(orgAllLins[i].first);
        allInts.insert(orgAllLins[i].second);
    }

    int cntInts = 0;
    for (auto ite = allInts.begin(); ite != allInts.end(); ++ite, ++cntInts)
    {
        hitol.push_back(*ite);
        hltoi[*ite] = cntInts;
    }

    vector<int> layers(cntInts + 1, 0);
    for (int i = 0; i <= n - 1; ++i)
    {
        layers[hltoi[orgAllLins[i].first]] += 1;
        layers[hltoi[orgAllLins[i].second]] -= 1;
    }

    for (int i = 1; i <= cntInts - 1; ++i)
    {
        layers[i] += layers[i - 1];
    }

    int log2CntInts = log2(cntInts);
    vector<vector<int>> f(cntInts, vector<int>(log2CntInts + 2, 0));
    for (int p = 0; p <= log2CntInts + 1; ++p)
    {
        for (int i = 0; i <= cntInts - 1; ++i)
        {
            if      (i + (1 << p) - 1 > cntInts - 1) f[i][p] = f[i][p - 1];
            else if (p == 0)                   f[i][p] = i;

            else
            {
                if (layers[f[i][p - 1]] < layers[f[i + (1 << (p - 1))][p - 1]]) f[i][p] = f[i][p - 1];
                else                                                            f[i][p] = f[i + (1 << (p - 1))][p - 1];
            }
        }
    }

    for (int i = 0; i <= n - 1; ++i)
    {
        if (query(hltoi[orgAllLins[i].first], hltoi[orgAllLins[i].second] - 1, layers, f) > 1)
        {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << "-1\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_863E_TurnOffTheTV.in", "r", stdin);
        freopen("CF_863E_TurnOffTheTV.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}