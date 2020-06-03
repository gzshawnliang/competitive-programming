/*
===========================================================
* @Name:           939E Maximize!
* @Author:         Thomas
* @create Time:    2020/6/3 9:13:19
* @url:            https://codeforces.com/contest/939/problem/E
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
const double eps = 1e-12;

void solve()
{
    cout << fixed << setprecision(6);
    int Q;
    cin >> Q;

    vector<ill> S(Q);
    vector<ill> sum(Q);
    
    int id=-1;
    double miniAvg = 0;
    bool isAdd=false;       //是否有新增值？
    bool isDiff=true;       //新增的值是否不同？
    while (Q--)
    {
        int q1;
        ill x;
        cin >> q1;

        auto f = [&](int i) 
        {
            if (id == 0)
                return (double)S[id];

            ill ret = sum[i];

            if (i == id)
                return 1.0 * ret / (1.0 * (i+1));
            else
                return 1.0 * (ret + S[id] * 1LL) / (1.0 * (i+1 + 1));
        };        

        if (q1 == 1)
        {
            ++id;
            isAdd=true;
            
            cin >> x;
            if(id>0)
            {
                if(S[id-1]!=x)
                    isDiff =true;
            }
            else
            {
                isDiff =true;
            }
            
            S[id]=x;
            if(id>0)
                sum[id] = sum[id - 1] + x;
            else 
                sum[id] = x;
        }
        else
        {
            if(isAdd==true && isDiff==true)
            {
                int right = id - 1, left = 0;
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

                miniAvg = min(f(left), f(right));
            }

            cout << (double)S[id] - miniAvg << "\n";
            isAdd=false;
            isDiff=false;
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