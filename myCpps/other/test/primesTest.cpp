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
    freopen("primesTest.in", "r", stdin);
    long long n=0;
    cin >> n;
    if(n==0)
    {
        return 0;
    }
    
    long long j;
    long long index=0;
    vector<bool> isPrime(n+1,true);
    vector<int> prime;
    isPrime[1]=false;
    
    for(long long i=2;i<n;++i)
    {
        if(isPrime[i]==true)
        {
            prime.push_back(i);

            for(long long j=i*i;j<n;j+=i)
            {
                isPrime[j]=false;
            }

        }
    }

    for(int i=0;i<=prime.size()-1;++i)
    {
        cout << prime[i] << " ";
    }
    
    return 0;
}