#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    long long testCase; cin >> testCase;
    for (long long t = 1; t <= testCase; ++t)
    {
        long long m, k; cin >> m >> k;

        long long l = 0, r = 0;
        vector<long long> a(m);
        for (long long i = 0; i <= m - 1; ++i)
        {
            cin >> a[i];

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
            if (fence_bool[i] == 1) cout << " /";
            if (i > 0) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }

   	cout.flush();
   	return 0;
}

