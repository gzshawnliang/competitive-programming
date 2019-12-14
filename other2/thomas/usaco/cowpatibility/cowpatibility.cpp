#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");

const int maxN = 50005;

int main()
{
    long long n; //牛的数量
    fin >> n;

    /*
        dp[i,j]:口味是i的对应的牛编号，
        j用bitset表示，例如 dp[1][0000110] 口味是1的有第1头牛、第2头牛
                                |||||||
                                6543210
    */
    map<int, bitset<maxN>> dp;

    //a[i][j]  ，i,j都从1开始
    //第i头牛的j个口味值
    vector<vector<int>> a(n + 1, vector<int>(5 + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            int f;                 //当前口味：f
            fin >> f;
            a[i][j] = f;
            dp[f][i] = 1;          //1代表存在这头牛
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        bitset<maxN> p;
        for (int j = 1; j <= 5; ++j)
        {
            int f = a[i][j];   //当前口味：f
            string s=p.to_string();
             auto first_digit = s.find('1') ;
             if( first_digit != std::string::npos )
                std::cout << s.substr(first_digit) << "->" ; 

            //cout <<dp[f].to_string() <<"\n";
            p |= dp[f];        //统计有哪些牛有f口味

            s=p.to_string();
            first_digit = s.find('1') ;
             if( first_digit != std::string::npos )
                std::cout << s.substr(first_digit) << '\n' ; 

        }
        ans += (n - p.count());         //不成对的数量，count计算bitset1个数量，n-count，代表0的数量
    }
    fout << ans /2 << "\n";             //多算了一次要除以2
    return 0;
}
