#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define ll long long

ifstream fin("minimumSumLCM_10791.in");
ofstream fout("minimumSumLCM_10791.out");

int N = 50000;

int main()
{
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

    int T = 0;
    while (true)
    {
        ++T;

        long long n = 0;
        fin >> n;
        if (n == 0) break;

        if (n == 1)
        {
            fout << "Case " << T << ": 2\n";
        }
        else
        {
            long long count = 0, ans = 0;
            for (int i = 0; primes[i] * primes[i] <= n; ++i)
            {
                long long a = 1, now = primes[i];
                while (n % now == 0)
                {
                    a *= now;
                    n /= now;
                }

                if (a > 1)
                {
                    ++count;
                    ans += a;
                }
            }
            if (n > 1)
            {
                ++count;
                ans += n;
            }

            if (count == 1)
            {
                ++ans;
            }

            fout << "Case " << T << ": " << ans << '\n';
        }
    }

    return 0;
}