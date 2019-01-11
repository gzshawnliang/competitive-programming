#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        string a = "", b = "";
        getline(cin, a);
        getline(cin, b);

        int size0 = a.size(), size1 = b.size();
        vector<bool> used(size1, false);
        string ans = "";

        for (int i = 0; i <= size0 - 1; ++i)
        {
            for (int j = 0; j <= size1 - 1; ++j)
            {
                if (a[i] == b[j] && used[j] == false)
                {
                    ans += a[i];
                    used[j] = true;

                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());

        if (cin.eof())
        {
            break;
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
