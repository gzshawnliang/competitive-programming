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


const long long N = 2000000;

long long phi(long long n, vector<long long> & primes)
{
    long long ans = 1, size0 = primes.size();
    for (int i = 0; primes[i] * primes[i] <= n && i <= size0 - 1; ++i)
    {
        long long now = primes[i]; 
        if (n % now == 0)
        {
            ans *= now - 1;
            n /= now;

            while (n % now == 0)
            {
                ans *= now;
                n /= now;
            }
        }
    }

    if (n > 1)
    {
        ans *= n - 1;
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<bool> isPrime(1415 + 1, true); 
    isPrime[0] = false, isPrime[1] = false;
    vector<long long> primes;
    
    for (long long i = 2; i <= 1415; ++i)
    {
        if (isPrime[i] == true)
        {
            primes.push_back(i);

            for (long long j = i * i; j <= 1415; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<long long> depthphi(N + 1, 1);
    for (long long n = 3; n <= N; ++n)
    {
        long long ans = 0;

        depthphi[n] = depthphi[phi(n, primes)] + 1;
    }

    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int m, n; cin >> m >> n;

        long long ans = 0;
        for (int i = m; i <= n; ++i)
        {
            ans += depthphi[i];
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
