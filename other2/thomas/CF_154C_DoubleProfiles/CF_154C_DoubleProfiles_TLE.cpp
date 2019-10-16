#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = unsigned long long;
const ull R = 13331; //质数

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_154C_DoubleProfiles.in", "r", stdin);
        freopen("CF_154C_DoubleProfiles.out", "w", stdout);
    #endif

    int n;
    cin >>n;
    int m;
    cin >>m;
    unordered_map<ull,ull> hashMap;
    vector<set<int>> data(n+1);

    for (int i = 0; i <= m - 1; ++i)
    {
        int u,v;
        cin >> u >> v;
        data[u].insert(v);
        data[u].insert(u);
        data[v].insert(u);
        data[v].insert(v);
    }

    for (int i = 1; i <= n; ++i)
    {
        if(data[i].empty())
        {
            ++hashMap[0];
        }
        else
        {
            ull code=0;
            ull code2=0;
            for (auto it=data[i].begin(); it!=data[i].end(); ++it)
            {
                code = code * R + (*it);
                if(i !=*it)
                    code2 = code2 * R + (*it);
            }
            ++hashMap[code];
            ++hashMap[code2];
        }
    }
    ull ans=0;
    for (auto it = hashMap.begin(); it != hashMap.end(); ++it)
    {
        if(it->second>1)
        {
            ans += (it->second * (it->second-1) /2);
        }
    }

    cout << ans << '\n';
    return 0;
}
