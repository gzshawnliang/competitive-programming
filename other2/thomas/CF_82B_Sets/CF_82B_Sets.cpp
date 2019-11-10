#include <bits/stdc++.h>

using namespace std;

using ull = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("CF_82B_Sets.in", "r", stdin);
    //freopen("CF_82B_Sets.out", "w", stdout);
#endif

    //code here
    ull n;
    cin >> n;
    ull lines = n * (n - 1) / 2;

    vector<set<ull>> sets(lines);

    ull i = 0;
    int liCount = lines;
    while (liCount--)
    {
        ull k;
        cin >> k;
        while (k--)
        {
            ull x;
            cin >> x;
            sets[i].insert(x);
        }
        ++i;
    }

    if (n == 2)
    {
        cout << 1 << " " << *sets.front().begin() << '\n';
        ull setSize = sets[0].size();
        cout << setSize - 1 << " ";
        auto it = sets.front().begin();
        ++it;
        for (; it != sets.front().end(); ++it)
            cout << *it << " ";
    }
    else if (n > 2)
    {
        map<ull, set<ull>> locations;
        for (int j = 0; j <= lines - 1; ++j)
            for (auto it : sets[j])
                locations[it].insert(j);
            
        
        map<set<ull>, set<ull>> ans;
        for (auto it : locations)
            ans[it.second].insert(it.first);
            
        for (auto it : ans)
        {
            cout << it.second.size() << " ";
            for (auto it2 : it.second)
                cout << it2 << " ";

            cout << "\n";
        }
        //cerr << "o";
    }

    cout.flush();
    return 0;
}