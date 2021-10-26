#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

typedef long long ill;

void solve()
{
    int t;
    cin >> t;
    int c = 1;
    while (c <= t)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<ill>> mp(N + 1, vector<ill>(M + 1, 0));

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                cin >> mp[i][j];

        //dp[i][j][k] 是当前已经决策完 第i行, 第j列的格子（1<=i<=n, 1<=j<=m）,轮廓线状态是k时的方案数(最大回路数量).
        vector<vector<vector<ill>>> dp(N + 1, vector<vector<ill>>(M + 1, vector<ill>((1 << (M+1)), 0)));
        
        ill full = 1 << (M + 1); //轮廓线是长度为M+1的01序列，full是转成十进制，轮廓线被状压成[0,full)内的一个值

        dp[1][0][0] = 1; //dp初始化，即第一行第0列决策完, 轮廓线状态是0，（事实上, 轮廓线状态只能是0啊~）的方案数就是1.
        /*
        答案是 dp[n][m][0], 即决策完全部的格子, 轮廓线的状态是0
        （决策完最后一个格子轮廓线的样子是形如LD样子,只不过LD在棋盘最底部边线, 所以自然轮廓线状态是0啦）        
        */
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j) //处理第i行,第j列的格子, 即逐格DP
            {
                bitset<12> p1 = 1 << (j - 1);       //第j-1个比特位
                bitset<12> p2 = 1 << j;             //第j个比特位
                for (ill k = 0; k < full; ++k)      // 注意, k是L1的状态值,而不是L2的
                {
                    bitset<12> p(k);

                    // if(dp[i][j - 1][k]==0)
                    //     continue;


                    if (mp[i][j] > 0) // 如果不是障碍物
                    {
                        bitset<12> px = p ^ p1 ^ p2;
                        ill r= (p ^ p1 ^ p2).to_ullong();
                        dp[i][j][r] += dp[i][j - 1][k]; //图1、图2、图4的情形

                        if(j==2 && dp[i][j][r] > 0)
                            for (int _s = 0; _s < 1 - 1; ++_s) cout << 1;

                        if(i==2 && dp[i][j - 1][k]>0)
                            cout << "r-c:" << i << "-" << j << " " << setw(2) << px.to_ulong() <<":" << px.to_string() << " from " << setw(2) << p.to_ulong() <<":" << p.to_string() << " " << dp[i][j][r] <<"\n";                            


                        if (((k >> (j - 1)) & 1) == (k >> j & 1))
                        {
                            continue; // 图1、图2、图4就会continue
                        }             // 因为只有情形3才要再加上一部分(即图3).
                        dp[i][j][k] += dp[i][j - 1][k];//即图3.
                        
                        if(i==2 && dp[i][j-1][k] > 0)
                             cout << "r-c:" << i << "-" << j << " " << setw(2) << p.to_ulong() <<":" << p.to_string() << " form " << setw(2) << p.to_ulong() <<":" << p.to_string() << " " << dp[i][j][k] <<"\n"; 
                    }
                    else // 如果是障碍物（图6）
                    {
                        if ((p & p1) !=0 || (p & p2) !=0 ) // AD、DC两个比特位至少一个不为0
                        {
                            continue; //  dp[i][j][k]为0
                        }
                        //assert(k < (1<<13)+5);
                        dp[i][j][k] = dp[i][j - 1][k]; // 只有AD、DC两个比特位皆为0,dp[i][j][k]才可能不为0
                    }
                }
            }
            //cout << "\n";
            //move(i, j);

            if (i < N) // 换行, 即逐行DP
                for (ill k = 0; k<(1 << ((M + 1)) >> 1); ++k)
                {
                    dp[i + 1][0][k << 1] = dp[i][M][k]; // 图5

                    if(i==1 )
                    {
                        bitset<12> p(k << 1);
                        bitset<12> px(k);
                        cout << "r-c:" << i+1 << "-" << 0 << " " << setw(2) << p.to_ulong() <<":" << p.to_string() << " form " << setw(2) << px.to_ulong() <<":" << px.to_string() << " " << dp[i + 1][0][k << 1] << " <-" << dp[i][M][k] <<"\n"; 
                    }

                }
        }

        cout << "Case " << c << ": There are " << dp[N][M][0] << " ways to eat the trees.\n";
        ++c;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("HDU_1693_EattheTrees.in", "r", stdin);
    //freopen("HDU_1693_EattheTrees.out", "w", stdout);
#endif

    solve();
    // bitset<10> b(7);
    // cout << b.to_string() << ":" <<b.to_ulong() <<"\n";

    // bitset<10> b1(7<<2);
    // cout << b1.to_string() << ":" <<b1.to_ulong() <<"\n";

    cout.flush();

    return 0;
}
