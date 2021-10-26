#include <iostream>
using namespace std;
int N; //total num of place
int Map[16][16];
int dp[16][36768];       //dp[cur][status] cur:0--N-1 当前所在位
                         //status 第i位 表示当前是否走过
int num_of_1(int status) //获取多少位为1，表示已经走过多少地点
{
    int i, sum = 0;
    int t = 1;
    for (i = 0; i < N; ++i)
    {
        if (status & t)
        {
            ++sum;
        }
        t <<= 1;
    }
    return sum;
}

int get(int cur, int status)
{
    if (dp[cur][status] != -1)
    {
        return dp[cur][status];
    }
    if (num_of_1(status) > 2) //除了出发点，还有其他地方可以走
    {
        int i, t = 2;
        int minlen = 10000000;
        for (i = 1; i < N; ++i, t <<= 1)
        {
            if (i == cur)
            {
                continue;
            }
            if (status & t)
            {
                if (get(i, status & (~(1 << cur))) + Map[cur][i] < minlen) //去掉当前位
                {
                    minlen = get(i, status & (~(1 << cur))) + Map[cur][i];
                }
            }
        }
        return dp[cur][status] = minlen;
    }
    else //只能回到出发点
    {
        return dp[cur][status] = Map[0][cur];
    }
}

int main()
{
    int i, j, minlen;
    cin >> N;
    if (N == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            cin >> Map[i][j];
        }
    }
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < 32768; ++j)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][1] = 0; //处在第一个点，即出发点
    minlen = 10000000;
    for (i = 1; i < N; ++i)
    {
        if (Map[0][i] + get(i, (1 << N) - 1) < minlen)
        {
            minlen = Map[0][i] + get(i, (1 << N) - 1);
        }
    }
    cout << minlen << endl;
}