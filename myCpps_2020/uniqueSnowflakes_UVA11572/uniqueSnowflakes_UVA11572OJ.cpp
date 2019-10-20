#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int count = 0;
        unordered_map<int, int> itoi;

        int n; cin >> n;

        if (n == 0)
        {
            cout << "0\n";
            continue;
        }

        vector<int> a;
        for (int c = 1; c <= n; ++c)
        {
            int temp; cin >> temp;

            if (itoi.count(temp) == 0)
            {
                itoi[temp] = count;
                ++count;
            }

            a.push_back(itoi[temp]);
        }

        vector<int> m(count, 0);
        m[a[0]] = 1;

        int l = 0, r = 0, ans = 1;
        while (r <= n - 2)
        {
            ++r;
            ++m[a[r]];

            while (m[a[r]] > 1 && l < r)
            {
                --m[a[l]];
                ++l;
            }

            ans = max(ans, r - l + 1);
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

