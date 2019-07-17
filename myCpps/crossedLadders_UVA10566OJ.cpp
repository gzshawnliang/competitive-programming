#include <bits/stdc++.h>

using namespace std;


const double eps = 1e-9;

bool check(double m, double x, double y, double c)
{
    double a = sqrt(x * x - m * m), b = sqrt(y * y - m * m);
    double p = x * b / (a + b), q = y * a / (a + b);
    double k = (p + q + m) / 2;
    double s = sqrt(k * (k - p) * (k - q) * (k - m));
    double h = 2 * s / m;

    return h < c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(3);
    while (true)
    {
        double x = 0.0, y = 0.0, c = 0.0; cin >> x >> y >> c;
        if (x + y + c == 0.0) break;

        double l = 0.0, r = min(x, y);
        while (true)
        {
            double m = (l + r) / 2.0;

            if (check(m, x, y, c) == true)
            {
                r = m;
            }
            else
            {
                l = m;
            }

            if (abs(l - r) < eps)
            {
                break;
            }
        }

        cout << l << '\n';
    }

   	cout.flush();
   	return 0;
}

