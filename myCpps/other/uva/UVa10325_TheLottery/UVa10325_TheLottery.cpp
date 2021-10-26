/*
===========================================================
* @Name:           UVa-10325 The Lottery
* @Author:         Thomas
* @create Time:    2020/2/25 8:37:38
* @url:            
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

/**
 * a和b最大公因数，greatest common divisor
 * @param  {ull} a : 
 * @param  {ull} b : 
 * @return {ull}   : 最大公因数
 */

ull gcd(ull a, ull b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}

/**
 * a和b的最小公倍数lcm
 * 根据唯一分解定理容易得到 gcd(a,b) x lcm(a,b)=axb
 * 将 a,b 分解为一系列素数的若干次幂的乘积，显然 gcd 总是取较小的幂，
 * lcm 总是取较大的幂。唯一需要注意的是不要写 lcm=a⋅b/gcd(a,b) ，
 * 而要改为 lcm= (a/gcd(a,b)) xb ，否则可能会导致乘法溢出。
 * @param  {ull} a : 
 * @param  {ull} b : 
 * @return {ull}   : 最小公倍数
 */
ull lcm(ull a, ull b) 
{ 
    return (a / gcd(a, b)) * b;  
      
}


void solve()
{
    ull N;
    ull M;
    while (cin >> N >>M)
    {
        vector<ull> a(M);
        for (ull i = 0; i <= M - 1; ++i)
        {
            cin >> a[i];
        }

        ull ans = 0;
        ull total = (1 << M); //枚举2^M种状态


        //每个数都有2种状态 ，对应着取与不取。
        //枚举2^M-1 {00000}~{11111}种状态,第0{00000}个不需要
        for (ull i = 1; i <= total - 1; ++i)
        {
            ull ret = 1;
            ull oneCount = 0;       //当前二进制1的数量

            for (ull j = 0; j <= M -1; ++j)
            {
                if ((1 << j) & i) //是否选第j个
                {
                    ++oneCount; 
                    ret=lcm(ret,a[j]);
                }
            }

            //1的数量，是奇数则加 偶数则减
            if ((oneCount % 2) == 1) 
                ans += (N / ret); 
            else
                ans -= (N / ret);
        }
        ans =N-ans;
        cout << ans << "\n";
    }
    
    //assert(N > 0);
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("UVa10325_TheLottery.in", "r", stdin);
        //freopen("UVa10325_TheLottery.out", "w", stdout);
    #endif    

    solve();
    //cout << lcm(4,18);

    cout.flush();
    return 0;
}