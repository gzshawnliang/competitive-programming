/*
===========================================================
* @Name:           1367C Social Distance
* @Author:         Shawn
* @create Time:    2020/6/16 22:35:38
* @url:            https://codeforces.com/gym/1367/problem/C
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

void solve()
{
    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        int n, k; cin >> n >> k;

        int las1 = -1, ans = 0;
        string a(n, 0); cin >> a;
        
        string front = "1";
        for (int c = 1; c <= k; ++c) front += "0";

        string back = "";
        for (int c = 1; c <= k; ++c) back += "0";
        back += "1";

        a = front + a + back;
        n = a.size();

        for (int i = 0; i <= n - 1; ++i)
        {
            if (a[i] == '1')
            {
                if (las1 >= 0)
                {
                    ans += ((i - las1 - (k + 1)) / (k + 1));
                }
                las1 = i;
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
    freopen("CF_1367C_SocialDistance.in", "r", stdin);
    freopen("CF_1367C_SocialDistance.out", "w", stdout);
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