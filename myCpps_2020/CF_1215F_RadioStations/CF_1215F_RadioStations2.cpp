/*
===========================================================
* @Name:           1215F Radio Stations
* @Author:         Shawn
* @create Time:    2020/2/6 20:51:16
* @url:            https://codeforces.com/contest/1215/problem/F
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
vector<vector<int>> g;
int get0(int x) 
{
    return x * 2 - 2;
}
int get1(int x) 
{
    return x * 2 - 1;
}

void dfs(int u, int &cnt, int &cntScc, vector<int> &topLog, vector<int> &ids, vector<int> &low, vector<int> &inStack, stack<int> &stk)
{
    stk.push(u); inStack[u] = 1;
    
    ids[u] = cnt; low[u] = cnt; ++cnt;

    for (auto ite = g[u].begin(); ite != g[u].end(); ++ite)
    {   
        int v = *ite;
        if (ids[v] == -1) dfs(v, cnt, cntScc, topLog, ids, low, inStack, stk);

        if (inStack[v] == true)
        {
            low[u] = min(low[u], low[v]);
        }
    }

    if (ids[u] == low[u])
    {
        while (stk.empty() == false)
        {
            int i = stk.top(); stk.pop();

            topLog[i] = cntScc;
            
            inStack[i] = 0;
            low[i] = ids[u];

            if (i == u) break;
        }

        ++cntScc;
    }
}

struct radioSta
{
    int l;
    int r;
    int num;

    bool operator < (const radioSta & temp) const
    {
        return l < temp.l;
    }
};
radioSta _radioSta(int l, int r, int num)
{
    radioSta tmp{l, r, num}; return tmp;
}

void solve()
{
    int totC, n, maxF, totI; cin >> totC >> n >> maxF >> totI;

    //vector<unordered_set<int>> g(n * 2);
    g.assign(n*2,vector<int>());

    for (int c = 1; c <= totC; ++c)
    {
        int sta1, sta2; cin >> sta1 >> sta2;

        g[get0(sta1)].push_back(get1(sta2));
        g[get0(sta2)].push_back(get1(sta1));
    }

    vector<pair<int, int>> freOrg(n + 1);
    vector<radioSta> fre(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> fre[i].l >> fre[i].r;
        fre[i].num = i + 1;

        freOrg[i + 1].first = fre[i].l; freOrg[i + 1].second = fre[i].r;
    }
    sort(fre.begin(), fre.end());

    for (int c = 1; c <= totI; ++c)
    {
        int sta1, sta2; cin >> sta1 >> sta2;

        g[get1(sta1)].push_back(get0(sta2));
        g[get1(sta2)].push_back(get0(sta1));
    }

    for (int i = 0; i <= n - 1; ++i)
    {
        radioSta now = fre[i];

        auto ite = upper_bound(fre.begin(), fre.end(), _radioSta(now.r, 0, 0));
        while (ite != fre.end())
        {
            radioSta oth = *ite;

            g[get1(now.num)].push_back(get0(oth.num));
            g[get1(oth.num)].push_back(get0(now.num));

            ++ite;
        }
    }

    int cnt = 0, cntScc = 0;
    vector<int> topLog(n * 2, 0), ids(n * 2, -1), low(n * 2, 0), inStack(n * 2, 0);
    stack<int> stk;

    for (int u = 0; u <= 2 * n - 1; ++u)
    {
        if (ids[u] == -1) dfs(u, cnt, cntScc, topLog, ids, low, inStack, stk);
    }

    bool flg = true;
    for (int u = 0; u <= 2 * n - 2; u += 2)
    {
        if (low[u] == low[u + 1])
        {
            flg = false;
            break;
        }
    }

    if (flg == false)
    {
        cout << "-1\n";
    }
    else
    {
        int ansSiz = 0, ansFre = 0;
        vector<int> ans;

        for (int i = 1; i <= n; ++i)
        {
            if (topLog[get0(i)] > topLog[get1(i)])
            {
                ans.push_back(i);
                ++ansSiz;

                ansFre = max(ansFre, freOrg[i].first);
            }
        }
        
        cout << ansSiz << ' ' << ansFre << '\n';
        for (int i = 0; i <= ansSiz - 1; ++i)
        {
            if (i > 0) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1215F_RadioStations.in", "r", stdin);
        freopen("CF_1215F_RadioStations.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}