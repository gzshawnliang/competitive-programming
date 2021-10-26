#include <bits/stdc++.h>

using namespace std;

//ifstream fin("stTable.in");
//ofstream fout("stTable.out");

int lg2(int n)
{
    int i = 0;
    while ((1 << i) <= n) //(1<<i) = 2^i
        ++i;

    return i - 1;
}

vector<vector<int>> buitST(vector<int> & a)
{
    int len = a.size();
    int maxJ = lg2(len)+1;
    vector<vector<int>> M(len, vector<int>(maxJ, -1));      //Sparse Table (ST表)

    for (int i = 0; i <= len - 1; ++i)
    {
        M[i][0] = i;
    }

    for (int j = 1; j <= maxJ ; ++j)
    {
        for (int i = 0; i <= len - 1; ++i)
        {
            int front=j-1;
            int back= i + (1<<(j-1));
            if(back>len-1)
                continue;
            if(a[M[i][front]]<=a[M[back][front]])
                M[i][j] = M[i][front];
            else                 
                M[i][j] = M[back][front];
        }
    }

    return M;
}

int queryMinST(int i,int j,vector<vector<int>> & M,vector<int> & a)
{
    if(i==j)
        return M[i][0];

    if(i>j)
        swap(i,j);

    int k=lg2(j-i+1);               //长度
    
    int front=M[i][k];              //前段
    int i2=j-(1<<k)+1;          //后段j-2^k+1;
    int back=M[i2][k];

    if(a[front]<=a[back])
        return front;
    else 
        return back;
}

int main()
{
    vector<int> a = {2, 4, 3, 1, 6, 7, 8, 9, 1, 7};
    vector<vector<int>> ST=buitST(a);

    int n=a.size();
    int maxJ = lg2(n)+1;

    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = 0; j <= maxJ-1; ++j)
            cout << ST[i][j] << " ";
        
        cout << "\n";
    }

    
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = i; j <= n - 1; ++j)
        {
            cout << "min(" <<i << "," << j <<"):" << queryMinST(i,j,ST,a) << "\n";
        }
    }

    return 0;
}
