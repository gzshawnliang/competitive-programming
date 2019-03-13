#include <bits/stdc++.h>

using namespace std;

ifstream fin("HORRIBLE.in");
ofstream fout("HORRIBLE.out");

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int n = 0, m = 0;
        fin >> n >> m;
        if (n + m == 0)
            break;

        vector<int> a(n, 0);

        for (int c = 1; c <= m; ++c)
        {
            bool command; fin >> command;

            if (command == 0)
            {
                int l, r, v; fin >> l >> r >> v;
                
                for (int i = l - 1; i <= r - 1; ++i)
                {
                    a[i] += v;
                }
            }
            else
            {
                int l, r, s = 0; fin >> l >> r;
                
                for (int i = l - 1; i <= r - 1; ++i)
                {
                    s += a[i];
                }

                for (int i = 0; i <= n - 1; ++i)
                {
                    if (i > 0) fout << ' ';
                    fout << a[i];
                }

                fout << '\n' << s << '\n';
            }
        }
    }

    return 0;
}
