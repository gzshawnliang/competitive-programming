/*
===========================================================
 * @名称:		Sparse Table (ST表) 模板
 * @作者:		Thomas 
 * @创建时间: 2020-02-05 17:42:33 
 * @修改人:   Thomas 
 * @修改时间: 2020-02-05 17:42:33 
 * @备注:		
 * @题目来源： https://www.geeksforgeeks.org/sparse-table/
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

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
    vector<vector<int>> M;      //Sparse Table (ST表)
    vector<int> a;
    vector<int> lg2Result;
    SparseTable(vector<int> & a)
    {
        int len = a.size();
        lg2Result.assign(len+1,0);

        int maxJ = lg2(len) + 1;

        for (int i = 1; i <= len ; ++i)
        {
            lg2Result[i]=lg2(i);
        }

        M.resize(len, vector<int>(maxJ+1,-1)); 
        

        this->a=a;

        for (int i = 0; i <= len - 1; ++i)
        {
            M[i][0] = i;
        }

        for (int j = 1; j <= maxJ; ++j)
        {
            for (int i = 0; i <= len - 1; ++i)
            {
                int front = j - 1;
                int back = i + (1 << (j - 1));
                if (back > len - 1)
                    continue;
                if (a[M[i][front]] <= a[M[back][front]])
                    M[i][j] = M[i][front];
                else
                    M[i][j] = M[back][front];
            }
        }
    }

    int QueryMin(int i, int j)
    {
        if (i == j)
            return M[i][0];

        if (i > j)
            swap(i, j);

        //int k = lg2(j - i + 1);       //计算长度，
        int k=lg2Result[j - i + 1];     //长度，用一维数组速度快点

        int front = M[i][k];       //前段
        int i2 = j - (1 << k) + 1; //后段j-2^k+1;
        int back = M[i2][k];

        if (a[front] <= a[back])
            return front;
        else
            return back;
    }
};


int main()
{
    vector<int> a = {2, 4, 3, 1, 6, 7, 8, 9, 1, 7};
    SparseTable st(a);

    for (auto i : st.M)
    {
        for (auto j : i)
            cout << j << " ";

        cout << "\n";
    }

    int n = a.size();
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = i; j <= n - 1; ++j)
        {
            cout << "min(" << i << "," << j << "):" << st.QueryMin(i, j) << "\n";
        }
    }

    return 0;
}

