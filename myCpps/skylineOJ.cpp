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

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int totalCase;
    cin >> totalCase;

    for (int c = 1; c <= totalCase; ++c)
    {
        int n;
        cin >> n;

        vector<int> h(n), w(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> h[i];
        }
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> w[i];
        }

        vector<int> dpI(n), dpD(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            dpI[i] = w[i]; dpD[i] = w[i];

            for (int j = 0; j <= i - 1; ++j)
            {
                if (h[i] > h[j])
                {
                    dpI[i] = max(dpI[i], dpI[j] + w[i]);
                }
                else if (h[i] < h[j])
                {
                    dpD[i] = max(dpD[i], dpD[j] + w[i]);
                }
            }
        }

        int ans1 = *max_element(dpI.begin(), dpI.end()), ans2 = *max_element(dpD.begin(), dpD.end());

        cout << "Case " << c << ". ";
        if (ans1 >= ans2)
        {
            cout << "Increasing (" << ans1 << "). Decreasing (" << ans2 << ").\n";
        }
        else
        {
            cout << "Decreasing (" << ans2 << "). Increasing (" << ans1 << ").\n";
        }
    }

   	cout.flush();
   	return 0;
}
