#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

ifstream fin("backToThe8-Queens_UVA11085.in");
ofstream fout("backToThe8-Queens_UVA11085.out");

bool check(vector<int> a)
{
    bool ok = true;
    for (int i = 0; i <= 7 && ok == true; ++i)
    {
        for (int j = i + 1; j <= 7 && ok == true; ++j)
        {
            if (abs(i - j) == abs(a[i] - a[j]))
            {
                ok = false;
            }
        }
    }

    return ok;
}

int main()
{
    vector<vector<int>> file;
    vector<int> temp0 = {0, 1, 2, 3, 4, 5, 6, 7};
    do
    {
        if (check(temp0) == true)
        {
            file.push_back(temp0);
        }
    }
    while (next_permutation(temp0.begin(), temp0.end()));

    int size0 = file.size(), cases = 0;

    while (true)
    {
        ++cases;

        vector<int> a(8, 0);
        for (int i = 0; i <= 7; ++i)
        {
            fin >> a[i];
            --a[i];
        }

        if (a[0] == -1)
        {
            break;
        }

        int ans = 100;
        for (int i = 0; i <= size0 - 1; ++i)
        {
            int temp1 = 0;

            for (int j = 0; j <= 7; ++j)
            {
                if (a[j] != file[i][j])
                {
                    ++temp1;
                }
            }

            ans = min(ans, temp1);
        }

        fout << "Case " << cases << ": " << ans << '\n';
    }

    return 0;
}