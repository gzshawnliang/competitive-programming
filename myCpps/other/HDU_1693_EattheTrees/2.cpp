//#include "stdafx.h"
#include <stdio.h>
#include <string.h>
//#define LOCAL
typedef long long LL;
LL n,m,a[15][15], bin[15],dp[15][15][(1<<13)+5], full;

void kk(int i, int j)
{
	LL p1 = 1<<j-1, p2 = 1<<j; // 第j-1个比特位和第j个比特位
	for (LL k = 0; k<full; k++) // 注意, k是L1的状态值,而不是L2的
	{
		if (a[i][j]) // 如果不是障碍物
		{
			dp[i][j][k^p1^p2] += dp[i][j-1][k]; // 图1、图2、图4的情形
			if ((k>>j-1&1)==(k>>j&1))
			{
				continue; // 图1、图2、图4就会continue
			} // 因为只有情形3才要再加上一部分(即图3).
			dp[i][j][k] += dp[i][j-1][k];
		}
		else // 如果是障碍物（图6）
		{
			if ((k&p1) || (k&p2)) // AD、DC两个比特位至少一个不为0
			{
				continue; //  dp[i][j][k]为0
			}
			dp[i][j][k] = dp[i][j-1][k]; // 只有AD、DC两个比特位皆为0,dp[i][j][k]才可能不为0
		}
	}
}

void sz(int i)
{
	for (int k = 0;k<full>>1; k++)
	{
		dp[i+1][0][k<<1] = dp[i][m][k]; // 图5
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("HDU_1693_EattheTrees.in", "r", stdin);
        //freopen("HDU_1693_EattheTrees.out", "w", stdout);
    #endif  
	int kase;
	scanf("%d", &kase);
	for (int kse = 1;kse<=kase;kse++)
	{
		memset(dp,0,sizeof(dp));
		scanf("%lld%lld", &n, &m);
		full = 1<<(m+1); // 则轮廓线被状压成[0,full)内的一个值
		for (LL i = 1;i<=n;i++)
		{
			for (LL j = 1;j<=m;j++)
			{
				scanf("%d", a[i]+j);
			}
		} // 读入棋盘
		dp[1][0][0] = 1; // dp初始化
		for (int i = 1;i<=n;i++)
		{
			for (int j = 1;j<=m;j++)
			{
				kk(i,j); //处理第i行,第j列的格子, 即逐格DP
			}
			if (i<n)
			{
				sz(i); // 换行, 即逐行DP
			}
		} // 开始dp
		printf("Case %d: There are %lld ways to eat the trees.\n", kse, dp[n][m][0]);
	}
	return 0;
}