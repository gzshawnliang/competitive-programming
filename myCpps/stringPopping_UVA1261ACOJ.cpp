#include <bits/stdc++.h>

using namespace std;


bool solve(string & s)
{
    if (s.size() == 0)
    {
        return true;
    }
    else
    {
        bool ans = false;

        int n = s.size(); 
        for (int i = 0; i <= n - 1; ++i)
        {
            int _count = 0;
            string temp = s;

            while (temp[i] == s[i])
            {
                temp.erase(temp.begin() + i);
                ++_count;
            }

            if (_count > 1)
            {
                ans = (ans || solve(temp));
            }
        }

        return ans;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        string s; cin >> s;

        cout << solve(s) << '\n';
    }

   	cout.flush();
   	return 0;
}

