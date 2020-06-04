/*
===========================================================
* @Name:           939E Maximize!
* @Author:         Thomas
* @create Time:    2020/6/3 9:13:19
* @url:            https://codeforces.com/contest/939/problem/E
* @Description:    三分搜索
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
    cout << fixed << setprecision(6);
    int Q;
    cin >> Q;

    vector<ill> S;      //S数组
    vector<ill> sum;    //S数组第i个元素之前的和

    auto f = [&](int i) {
        int sSize = S.size();
        if (sSize == 1)
            return (double)S.back();

        ill ret = sum[i];

        if (i == sSize - 1)
            return 1.0 * ret / (1.0 * (i + 1));
        else
            return 1.0 * (ret + S.back() * 1LL) / (1.0 * (i + 1 + 1));
    };

    while (Q--)
    {
        int q;
        ill x;
        cin >> q;

        if (q == 1)
        {
            cin >> x;

            if (S.size() > 0)
                sum.push_back(sum.back()+x);
            else
                sum.push_back(x);

            S.push_back(x);
        }
        else
        {

            int right = S.size() - 1, left = 0;
            while (right - left > 1)
            {
                int midL = left + (right - left) / 3.0;
                int midR = right - (right - left) / 3.0;

                //如果是求最大值的话这里判>=即可
                //如果是求最小值的话这里判<=即可
                if (f(midL) <= f(midR))
                    right = midR - 1;
                else
                    left = midL + 1;
            }

            cout << (double)S.back() - min(f(left), f(right)) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_939E_Maximize!.in", "r", stdin);
    freopen("CF_939E_Maximize!.out", "w", stdout);
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