#include <bits/stdc++.h>

using namespace std;

ifstream fin("talent.in");
ofstream fout("talent.out");

const int inf = INT_MAX / 10;
const pair<int, int> _null = make_pair(-1, -1);

bool check(int w, double mid, vector<int> &a, vector<int> &b)
{
    int n = a.size() - 1;

    vector<double> f(w + 1, -1 * inf);
    f[0] = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = w; j >= 0; --j)
        {
            if (j == 0)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            int last = min(w, j + a[i]);

            f[last] = max(f[last], f[j] + b[i] - mid * a[i]);
        }
    }

    return f[w] >= 0;
}

int main()
{
    int n, w; fin >> n >> w;

    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i] >> b[i];
    } 

    double l = 0.0, r = double(inf);
    for (int c = 1; c <= 100; ++c)
    {
        double mid = (l + r) / 2;

        if (check(w, mid, a, b) == true)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    fout << (int)(l * 1000.0) << '\n';

    return 0;
}
