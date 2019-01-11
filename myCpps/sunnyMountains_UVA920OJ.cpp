#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <climits>

using namespace std;


struct point
{
    int x;
    int y;

    bool operator<(const point & temp) const
    {
        if (x != temp.x)
        {
            return x > temp.x;
        }
        else
        {
            return y < temp.y;
        }
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(2);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n; cin >> n;
        double total = 0.0;

        vector<point> m(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> m[i].x >> m[i].y;
        }

        sort(m.begin(), m.end());

        point now = m[0];
        for (int i = 1; i <= n - 1; ++i)
        {
            if (m[i].y > now.y)
            {
                double h = (double)m[i].y - (double)now.y,
                       k = ((double)m[i].y - (double)m[i - 1].y) / ((double)m[i].x - (double)m[i - 1].x),
                       l = h / k;

                total += sqrt(l * l + h * h);

                now = m[i];
            }
        }

        cout << total << '\n';
    }

   	cout.flush();
   	return 0;
}
