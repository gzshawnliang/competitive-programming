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

ifstream fin("homework.in");
ofstream fout("homework.out");

struct answer
{
    long double ave;
    int k;

    bool operator<(const answer &temp) const
    {
        if (ave != temp.ave)
        {
            return ave < temp.ave;
        }
        else
        {
            return k > temp.k;
        }
    }
};

int main()
{
    int n; fin >> n;
    long double total = 0;
    vector<long double> dp(n + 1), a(n), minE(n + 1);

    dp[0] = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
        total += a[i];
        dp[i + 1] = dp[i] + a[i];
    }

    minE[n] = 2147483647;
    for (int i = n - 1; i >= 0; --i)
    {
        minE[i] = min(minE[i + 1], a[i]);
    }

    vector<answer> ans;
    for (int k = 1; k <= n - 2; ++k)
    {
        long double now = (long double)((total - dp[k] - minE[k]) / (n - k - 1));
        answer temp{now, k};
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());

    int size = ans.size();

    fout << ans[size - 1].k << '\n';
    for (int i = size - 2; i >= 0; --i)
    {
        if (ans[i].ave != ans[i + 1].ave) break;
        fout << ans[i].k << '\n';
    }

    return 0;
}