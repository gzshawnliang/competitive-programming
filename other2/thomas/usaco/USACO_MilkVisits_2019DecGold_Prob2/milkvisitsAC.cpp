#include <bits/stdc++.h>
using namespace std;



const int MX = 100005;

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, M, T[MX], C[MX];
bool ok[MX];
vector<int> adj[MX];
array<int, 2> dat[MX];
vector<int> todo[MX];
pair<int, int> range[MX];
vector<pair<int, int>> stor[MX];
vector<int> ord;
int co = 0;

void dfs(int x, int y)
{
    co++;
    range[x].first = co;
    for (auto & t : adj[x])
        if (t != y)
            dfs(t, x);

    range[x].second = co - 1;
}

bool anc(int a, int b)
{
    return range[a].first <= range[b].first && range[b].second <= range[a].second;
}

void dfs2(int x, int y)
{
    stor[T[x]].push_back({x, (int)ord.size()});
    ord.push_back(x);
    for (auto t : todo[x])
        if ((int)stor[C[t]].size())
        {
            pair<int, int> y = stor[C[t]].back();
            if (y.first == x)
                ok[t] = 1;
            else
            {
                int Y = ord[y.second + 1];
                // x is one of endpoints for query t
                assert(dat[t][0] == x || dat[t][1] == x);
                if (!anc(Y, dat[t][0] + dat[t][1] - x))
                    ok[t] = 1;
            }
        }

    for (auto t : adj[x])
    {
        if (t != y)
            dfs2(t, x);
    }
    stor[T[x]].pop_back();
    ord.pop_back();
}

int main()
{
    setIO("milkvisits");
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> T[i];

    for (int i = 0; i < N - 1; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    dfs(1, 0);
    for (int i = 0; i <= M - 1; ++i)
    {
        cin >> dat[i][0] >> dat[i][1] >> C[i];
        for (int j = 0; j <= 2 - 1; ++j)
            todo[dat[i][j]].push_back(i);
    }
    dfs2(1, 0);
    for (int i = 0; i <= M - 1; ++i)
    {
        if (ok[i])
            cout << 1;
        else
            cout << 0;
    }
    cout << "\n";
}