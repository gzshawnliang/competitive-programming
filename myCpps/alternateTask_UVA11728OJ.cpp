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


const int N = 1000;

int divSum(int n, vector<int> & primes)
{
    int size0 = primes.size(), ans = 1;
    for (int i = 0; primes[i] * primes[i] <= n; ++i)
    {
        int pf = primes[i], _pow = 0;
        while (n % pf == 0)
        {
            n /= pf;
            ++_pow;
        }

        ans *= (int)(pow((double)pf, _pow + 1.0) - 1) / (pf - 1);
    }

    if (n > 1)
    {
        ans *= (int)(pow((double)n, 2.0) - 1) / (n - 1);
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<bool> isPrime(N, true);
    isPrime[0] = false, isPrime[1] = false;
    vector<int> primes;
    
    for (int i = 2; i <= N; ++i)
    {
        if (isPrime[i] == true)
        {
            primes.push_back(i);

            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> ans(1001, -1);
    for (int n = 1; n <= 1000; ++n)
    {
        int res = divSum(n, primes);

        if (res <= 1000)
        {
            ans[res] = n;
        }
    }

    int C = 0;
    while (true)
    {
        ++C;

        int n = 0;
        cin >> n;
        if (n == 0) break;

        cout << "Case " << C << ": " << ans[n] << '\n';
    }

   	cout.flush();
   	return 0;
}
