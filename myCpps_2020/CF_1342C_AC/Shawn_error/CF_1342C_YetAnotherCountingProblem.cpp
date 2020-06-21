/*
===========================================================
* @Name:           1342C Yet Another Counting Problem
* @Author:         Shawn
* @create Time:    2020/6/21 15:17:18
* @url:            https://codeforces.com/contest/1342/problem/C
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

class solution
{
  public:
    ill gcd(ill a, ill b)
    {
        while (b != 0)
        {
            ill r = b;
            b = a % b;
            a = r;
        }
        return a;
    }

    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill a, b, qt; cin >> a >> b >> qt;

            if (a > b) swap(a, b);
            ill lcmab = a * b / gcd(a, b);

            auto cntX=[&](ill r)
            {
                ill ans = 0; 
                
                ill rb = (r / lcmab) * lcmab;

                if (rb > 0) ans += ((r / lcmab)) * b;

                if (r > rb + b - 1) ans += b;
                else            ans += (r - rb + 1);

                return r + 1 - ans;
            };

            for (ill qc = 1; qc <= qt; ++qc)
            {
                ill l, r; cin >> l >> r;
                
                //if (qc > 1) cout << ' ';
                cout << cntX(r) - cntX(l - 1) << " ";
            }
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1342C_YetAnotherCountingProblem.in", "r", stdin);
    freopen("CF_1342C_YetAnotherCountingProblem.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}