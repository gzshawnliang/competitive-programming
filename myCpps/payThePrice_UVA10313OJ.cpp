#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<vector<long long>> dp(301, vector<long long>(301, 0));
    dp[0][0] = 1;
    for (int c = 1; c <= 300; ++c)
    {
        for (int p = c; p <= 300; ++p)
        {
            for (int k = 1; k <= p; ++k)
            {
                dp[p][k] += dp[p - c][k - 1];
            }
        }
    }

    while (true)
    {
        string in = "", temp = "";
        vector<int> a;
        getline(cin, in);

        if (in == "")
        {
            break;
        }

        int size0 = in.size();

        for (int i = 0; i <= size0 - 1; ++i)
        {
            if (in[i] == ' ')
            {
                a.push_back(stoi(temp));
                temp = "";
            }
            else
            {
                temp += in[i];
            }
        }
        a.push_back(stoi(temp));
        int size1 = a.size();
        
        if (size1 == 1)
        {
            if (a[0] == 0)
            {
                cout << "1\n";
                continue;
            }

            long long ans = 0;
            for (int i = 1; i <= a[0]; ++i)
            {
                ans += dp[a[0]][i];
            }

            cout << ans << '\n';
        }
        else if (size1 == 2)
        {
            if (a[0] == 0)
            {
                cout << "1\n";
                continue;
            }

            long long ans = 0;
            for (int i = 1; i <= a[1] && i <= 300; ++i)
            {
                ans += dp[a[0]][i];
            }

            cout << ans << '\n';
        }
        else
        {
            if (a[0] == 0 && a[1] == 0)
            {
                cout << "1\n";
                continue;
            }
            else if (a[1] > a[0])
            {
                cout << "0\n";
                continue;
            }

            long long ans = 0;
            for (int i = a[1]; i <= a[2] && i <= 300; ++i)
            {
                ans += dp[a[0]][i];
            }

            cout << ans << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
