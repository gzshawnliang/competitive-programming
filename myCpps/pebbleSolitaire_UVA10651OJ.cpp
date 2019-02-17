#include <bits/stdc++.h>

using namespace std;


const int n = 12;

int solve(vector<bool> & a)
{
    int ans = 0;

    for (int i = 0; i <= n - 1; ++i)
    {
        ans += a[i];
    }

    if (ans == 7)
    {
        for (int __s = 0; __s == 0; ++__s);
    }

    for (int i = 0; i <= n - 1; ++i)
    {
        if (a[i] == 0)
        {
            continue;
        }

        if (i >= 0 + 2)
        {
            if (a[i - 1] == 1 && a[i - 2] == 0)
            {
                a[i - 1] = 0; swap(a[i], a[i - 2]);
                ans = min(ans, solve(a));

                a[i - 1] = 1; swap(a[i], a[i - 2]);
            }
        }
        
        if (i <= n - 1 - 2)
        {
            if (a[i + 1] == 1 && a[i + 2] == 0)
            {
                a[i + 1] = 0; swap(a[i], a[i + 2]);
                ans = min(ans, solve(a));

                a[i + 1] = 1; swap(a[i], a[i + 2]);
            }
        }
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        vector<bool> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            char ch; cin >> ch;
            a[i] = (ch == 'o');
        }

        cout << solve(a) << '\n';
    }

   	cout.flush();
   	return 0;
}

