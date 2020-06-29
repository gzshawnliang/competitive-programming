/*
===========================================================
* @Name:           1367E Necklace Assembly
* @Author:         Shawn
* @create Time:    2020/6/16 22:35:38
* @url:            https://codeforces.com/contest/1367/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const int N = 2000;

void solve()
{
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

    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        
        vector<int> mp('z' + 1, 0);
        for (char ch:s)
        {
            ++mp[ch];
        }

        vector<int> cntUse(n + 1, 0);
        for (int x = 1; x <= n; ++x)
        {
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                cntUse[x] += (mp[ch] / x);
            }
        }

        int ans = 0;
        for (int x = 1; x <= k; ++x)
        {
            if (x > k || x > n) break;

            if (k % x == 0)
            {
                int maxUse = n;
                while (cntUse[maxUse] < x) --maxUse;
                
                ans = max(ans, maxUse * x);
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1367E_NecklaceAssembly.in", "r", stdin);
    freopen("CF_1367E_NecklaceAssembly.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}