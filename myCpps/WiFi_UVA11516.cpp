#include <bits/stdc++.h>

using namespace std;

ifstream fin("WiFi_UVA11516.in");
ofstream fout("WiFi_UVA11516.out");

int _abs(int x)
{
    if (x > 0) return x;
    else return -x;
}

bool check(int d, int n, vector<int> & a)
{
    if (d == 3)
    {
        for (int __s = 0; __s == 0; ++__s);
    }

    int p = a[0] + d, i = 1, m = a.size();
    --n;

    while (true)
    {
        while (_abs(a[i] - p) <= d && i <= m - 1)
        {
            ++i;
        }

        if (i >= m)
        {
            return true;
        }
        else if (n == 0)
        {
            return false;
        }
        else
        {
            p = a[i] + d;
            --n;
        }
    }
}

int main()
{
    fout << fixed << setprecision(1);

    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int n, m; fin >> n >> m;

        vector<int> a(m);
        for (int i = 0; i <= m - 1; ++i)
        {
            fin >> a[i]; a[i] *= 2;
        }

        sort(a.begin(), a.end());

        int l = 0, r = 2000000;
        while (l < r)
        {
            int d = (l + r) / 2;

            if (check(d, n, a) == true)
            {
                r = d;
            }
            else
            {
                l = d + 1;
            }
        }

        fout << (double)l / 2.0 << '\n';
    }

    return 0;
}
