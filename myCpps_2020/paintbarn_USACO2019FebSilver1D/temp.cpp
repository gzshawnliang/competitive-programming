#include <bits/stdc++.h>

using namespace std;

ifstream fin("temp.in");
ofstream fout("temp.out");

const int maxL = 1000001;

int main()
{
    int n, k; fin >> n >> k;

    vector<int> a(maxL + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int l, r; fin >> l >> r; --r;
        ++l; ++r;

        ++a[l - 1]; --a[r + 1];
    }

    int ans = 0, nowL = 0;
    for (int x = 0; x <= maxL; ++x)
    {
        if (nowL == k) ++ans;

        nowL += a[x];
    }

    fout << ans << '\n';

    return 0;
}
