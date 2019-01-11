#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("whatGoesUp.in");
ofstream fout("whatGoesUp.out");

struct item
{
    int i;
    int valumn;
    int dp;
    vector<int> element;

    bool operator < (const item &temp) const
    {
        if (dp != temp.dp)
        {
            return dp < temp.dp;
        }
        else
        {
            return i < temp.i;
        }
    }
    // bool operator < (const item &temp) const
    // {
    //     if (valumn != temp.valumn)
    //     {
    //         return valumn < temp.valumn;
    //     }
    //     else if (dp != temp.dp)
    //     {
    //         return dp < temp.dp;
    //     }
    //     else
    //     {
    //         return i < temp.i;
    //     }
    // }    
};

int main()
{
    vector<int> a;

    int in;
    while (fin >> in)
    {
        a.push_back(in);
    }

    int size0 = a.size();
    vector<int> dp(a.size(), 1);
    vector<vector<int>> elements(a.size());

    set<item> file;
    vector<int> wheee;
    wheee.push_back(a[0]);
    item whee{0, a[0], 1, wheee};
    file.insert(whee);

    for (int i = 1; i <= size0 - 1; ++i)
    {
        // for (int j = 0; j <= i - 1; ++j)
        // {
        //     if (a[j] < a[i])
        //     {
        //         if (dp[i] <= dp[j] + 1)
        //         {
        //             dp[i] = dp[j] + 1;
        //             elements[i] = elements[j];
        //         }
        //     } 
        // }

        for (auto it = file.rbegin(); it != file.rend(); ++it)
        {
            if (it->valumn < a[i])
            {
                dp[i] = it->dp + 1;
                elements[i] = it->element;
                break;
            } 
        }


        elements[i].push_back(a[i]);

        item temp{i, a[i], dp[i], elements[i]};
        file.insert(temp);
    }

    int ansPos = 0;
    for (int i = 0; i <= size0 - 1; ++i)
    {
        if (dp[ansPos] <= dp[i])
        {
            ansPos = i;
        }
    }
    fout << dp[ansPos] << "\n-\n";

    vector<int> out = elements[ansPos];
    int size1 = out.size();
    for (int i = 0; i <= size1 - 1; ++i)
    {
        fout << out[i] << '\n';
    }

    return 0;
}