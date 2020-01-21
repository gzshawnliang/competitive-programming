#include <bits/stdc++.h>

using namespace std;

ifstream fin("threesum.in");
ofstream fout("threesum.out");

int maxN = 100000;

int main()
{
    vector<vector<int>> pos(maxN * 2 + 1);
    
    int n, cfq; fin >> n >> cfq;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
        pos[a[i] + maxN].push_back(i);
    }

    multiset<pair<int, int>> all_s;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 2; j <= n; ++j)
        {
            int lef = 0 - a[i] - a[j];

            int siz = pos[lef + maxN].size();
            for (int ifp = 0; ifp <= siz - 1; ++ifp)
            {
                int k = pos[lef + maxN][ifp];
                if (i < k && k < j)
                {
                    all_s.insert({i, j});
                }
            }
        }
    }

    vector<pair<int, int>> all;
    for (auto ite = all_s.begin(); ite != all_s.end(); ++ite)
    {
        all.push_back(*ite);
    }
    
    for (int c = 1; c <= cfq; ++c)
    {
        int bfl, bfr; fin >> bfl >> bfr;

        auto ipos1 = lower_bound(all.begin(), all.end(), make_pair(bfl, 0));
        auto ipos2 = upper_bound(ipos1, all.end(), make_pair(0, bfr),
            [](pair<int, int> tmp1, pair<int, int> tmp2) -> bool
            {
                return tmp1.second < tmp2.second;
            });


        fout << ipos2 - ipos1 << '\n';
    }

    return 0;
}
