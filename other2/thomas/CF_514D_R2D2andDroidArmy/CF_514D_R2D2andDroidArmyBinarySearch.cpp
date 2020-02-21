/*
===========================================================
* @Name:           514D R2D2 and Droid Army
* @Author:         Thomas
* @create Time:    2020/2/21 9:42:21
* @url:            https://codeforces.com/contest/514/problem/D
* @Description:    SparseTable + 二分 AC
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
    vector<vector<int>> MAX; //Sparse Table (ST表)
    vector<int> a;
    vector<int> lg2Result;
    SparseTable()
    {
    }
    SparseTable(vector<int> & a)
    {
        int len = a.size();
        lg2Result.assign(len + 1, 0);

        int maxJ = lg2(len) + 1;

        for (int i = 1; i <= len; ++i)
        {
            lg2Result[i] = lg2(i);
        }

        MAX.resize(len, vector<int>(maxJ + 1, -1));

        this->a = a;

        for (int i = 0; i <= len - 1; ++i)
        {
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

                if (a[MAX[i][front]] >= a[MAX[back][front]])
                    MAX[i][j] = MAX[i][front];
                else
                    MAX[i][j] = MAX[back][front];
            }
        }
    }

    int QueryMaxIndex(int i, int j)
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
    int QueryMax(int i, int j)
    {
        return a[QueryMaxIndex(i, j)];
    }
};

int checkLen(int len, vector<SparseTable> & st, int n, int m, int k)
{
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = i + len - 1; j <= n - 1; ++j)
        {
            ll total = 0;
            for (int q = 0; q <= m - 1; ++q)
            {
                int curr = st[q].QueryMax(i, j);
                total += curr;
                if (total > k)
                    break;
            }

            //可以满足
            if (total <= k)
            {
                return i;
            }
            else
            {
                break;
            }
        }
    }
    return -1;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = 0; j <= m - 1; ++j)
        {
            cin >> a[i][j];
        }
    }

    //行列转换
    vector<vector<int>> droid(m, vector<int>(n, 0));
    for (int i = 0; i <= m - 1; ++i)
    {
        for (int j = 0; j <= n - 1; ++j)
        {
            droid[i][j] = a[j][i];
        }
    }

    vector<SparseTable> st;
    for (int i = 0; i <= m - 1; ++i)
    {
        SparseTable temp(droid[i]);
        st.push_back(temp);
    }

    int maxLen = 0;
    int beginId = 0;

    int l = 0, r = n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        int ret = checkLen(mid, st, n, m, k);
        if (ret>= 0)
        {
            l = mid;
            maxLen = mid;
            beginId = ret;
        }
        else
        {
            r = mid;
        }
    }

    //特殊情况，没进入二分
    /* iput:
1 1 0
1    
    */
    if(maxLen==0)
    {
        int ret = checkLen(1, st, n, m, k);
        if (ret>= 0)
        {
            maxLen = 1;
            beginId = ret;
        }        

    }

    vector<int> ans(m, 0);
    for (int q = 0; q <= m - 1 && maxLen>0; ++q)
    {
        int curr = st[q].QueryMax(beginId, beginId + maxLen - 1);
        ans[q] += curr;
    }

    for (int i = 0; i <= m - 1; ++i)
    {
        cout << ans[i] << " ";
    }

    //assert(n > 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_514D_R2D2andDroidArmy.in", "r", stdin);
    //freopen("CF_514D_R2D2andDroidArmy.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}