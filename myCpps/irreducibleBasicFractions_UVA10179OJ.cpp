#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
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
        int n = 0;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        int ans = 1;
        for (int i = 2; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                ans *= i - 1;
                n /= i;

                while (n % i == 0)
                {
                    ans *= i;
                    n /= i;
                }
            }

            if (i == 2)
            {
                i = 1;
            }
        }

        if (n > 1)
        {
            ans *= n - 1;
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
