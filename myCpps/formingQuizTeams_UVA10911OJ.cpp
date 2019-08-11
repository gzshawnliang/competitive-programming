#include <bits/stdc++.h>

using namespace std;


const int N = 16;
const double inf = 30000.0;

int pow2(int x)
{
    return (1 << x);
}

struct point
{
    int x;
    int y;
};
point _point(int x, int y)
{
    point temp{x, y}; return temp;
}

double dis(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(2);

    vector<vector<int>> a(N + 1);
    for (int x = 0; x <= pow2(N) - 1; ++x)
    {
        bitset<16> b(x);

        int c = 0;
        for (int i = 0; i <= N - 1; ++i)
        {
            c += b[i];
        }

        a[c].push_back(x);
    }

    int t = 0;
    while (true)
    {
        int n = 0; cin >> n;
        if (n == 0) break;

        ++t;

        n *= 2;
        
        vector<point> points(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            string useless; cin >> useless;
            cin >> points[i].x >> points[i].y;
        }

        vector<double> dp(pow2(n), inf); dp[0] = 0.0;
        for (int c = 2; c <= n; c += 2)
        {
            int sizeNow = a[c].size();
            for (int i = 0; i <= sizeNow - 1 && a[c][i] <= pow2(n) - 1; ++i)
            {
                int now = a[c][i];
                bitset<16> now_b(now);

                for (int p = 0; p <= n - 1; ++p)
                {
                    for (int q = 0; q <= n - 1; ++q)
                    {
                        if (now_b[p] == 1 && now_b[q] == 1 && p != q)
                        {
                            bitset<16> last_b = now_b;
                            last_b[p] = 0; last_b[q] = 0;

                            int last = last_b.to_ulong();

                            dp[now] = min(dp[now], dp[last] + dis(points[p], points[q]));
                        }
                    }
                }
            }
        }

        double ans = dp[pow2(n) - 1];
        ans = (int)(ans * 100.0 + 0.5) / 100.0;

        cout << "Case " << t << ": " << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

