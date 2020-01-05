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


struct crossing
{
    int x;
    int y;
    int k;
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int d, n; cin >> d >> n;

    vector<crossing> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i].x >> a[i].y >> a[i].k;
    }

    vector<int> ans;
    for (int xn = 0; xn <= 128; ++xn)
    {
        for (int yn = 0; yn <= 128; ++yn)
        {
            if (xn == 5 && yn == 5)
            {
                cout << "";
            }

            int total = 0;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (a[i].x >= xn - d && a[i].x <= xn + d && a[i].y >= yn - d && a[i].y <= yn + d)
                {
                    total += a[i].k;
                }
            }

            if (total > 0)
            {
                ans.push_back(total);
            }
        }
    }

    sort(ans.begin(), ans.end());

    int size = ans.size();
    int i = size - 2;
    int count = 1, MAX = ans[size - 1];
    while (ans[i] == MAX)
    {
        --i;
        ++count;
    }

    cout << count << ' ' << MAX << '\n';

   	cout.flush();
   	return 0;
}
