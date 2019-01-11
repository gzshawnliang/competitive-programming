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


const int N = 1000000;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<bool> isPrime(N + 1, true); 
    isPrime[0] = false, isPrime[1] = false;
    vector<int> primes;
    
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

    vector<int> mu(N + 1, -2), M(N + 1, 0);
    mu[1] = 1; M[1] = 1;
    for (long long n = 2; n <= N; ++n)
    {
        long long temp = n, _count = 0;
        for (int i = 0; primes[i] * primes[i] <= temp; ++i)
        {
            long long now = primes[i];

            if (temp % (now * now) == 0)
            {
                mu[n] = 0;
                break;
            }
            else if (temp % now == 0)
            {
                ++_count;
                temp /= now;
            }
        }

        if (mu[n] == -2)
        {
            if (temp > 1)
            {
                ++_count;
            }

            if (_count % 2 == 0)
            {
                mu[n] = 1;
            }
            else
            {
                mu[n] = -1;
            }
        }

        M[n] = M[n - 1] + mu[n];
    }

    while (true)
    {
        int n = 0;
        cin >> n;
        if (n == 0) break;

        cout << setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << '\n';
    }

   	cout.flush();
   	return 0;
}
