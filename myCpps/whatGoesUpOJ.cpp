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
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<int> a;

    int in;
    while (cin >> in)
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
        for (auto it = file.rbegin(); it != file.rend(); ++it)
        {
            if (it->valumn < a[i])
            {
                dp[i] = it->dp + 1;
                elements[i] = it->element;
                break;
            } 
        }

        // auto it = lower_bound(file.begin(),file.end(), a[i]);
        // --it;

        // dp[i] = it->dp + 1;
        // elements[i] = it->element;
        // break;

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

    cout << dp[ansPos] << "\n-\n";

    vector<int> out = elements[ansPos];
    int size1 = out.size();
    for (int i = 0; i <= size1 - 1; ++i)
    {
        cout << out[i] << '\n';
    }

   	cout.flush();
   	return 0;
}
