#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    vector<int> value = {4, 5, 10, 11, 13};     //物品价值
    vector<int> weight = {3, 4, 7, 8, 9};       //物品重量

    int totalWeight = 17;                       //背包总重量
    int totalCount = value.size();              //物品的数量

    //dp[i][j] 代表第累计到第i个物品，背包容量是j的最大价值
    vector<vector<int>> dp(totalCount, vector<int>(totalWeight + 1, 0));

    //背包中的物品，存储物品的索引。记录放还是不放入背包。false为不放，true为放
    vector<vector<int>> isPutInKnapsack(totalCount, vector<int>(totalWeight + 1, false));
    
    
    dp[0][0]=0;
    
    for (int i = 0; i <= totalCount - 1; ++i)
    {
        if (i == 0)
        {
            //初始化仅放第0个物品时候dp数据
            for (int j = 0; j <= totalWeight; ++j)
            {
                if(j<weight[0])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] =value[0];
                    isPutInKnapsack[i][j]=true;
                }
            }            
        }
        else
        {
            for (int j = 0; j <= totalWeight; ++j)
            {
                
                //surplusW：如果仅仅要第i个物品之后的剩余容量
                //dp[i-1][surplusW]:容量是surplusW，前i-1个物品的最大价值
                int surplusW = j - weight[i];

                if (surplusW < 0)
                {
                    //背包放不下第i个物品的情况，背包的最大价值还是放i-1个的一样
                    dp[i][j] =  dp[i-1][j];
                }
                else
                {
                    //背包放的下第i个物品的情况，背包的最大价值递推公式
                    dp[i][j] = max(dp[i-i][j], dp[i-1][surplusW]+ value[i]);


                    //记录背包的内容，如果价值大于前面的价值这放进背包
                    if(dp[i-1][surplusW]+ value[i]>dp[i-i][j])
                    {
                        isPutInKnapsack[i][j]=true;
                    }
                }
            }
        }
    }

    //表格里数据
    for (int i = 0; i <= totalCount - 1; ++i)
    {
        for (int j = 0; j <= totalWeight ; ++j)
        {
            cout << setw(2) << dp[i][j] << " ";        
        }
        cout << "\n";        
    }

    cout << "The max value in knapsack is:" << dp[totalCount-1][totalWeight] << "\n";

    cout << "The ID in the knapsack is :" ;
    for (int i = totalCount-1,j = totalWeight; i>=0; --i)
    {
        if(isPutInKnapsack[i][j]==true)
        {
            cout << i << " ";
            j-=weight[i];
        }
        
    }

    cout << "\n";        
    return 0;
}