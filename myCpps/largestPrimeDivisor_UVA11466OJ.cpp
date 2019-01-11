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


const int N = 10000000;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    vector<long long> primes;
    
    for (long long i = 2; i <= N; ++i)
    {
        if (isPrime[i] == true)
        {
            primes.push_back(i);

            for (long long j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int size0 = primes.size();

    while (true)
    {
        long long n = 0;
        cin >> n;
        if (n == 0) break;

        if (n < 0) n = -1 * n;

        long long _count = 0, ans = -1;
        for (int i = 0; i <= size0 - 1; ++i)
        {
            if (n < primes[i])
            {
                break;
            }
            else if (n % primes[i] == 0)
            {
                ans = primes[i];
                ++_count;

                while (n % primes[i] == 0)
                {
                    n /= primes[i];
                }
            }
        }

        if (n > 1)
        {
            ans = n;
            ++_count;
        }

        if (_count > 1)
        {
            cout << ans << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }

   	cout.flush();
   	return 0;
}
