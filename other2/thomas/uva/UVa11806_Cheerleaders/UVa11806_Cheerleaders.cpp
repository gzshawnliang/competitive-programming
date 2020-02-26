/*
===========================================================
* @Name:           UVa-11806 Cheerleaders
* @Author:         Thomas
* @create Time:    2020/2/26 19:23:32
* @url:            
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ull = long long;

vector<vector<ull>> c;

const ull MOD=1000007;

/**
 * 从M个数中取N个处理有多少种方案
 */

ull C(ull M,ull N)
{
    if (N == 0)
        return 1;
    else if (M == 1)
        return 1;
    else if (M == N)
        return 1;
    else
        return C(M - 1, N - 1) + C(M - 1, N);
}

/**
 * 从M个数中取N个处理有多少种方案,动态规划
 */
void InitData(ull M)
{
    c[0][0]=1;
    for (ull i = 0 ; i <= M ; ++i)
    {
        for (ull j = 0 ; j <= i ; ++j)
        {
            if (j == 0)
                c[i][j] = 1;
            else if (i == 1)
                c[i][j] = 1;
            else if (i == j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j - 1]%MOD) + (c[i - 1][j]%MOD)%MOD;
        }
    }
}

void solve()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T ; ++i)
    {
        int m,n,k;
        cin >> m >>n >>k;
        ull ans = 1;
        if(k>m*n)
        {
            ans=0;
        }
        else
        {
            ans =c[m*n][k];
            
            /*
            ans - (A+B+C+D)
            */
            ans -= c[(m-1)*n][k]; ans += MOD; ans %= MOD;
            ans -= c[(m-1)*n][k]; ans += MOD; ans %= MOD;
            ans -= c[m*(n-1)][k]; ans += MOD; ans %= MOD;
            ans -= c[m*(n-1)][k]; ans += MOD; ans %= MOD;

            //ans - (-AB -AC -AD-BC-BD-CD)
            ans += c[(m-2)*n][k]; ans += MOD; ans %= MOD;
            ans += c[(m-1)*(n-1)][k]; ans += MOD; ans %= MOD;
            ans += c[(m-1)*(n-1)][k]; ans += MOD; ans %= MOD;
            ans += c[(m-1)*(n-1)][k]; ans += MOD; ans %= MOD;
            ans += c[(m-1)*(n-1)][k]; ans += MOD; ans %= MOD;
            ans += c[m*(n-2)][k]; ans += MOD; ans %= MOD;

            //ans - (ABC + ABD + +ACD BCD)
            ans -= c[(m-2)*(n-1)][k]; ans += MOD; ans %= MOD;
            ans -= c[(m-2)*(n-1)][k]; ans += MOD; ans %= MOD;
            ans -= c[(m-1)*(n-2)][k]; ans += MOD; ans %= MOD;
            ans -= c[(m-1)*(n-2)][k]; ans += MOD; ans %= MOD;

            //ans - (-ABCD)
            ans += c[(m-2)*(n-2)][k]; ans += MOD; ans %= MOD;
        }

        cout << "Case " << i << ": " << ans << "\n";
    }


    
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("UVa11806_Cheerleaders.in", "r", stdin);
        freopen("UVa11806_Cheerleaders.out", "w", stdout);
    #endif    

    //solve();

    
    int n=400;
    c.assign(n+1,vector<ull>(n+1,0));
    InitData(n);
    // for (int i = 1 ; i <= n ; ++i)
    // {
    //     cout << "C("<< n << "," << i <<")=" << c[n][i] << "\n";    
    // }

    solve();
    

    cout.flush();
    return 0;
}