/*
===========================================================
* @Name:           578C Weakness and Poorness
* @Author:         Thomas
* @create Time:    2020/5/31 21:19:29
* @url:            https://codeforces.com/contest/578/problem/C
* @Description:    三分+dp，double精度不够，long double才行
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
using ldo = long double;

const ldo eps = 1e-12;

void solve()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    //暴力：绝对值最大的子序列和以及其区间
    //超时
    auto f2 = [&](ldo x) 
    {
        vector<ldo> s(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            s[i] = a[i] - x;

        ldo weakness = 0;
        for (int i = 1; i <= n; ++i)
        {
            ldo poorness = s[i];
            weakness = max(weakness, abs(poorness));
            for (int j = i + 1; j <= n; ++j)
            {
                poorness += s[j];
                weakness = max(weakness, abs(poorness));
            }
        }
        return weakness;
    };

    //动态规划：绝对值最大的子序列和以及其区间
    //https://blog.csdn.net/insistGoGo/article/details/9450979
    auto f = [&](ldo x) 
    {
        vector<ldo> s(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            s[i] = a[i] - x;

        ldo weakness = s[1];
        // ldo maxhere = s[1];
        vector<ldo> dpMax(n + 1, 0);
        vector<ldo> dpMin(n + 1, 0);
        dpMax[1]=s[1];
        dpMin[1]=s[1];
        for (int i = 2; i <= n; ++i)
        {
            dpMax[i] = max(dpMax[i - 1] + s[i],s[i]);
            dpMin[i] = min(dpMin[i - 1] + s[i], s[i]);

            if (abs(dpMax[i]) > abs(weakness))
                weakness = dpMax[i];

            if (abs(dpMin[i]) > abs(weakness))
                weakness = dpMin[i];
        }
        return abs(weakness);
    };    

    //三分法
    ldo right = 10000.0, left = -10000.0;
    ldo ans=f(left);
    while (right-left>eps)
    {
        ldo midL = left + (right - left) / 3.0;
        ldo midR = right - (right - left) / 3.0;


        ldo fL = f(midL);
        ldo fR = f(midR);

        //如果是求最大值的话这里判>=即可
        //如果是求最小值的话这里判<=即可
        if (fL <= fR)
            right = midR;
        else
            left = midL;

        ans = fL;

        //cerr << right << " " << left << " " << right - left << " " << ans << endl;
    }
    cout << ans << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_578C_WeaknessandPoorness.in", "r", stdin);
    //freopen("CF_578C_WeaknessandPoorness.out", "w", stdout);
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




