#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("convention.in");
ofstream fout("convention.out");

const int INF=1e7;

int main()
{
    int n, m, c; fin >> n >> m >> c;
    vector<int> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }

    sort(a.begin(), a.end(),greater<int>());

    // vector<int> b(n - 1);
    // for (int i = 0; i <= n - 2; ++i)
    // {
    //     b[i] = a[i + 1] - a[i];
    // }

    // sort(b.begin(), b.end(), greater<int>());

    //fout << b[c * m - n + 1] << '\n';

    vector<vector<int>> dp(n,vector<int>(n,INF));

    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = i; j <= n - 1; ++j)
        {
            if(j-i<c)
            {
                dp[i][j] = a[i]-a[j];
            }
            
        }        
    }

    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = i; j <= n - 1; ++j)
        {
            if(dp[i][j]==INF)
            {
                continue;
            }
            else
            {
               
            }
        }        
    }    

    return 0;
}
