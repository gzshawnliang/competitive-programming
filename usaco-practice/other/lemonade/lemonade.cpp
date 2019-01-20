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

ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

int main()
{
    int n; fin >> n;
    vector<int> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        if (a[i] >= ans)
        {
            ++ans;
        }
    }

    fout << ans << '\n';

    return 0;
}
