/*
===========================================================
* @Name:           UVa-11481 Arrange the Numbers
* @Author:         Shawn
* @create Time:    2020/2/27 20:52:32
* @url:            
* @Description:    todo
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ull = long long;

const int MOD=1000000007;

/**
 * 从M个数中取N个处理有多少种方案,动态规划
 * https://zhuanlan.zhihu.com/p/74787475
 */
void initDataC(int N,vector<vector<int>> & c)
{
    c[0][0]=1;
    for (int i = 0 ; i <= N ; ++i)
    {
        for (int j = 0 ; j <= i ; ++j)
        {
            if (j == 0)
                c[i][j] = 1;
            else if (i == 1)
                c[i][j] = 1;
            else if (i == j)
                c[i][j] = 1;
            else
                c[i][j] = (1LL * c[i - 1][j - 1] % MOD) + (1LL * c[i - 1][j] % MOD) % MOD;
        }
    }
}

void initDataP(int N,vector<int> & p)
{
    p[0]=1;
    for (int i = 1 ; i <= N ; ++i)
        p[i] = 1LL * p[i - 1] * i % MOD;
}

void solve()
{
    int T;
    cin >> T;
    for (int t = 0; t <= T ; ++t)
    {
        int N,M,K;
        cin >> N >> M >> K;
        N=100;
        vector<vector<int>> C(N+5,vector<int>(N+5,0));
        vector<int> P(N+5);
        initDataC(N,C);
        int i=C[3][2];

        initDataP(N,P);
        i=P[3];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("UVa11481_ArrangetheNumbers.in", "r", stdin);
        //freopen("UVa11481_ArrangetheNumbers.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}