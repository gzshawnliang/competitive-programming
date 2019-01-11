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

ifstream fin("primeDistance_UVA10140.in");
ofstream fout("primeDistance_UVA10140.out");

const int N = 46341;
const int INTMAX = 2147483647;

int main()
{
    vector<bool> isPrime(1000000, true);
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
        long long l = 0, u = 0;
        fin >> l >> u;
        if (l == 0) break;

        vector<bool> isPrimeNow(u - l + 1, true);
        for (int i = 0; i <= size0 - 1; ++i)
        {
            int b = l / primes[i];
            while (b <= 1 || primes[i] * b < l)
            {
                ++b;
            }

            for (long long j = primes[i] * b; j <= u; j += primes[i])
            {
                if (j >= l)
                {
                    isPrimeNow[j - l] = false;
                }
            }
        }

        if (l == 1)
        {
            isPrimeNow[0] = false;
        }

        long long lastPrime = -1;
        long long _min = INTMAX, minL, minR;
        long long _max = -1 * INTMAX, maxL, maxR;
        for (long long i = l; i <= u; ++i)
        {
            if (isPrimeNow[i - l] == true)
            {
                if (lastPrime != -1)
                {
                    if (i - lastPrime < _min)
                    {
                        _min = i - lastPrime;
                        minL = lastPrime;
                        minR = i;
                    }

                    if (i - lastPrime > _max)
                    {
                        _max = i - lastPrime;
                        maxL = lastPrime;
                        maxR = i;
                    }
                }

                lastPrime = i;
            }
        }

        if (_min == INTMAX)
        {
            fout << "There are no adjacent primes.\n";
        }
        else
        {
            fout << minL << ',' << minR << " are closest, " << maxL << ',' << maxR << " are most distant.\n";
        }
    }

    return 0;
}