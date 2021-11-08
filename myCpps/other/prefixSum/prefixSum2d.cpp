/*
===========================================================
 * 名称:    二维前缀和
 * 作者:    Shawn
 * 创建时间: 2019-10-28 09:02:16 
 * 修改人:   Shawn 
 * 修改时间: 2019-10-28 09:02:16 
 * 备注:    
 * 题目来源: https://blog.csdn.net/ToBeYours/article/details/79746095
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("prefixSum2d.in");
ofstream fout("prefixSum2d.out");

int main()
{
    int n;
    fin >> n;

    int m;
    fin >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> b(n + 1, vector<int>(n + 1, 0)); //prefixSum of a
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> a[i][j];

    b[1][1] = a[1][1];
    for (int i = 2; i <= n; ++i)
    {
        b[1][i] = b[1][i - 1] + a[1][i];
        b[i][1] = b[i - 1][1] + a[i][1];
    }

    for (int i = 2; i <= n - 1; ++i)
    {
        for (int j = 2; j <= n - 1; ++j)
        {
            b[i][j] = b[i - 1][j] + b[i][j - 1] + a[i][j] - b[i - 1][j - 1];
        }
    }

    for (int i = 0; i <= m - 1; ++i)
    {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        cout << b[x2][y2] - b[x2][y1 - 1] - b[x1 - 1][y2] + b[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}
