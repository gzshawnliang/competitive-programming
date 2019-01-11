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

    while (true)
    {
        int n = 0, m = 0, c = 0, r = 0;
        cin >> n >> m >> r >> c;

        if (n + m + r + c == 0)
        {
            break;
        }

        vector<string> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
        }

        int ans = 0;
        for (int y0 = 0; y0 <= n - 1 && ans >= 0; ++y0)
        {
            for (int x0 = 0; x0 <= m - 1 && ans >= 0; ++x0)
            {
                if (a[y0][x0] == '1')
                {
                    if (y0 + r - 1 > n - 1 || x0 + c - 1 > m - 1)
                    {
                        ans = -1;
                    }
                    else
                    {
                        ++ans;
                        for (int y1 = y0; y1 <= y0 + r - 1; ++y1)
                        {
                            for (int x1 = x0; x1 <= x0 + c - 1; ++x1)
                            {
                                if (a[y1][x1] == '0')
                                {
                                    a[y1][x1] = '1';
                                }
                                else
                                {
                                    a[y1][x1] = '0';
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    cout.flush();
    return 0;
}