#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;


bool solve(int l, int m, vector<int> & dis)
{
    int total = 0, n = dis.size(), last = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        if (dis[i] - dis[last] < l)
        {
            ++total;
        }
        else
        {
            last = i;
        }
    }

    return total <= m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int ld, n, m; cin >> ld >> n >> m;
    vector<int> dis(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        cin >> dis[i];
    }
    dis[0] = 0;
    dis[n + 1] = ld;

    int l = 0, r = ld, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (solve(mid, m, dis) == true)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << '\n';

   	cout.flush();
   	return 0;
}
