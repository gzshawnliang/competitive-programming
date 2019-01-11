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
        int n = 0, temp;
        cin >> n;
        if (n == 0) break;

        temp = n;

        int ans = 0;
        for (int i = 2; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                ++ans;

                while (n % i == 0)
                {
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
            ++ans;
        }

        cout << temp << " : " << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
