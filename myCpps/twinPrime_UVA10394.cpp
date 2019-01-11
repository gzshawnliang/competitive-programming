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

ifstream fin("twinPrime_UVA10394.in");
ofstream fout("twinPrime_UVA10394.out");

const int N = 18409201;

int main()
{
    long long _count = 1, last = 2;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    vector<string> ans;

    for (long long i = 2; _count <= 100000; ++i)
    {
        if (isPrime[i] == true)
        {
            if (i - last == 2)
            {
                ans.push_back('(' + to_string(i - 2) + ", " + to_string(i) + ')');
                ++_count;
            }
            last = i;

            for (long long j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    while (true)
    {
        long long s = 0;
        fin >> s;
        if (s == 0) break;

        fout << ans[s - 1] << '\n';
    }

    return 0;
}