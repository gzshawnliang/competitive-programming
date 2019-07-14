#include <bits/stdc++.h>

using namespace std;

ifstream fin("copyingBooks_UVA714.in");
ofstream fout("copyingBooks_UVA714.out");

int main()
{
    long long testCase; fin >> testCase;
    for (long long t = 1; t <= testCase; ++t)
    {
        long long m, k; fin >> m >> k;

        long long l = 0, r = 0;
        vector<long long> a(m);
        for (long long i = 0; i <= m - 1; ++i)
        {
            fin >> a[i];

            r += a[i];
        }

        set<long long> s;
        while (l <= r)
        {
            long long mid = (l + r) / 2,
                      kc = k, i = m - 1,
                      now = 0;
            s.clear();

            while (kc >= 1)
            {
                if (kc == 1)
                {
                    while (i >= 0)
                    {
                       now += a[i];
                        --i;
                    }
                    break;
                }
                else if (i < kc - 1)
                {
                    now = 0;
                    s.insert(i + 1);
                    --kc;
                }
                else if (now + a[i] > mid)
                {
                    now = 0;
                    s.insert(i + 1);
                    --kc;
                }
                else
                {
                    now += a[i];
                    --i;
                }
            }

            if (now <= mid)
            {
                if (r == mid) break;
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        vector<long long> fence_bool(m, 0);
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            long long pos = *it;
            fence_bool[pos] = 1;
        }

        for (long long i = 0; i <= m - 1; ++i)
        {
            if (fence_bool[i] == 1) fout << " /";
            if (i > 0) fout << ' ';
            fout << a[i];
        }
        fout << '\n';
    }

    return 0;
}
