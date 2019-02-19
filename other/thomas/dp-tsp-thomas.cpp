#include <bits/stdc++.h>

using namespace std;

//判断一个数字x二进制下第i位是不是等于1。
bool getMask(int x, int i)
{
    return (x & (1 << (i - 1))) > 0;
}

//将一个数字x二进制下第i位更改成1。
void setMask(int & x, int i)
{
    //x = x | (1 << (i - 1));
    x |= (1 << (i - 1));
}

//把一个数字二进制下最靠右的第一个1去掉。
void removeMask(int & x)
{
    //x = x & (x - 1);
    x &= (x - 1);
}

int vetexCount = 4;

vector<vector<int>> dist = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

vector<vector<int>> dp(vetexCount, vector<int>(1 << vetexCount, INT_MAX));


int tsp(int pos, int notVisitedSet)
{
    cout << bitset<8>(notVisitedSet).to_string() << "\n";

    if (notVisitedSet == ((1 << vetexCount) - 1))  //全是1111的情况
    {
        return dist[pos][0];
    }

    if (dp[pos][notVisitedSet] != INT_MAX)
    {
        return dp[pos][notVisitedSet];
    }

    int ans = INT_MAX;
    for (int k = 0; k <= vetexCount - 1; ++k)
    {
        
        if ((notVisitedSet & (1 << k)) == 0) //第 k 个节点没访问过
        {
            int newNotVisitedSet = notVisitedSet | (1 << k);   //更改第K个节点为1，已经访问

            ans = min(ans, dist[pos][k] + tsp(k, newNotVisitedSet));
        }
    }

    dp[pos][notVisitedSet] = ans;

    return ans;
}

int main()
{

    int ans = tsp(0, 0);
    cout << ans << "\n";
    return 0;
}
