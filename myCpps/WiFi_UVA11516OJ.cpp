#include <bits/stdc++.h>

using namespace std;


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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(1);

    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int n, m; cin >> n >> m;

        vector<int> a(m);
        for (int i = 0; i <= m - 1; ++i)
        {
            cin >> a[i]; a[i] *= 2;
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

        cout << (double)l / 2.0 << '\n';
    }

   	cout.flush();
   	return 0;
}

