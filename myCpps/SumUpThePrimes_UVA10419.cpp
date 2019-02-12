#include <bits/stdc++.h>

using namespace std;

ifstream fin("SumUpThePrimesAC_UVA10419.in");
ofstream fout("SumUpThePrimesAC_UVA10419.out");

const int maxP = 300;

int compare(int x, int y)
{
    return to_string(x) < to_string(y);
}

int main()
{
    vector<bool> isPrime(maxP + 1, true); 
    isPrime[0] = false, isPrime[1] = false;
    vector<int> primes;
    
    for (int i = 2; i <= maxP; ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= maxP; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    primes.push_back(2);
    for (int x = 3; x <= 300; ++x)
    {
        if (isPrime[x] == true)
        {
            for (int c = 1; c <= 2; ++c)
            {
                primes.push_back(x);
            }
        }
    }

    sort(primes.begin(), primes.end(), compare);
    
    int _case = 0, sizeP = primes.size();

    while (true)
    {
        int x = 0, t = 0; fin >> x >> t;
        if (x + t == 0) break; ++_case;
        
        fout << "CASE " << _case << ":\n";

        
    }

    return 0;
}
