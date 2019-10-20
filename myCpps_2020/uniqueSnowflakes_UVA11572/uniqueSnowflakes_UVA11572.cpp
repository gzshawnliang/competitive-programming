#include <bits/stdc++.h>

using namespace std;

ifstream fin("uniqueSnowflakes_UVA11572.in");
ofstream fout("uniqueSnowflakes_UVA11572.out");

int main()
{
    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int count = 0;
        unordered_map<int, int> itoi;

        int n; fin >> n;

        if (n == 0)
        {
            fout << "0\n";
            continue;
        }

        vector<int> a;
        for (int c = 1; c <= n; ++c)
        {
            int temp; fin >> temp;

            if (itoi.count(temp) == 0)
            {
                itoi[temp] = count;
                ++count;
            }

            a.push_back(itoi[temp]);
        }

        vector<int> m(count, 0);
        m[a[0]] = 1;

        int l = 0, r = 0, ans = 1;
        while (r <= n - 2)
        {
            ++r;
            ++m[a[r]];

            while (m[a[r]] > 1 && l < r)
            {
                --m[a[l]];
                ++l;
            }

            ans = max(ans, r - l + 1);
        }

        fout << ans << '\n';
    }

    return 0;
}
