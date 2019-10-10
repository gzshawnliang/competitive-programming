#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");

const int maxN = 50005;

int main()
{
    int n;  //牛的数量
    fin >> n;

    /*
        dp[i,j]:口味值是i的对应的牛编号，
        j用bitset表示，例如 dp[1][0000110] 口味值是1的有第1头牛、第2头牛
    */
    map<int, bitset<maxN>> dp; 

    //a[i][j]  ，i,j都从1开始
    //第i头牛的j个口味值
    vector<vector<int>> a(n + 1, vector<int>(5 + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            int currFlavor;
            fin >> currFlavor;
            a[i][j] = currFlavor;
            dp[currFlavor][i] = 1;
        }
    }

    
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        bitset<maxN> p;
        for (int j = 1; j <= 5; ++j)
        {
            int currFlavor=a[i][j];
            p |= dp[currFlavor];
        }
        ans += (n - p.count());
    }
    fout << ans / 2 << "\n";
    return 0;
}
