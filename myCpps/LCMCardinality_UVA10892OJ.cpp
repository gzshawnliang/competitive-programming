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
        long long n = 0;
        cin >> n;
        if (n == 0) break;

        long long ans = 1, temp = n;
        for (long long i = 2; i * i <= n; i += 2)
        {
            long long c = 1;
            while (n % i == 0)
            {
                ++c;
                n /= i;
            }
            ans *= c * 2 - 1;

            if (i == 2)
            {
                i = 1;
            }
        }

        if (n > 1)
        {
            ans *= 3;
        }

        ans = ans / 2 + 1;

        cout << temp << ' ' << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
