/*
===========================================================
 * @名称:		Strip
 * @作者:		Thomas 
 * @创建时间: 2020-02-12 20:54:33 
 * @修改人:   Thomas 
 * @修改时间: 2020-02-12 20:54:33 
 * @备注:	  Sparse Table + Sliding Window(双指针) + DP
 * @题目来源： https://codeforces.com/problemset/problem/488/D
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX / 2;

class SparseTable
{
  private:
    int lg2(int n)
    {
        int i = 0;
        while ((1 << i) <= n) //(1<<i) = 2^i
        {
            ++i;
        }

        return i - 1;
    }

  public:
    vector<vector<int>> MIN; //Sparse Table (ST表)
    vector<vector<int>> MAX; //Sparse Table (ST表)
    vector<int> a;
    vector<int> lg2Result;
    SparseTable(vector<int> & a)
    {
        int len = a.size();
        lg2Result.assign(len + 1, 0);

        int maxJ = lg2(len) + 1;

        for (int i = 1; i <= len; ++i)
        {
            lg2Result[i] = lg2(i);
        }

        MIN.resize(len, vector<int>(maxJ + 1, -1));
        MAX.resize(len, vector<int>(maxJ + 1, -1));

        this->a = a;

        for (int i = 0; i <= len - 1; ++i)
        {
            MIN[i][0] = i;
            MAX[i][0] = i;
        }

        for (int j = 1; j <= maxJ; ++j)
        {
            for (int i = 0; i <= len - 1; ++i)
            {
                int front = j - 1;
                int back = i + (1 << (j - 1));
                if (back > len - 1)
                    continue;
                if (a[MIN[i][front]] <= a[MIN[back][front]])
                    MIN[i][j] = MIN[i][front];
                else
                    MIN[i][j] = MIN[back][front];

                if (a[MAX[i][front]] >= a[MAX[back][front]])
                    MAX[i][j] = MAX[i][front];
                else
                    MAX[i][j] = MAX[back][front];
            }
        }
    }

    int QueryMin(int i, int j)
    {
        if (i == j)
            return MIN[i][0];

        if (i > j)
            swap(i, j);

        int k = lg2(j - i + 1); //计算长度，
        //int k=lg2Result[j - i + 1];       //长度，用一维数组速度快点

        int front = MIN[i][k];     //前段
        int i2 = j - (1 << k) + 1; //后段j-2^k+1;
        int back = MIN[i2][k];

        if (a[front] <= a[back])
            return front;
        else
            return back;
    }

    int QueryMax(int i, int j)
    {
        if (i == j)
            return MAX[i][0];

        if (i > j)
            swap(i, j);

        int k = lg2(j - i + 1); //计算长度，
        //int k=lg2Result[j - i + 1];     //长度，用一维数组速度快点

        int front = MAX[i][k];     //前段
        int i2 = j - (1 << k) + 1; //后段j-2^k+1;
        int back = MAX[i2][k];

        if (a[front] >= a[back])
            return front;
        else
            return back;
    }

    int Max_Min(int i, int j)
    {
        if (i == j)
            return 0;

        if (i > j)
            swap(i, j);

        int k = lg2(j - i + 1); //计算长度，
        //int k=lg2Result[j - i + 1];     //长度，用一维数组速度快点

        int front = MAX[i][k];     //前段
        int i2 = j - (1 << k) + 1; //后段j-2^k+1;
        int back = MAX[i2][k];

        int maxV = max(a[front], a[back]);

        front = MIN[i][k]; //前段
        back = MIN[i2][k];

        int minV = min(a[front], a[back]);

        return maxV - minV;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("CF_488D_Strip.in", "r", stdin);
    freopen("CF_488D_Strip.out", "w", stdout);
#endif

    int n, s, l;
    cin >> n >> s >> l;

    vector<int> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
    }
    SparseTable st(a);

    // for (int i = 0; i <= n - 1; ++i)
    // {
    //     for (int j = i+l-1; j <= n - 1; ++j)
    //     {
    //         //cout << "min(" << i << "," << j << "):" << st.QueryMin(i, j) << "\n";
    //         //cout << "max(" << i << "," << j << "):" << st.QueryMax(i, j) << "\n";
    //         if(st.Max_Min(i,j)<=s)
    //             cout << "max-min(" << i << "," << j << "):" << st.Max_Min(i,j) << "\n";
    //     }
    // }

    vector<int> dp(n + 1, INF);
    int j = 0;
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        //      长度满足但最值相差大，则j++；                   j前无值,++j;
        while ((i - j >= l && st.Max_Min(j, i - 1) > s) || dp[j] == INF)
            ++j;

        if (i - j >= l)
            dp[i] = min(dp[j] + 1, dp[i]);
    }

    if (dp[n] == INF)
        cout << -1 << "\n";
    else
        cout << dp[n] << "\n";

    return 0;
}
