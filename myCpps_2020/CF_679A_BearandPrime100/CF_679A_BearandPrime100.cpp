/*
===========================================================
* @Name:           679A Bear and Prime 100
* @Author:         Shawn
* @create Time:    2020/5/16 16:38:19
* @url:            https://codeforces.com/contest/679/problem/A
* @Description:    
===========================================================
*/

#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 50;

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

    int cnt = 0, num = -1;
    for (auto x: primes)
    {
        cout << x << '\n'; cout.flush();

        string in; cin >> in;
        if (in == "yes")
        {
            ++cnt;
            num = x;
            if (cnt == 2)
            {
                cout << "composite\n" << '\n';

                return;
            }
        }
    }

    if (cnt == 1 && num * num <= 100)
    {
        cout << num * num << '\n'; cout.flush();

        string in; cin >> in;
        if (in == "yes") cout << "composite\n";
        else             cout << "prime\n";
    }
    else
    {
        cout << "prime\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        //freopen("CF_679A_BearandPrime100.in", "r", stdin);
        //freopen("CF_679A_BearandPrime100.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}