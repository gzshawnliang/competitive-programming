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




int main()
{

    
    return 0;
}
