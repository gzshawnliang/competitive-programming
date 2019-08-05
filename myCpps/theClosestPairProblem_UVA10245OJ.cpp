#include <bits/stdc++.h>

using namespace std;


const double inf = 1e8;

struct point
{
    double x;
    double y;

    bool operator < (const point & temp) const
    {
        return x < temp.x;
    }
};

double dis(point p1, point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(4);

    int t = 0;
    while (true)
    {
        int n = 0; cin >> n;
        if (n == 0) break;

        ++t;
        if (t == 77)
        {
            for (int __s = 0; __s == 0; ++__s);
        }

        vector<point> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].x >> a[i].y;
        }
        sort(a.begin(), a.end());

        if (n == 1)
        {
            cout << "INFINITY\n";
            continue;
        }

        double ans = inf, nowDis_2;
        for (int i = 0; i <= n - 2;)
        {
            nowDis_2 = dis(a[i], a[i + 1]);
            ans = min(ans, nowDis_2);

            int top = i;
            while (top <= n - 1)
            {
                if ((a[top].x - a[i].x) * (a[top].x - a[i].x) > nowDis_2)
                {
                    break;
                }

                ++top;
            }
            --top;

            for (int p = i; p <= top; ++p)
            {
                for (int q = p + 1; q <= top; ++q)
                {
                    double temp = dis(a[p], a[q]);
                    ans = min(ans, temp);
                }
            }

            i = top;
        }

        if (ans < inf)
        {
            double ans_d = sqrt((double)ans);

            cout << ans_d << '\n';
        }
        else
        {
            cout << "INFINITY\n";
        }
    }

   	cout.flush();
   	return 0;
}

