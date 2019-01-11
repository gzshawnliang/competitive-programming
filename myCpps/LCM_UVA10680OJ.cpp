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
    vector<long long> primes, out(N + 1, -1);
    
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

        if (n == 0)
        {
            break;
        }
        else if (out[n] != -1)
        {
            cout << out[n] << '\n';
        }

        long long ans = 1;
        for (int i = 0; i <= size0 - 1; ++i)
        {
            long long now = primes[i];

            if (now > n)
            {
                break;
            }
            else if (now == 5)
            {
                long long temp = now;
                while (temp <= n)
                {
                    ans = ans * now;
                    temp *= now;
                }
                while (ans % 10 == 0)
                {
                    ans /= 10;
                }

                ans = to_string(ans).back() - '0';
            }
            else
            {
                long long temp = now;
                while (temp <= n)
                {
                    ans *= now;
                    temp *= now;

                    if (now > 5)
                    {
                        ans %= 10;
                    }
                }
            }
        }

        out[n] = ans;
        cout << ans << '\n';  
    }

   	cout.flush();
   	return 0;
}
