
// https://codeforces.com/contest/1355/submission/80323017
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    ll maxN = max(B + C, D) + 5;
    vector<ll> sum(maxN, 0);

    for (int x = A; x <= B; ++x)
        ++sum[x + B];

    for (int x = A; x <= B; ++x)
        --sum[x + C + 1];

    for (int i = 1; i <= maxN - 1; ++i)
        sum[i] += sum[i - 1];

    for (int i = maxN - 2; i >= 0; --i)
        sum[i] += sum[i + 1];

    ll ans = 0;
    for (int i = C; i <= D; ++i)
        ans += sum[i + 1];

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    auto start = std::chrono::high_resolution_clock::now();
    freopen("CF_1355C_CountTriangles.in", "r", stdin);
    //freopen("cf_ac.out", "w", stdout);
#endif

    solve();

    cout.flush();

#ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;
#endif

    return 0;
}