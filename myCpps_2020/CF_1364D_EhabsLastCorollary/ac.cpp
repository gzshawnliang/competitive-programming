#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> G[N];
deque<int> circ;
vector<int> s, col[2];
int n, m, k, pos[N], u[N], v[N];
bool in_circ[N];
void DFS(int u)
{
    pos[u] = s.size();
    s.push_back(u);
    col[pos[u] & 1].push_back(u);
    for(int v : G[u])
    {
        if(pos[v] == -1) DFS(v);
        else if(circ.empty() && pos[u] > pos[v] + 1)
        {
            for(int i = pos[v]; i <= pos[u]; i++)
            {
                circ.push_back(s[i]);
                in_circ[s[i]] = true;
            }
        }
    }
    s.pop_back();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("CF_1364D_EhabsLastCorollary.in", "r", stdin);
    freopen("CF_1364D_EhabsLastCorollary.out", "w", stdout);
#endif    
    memset(pos, -1, sizeof pos);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    DFS(1);
    if(circ.empty())
    {
        cout << 1 << endl;
        if(col[0].size() < col[1].size()) swap(col[0], col[1]);
        for(int i = 0; i < (k + 1) / 2; i++) cout << col[0][i] << ' ';
        return 0;
    }
    for(int i = 1; i <= m; i++)
    {
        if(in_circ[u[i]] && in_circ[v[i]] && abs(pos[u[i]] - pos[v[i]]) != 1)
        {
            while(circ.front() != u[i] && circ.front() != v[i])
                in_circ[circ.front()] = false, circ.pop_front();
            while(circ.back() != u[i] && circ.back() != v[i])
                in_circ[circ.back()] = false, circ.pop_back();
        }
    }
    if(circ.size() <= k)
    {
        cout << 2 << endl;
        cout << circ.size() << endl;
        for(int i = 0; i < circ.size(); i++) cout << circ[i] << ' ';
    }
    else
    {
        cout << 1 << endl;
        for(int i = 0; i < (k + 1) / 2; i++) cout << circ[i * 2] << ' ';
    }
    return 0;
}