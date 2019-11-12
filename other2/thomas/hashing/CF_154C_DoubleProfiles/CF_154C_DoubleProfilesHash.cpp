#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
const ull R1 = 999853; //质数
const ull R2 = 708989; //质数

int main()
{
    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);

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
            ull code0=0;
            ull code1=0;

            ull code2=0;
            ull code3=0;
            for (auto it=data[i].begin(); it!=data[i].end(); ++it)
            {
                code0 = code0 * R1 + (*it);
                code1 = code1 * R2 + (*it);

                if(i !=*it)
                {
                    code2 = code2 * R1 + (*it);
                    code3 = code3 * R1 + (*it);
                }
            }
            ++hashMap[code0*code1];
            ++hashMap[code2*code3];
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
    cout.flush();
    return 0;
}
