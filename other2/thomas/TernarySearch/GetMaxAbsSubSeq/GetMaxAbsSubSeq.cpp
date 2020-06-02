/*
===========================================================
 * @名称:    动态规划：绝对值最大的子序列和以及其区间
 * @作者:    Thomas 
 * @创建时间: 2020-06-02 20:29:04 
 * @修改人:   Thomas 
 * @修改时间: 2020-06-02 20:29:04 
 * @备注:    https://blog.csdn.net/insistGoGo/article/details/9450979
 * @题目来源： 
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; ++i)
        cin >> a[i];

    auto solveDp=[&]()
    {
        vector<int> dpMax(n);
        vector<int> dpMin(n);
        dpMax[0]=a[0];
        dpMin[0]=a[0];
        int maxV=a[0];
        int minV=a[0];
        for (int i = 1; i <= n - 1; ++i)
        {
            dpMax[i] =max(dpMax[i-1]+a[i],a[i]);
            maxV=max(maxV,dpMax[i]);

            dpMin[i] =min(dpMin[i-1]+a[i],a[i]);
            minV=min(minV,dpMin[i]);

        }
        cout << maxV << " " << minV << " ";
    };

    auto solveBf=[&]()
    {
        int maxV=INT_MIN;
        int minV=INT_MAX;
        
        for (int i = 0; i <= n-1; ++i)
        {
            int sum1=0;
            for (int j = i ; j <= n-1; ++j)
            {
                sum1+=a[j];
                maxV=max(maxV,sum1);
                minV=min(minV,sum1);
            }
        }        
        cout << maxV << " " << minV << " ";
    };
    cout << "dp:";
    auto startTime = std::chrono::high_resolution_clock::now();
    solveDp();
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;    

    cout << "bf:";
    startTime = std::chrono::high_resolution_clock::now();
    solveBf();
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;       
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("GetMaxAbsSubSeq.in", "r", stdin);
    //freopen("test.out", "w", stdout);
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