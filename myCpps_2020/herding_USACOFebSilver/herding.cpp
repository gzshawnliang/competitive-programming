#include <bits/stdc++.h>

using namespace std;

ifstream fin("herding.in");
ofstream fout("herding.out");

int main()
{
    int n; fin >> n;

    vector<int> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }
    sort(a.begin(), a.end());

    int ansMin = INT_MAX;

    if (a[n - 2] - a[0] + 1 == n - 1 && a[n - 1] > a[n - 2] + 2)
    {
        ansMin = 2;
    }
    else if (a[n - 1] - a[1] + 1 == n - 1 && a[0] < a[1] - 2)
    {
        ansMin = 2;
    }
    else
    {
        int l = 0, r = 1;
        while (r <= n - 1)
        {
            if (a[r] - a[l] + 1 > n)
            {
                ++l;
            }
            else
            {
                ansMin = min(ansMin, n - (r - l + 1));

                ++r;
            }
        }
    }

    fout << ansMin << '\n';
    fout << max(a[n - 2] - a[0] - (n - 1) + 1, a[n - 1] - a[1] - (n - 1) + 1) << '\n';

    return 0;
}
