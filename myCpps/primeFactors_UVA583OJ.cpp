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
        bool first = true;
        long long n = 0;
        cin >> n;
        if (n == 0) break;

        cout << n << " = ";
        if (n < 0)
        {
            cout << "-1";
            n *= -1;
            first = false;
        }

        long long ans = 1, temp = n;
        for (long long i = 2; i * i <= n; i += 2)
        {
            while (n % i == 0)
            {
                if (first == true)
                {
                    first = false;
                }
                else
                {
                    cout << " x ";
                }

                cout << i;

                n /= i;
            }
            if (i == 2)
            {
                i = 1;
            }
        }

        if (n > 1)
        {
            if (first == true)
            {
                first = false;
            }
            else
            {
                cout << " x ";
            }

            cout << n;
        }

        cout << '\n';
    }

   	cout.flush();
   	return 0;
}
