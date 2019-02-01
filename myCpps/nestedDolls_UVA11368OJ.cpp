#include <bits/stdc++.h>

using namespace std;


struct doll
{
    int w;
    int h;

    bool operator < (const doll & temp) const
    {
        if (w != temp.w)
        {
            return w > temp.w;
        }
        else
        {
            return h < temp.h;
        }
    };
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int n; cin >> n;

        vector<doll> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].w >> a[i].h;
        }

        sort(a.begin(), a.end());

        multiset<int> s;
        s.insert(INT_MAX);

        for (int i = 0; i <= n - 1; ++i)
        {
            auto it = s.upper_bound(a[i].h);

            if (it == s.end())
            {
                s.insert(a[i].h);
            }
            else
            {
                s.erase(it);
                s.insert(a[i].h);
            }
        }

        cout << s.size() << '\n';
    }

   	cout.flush();
   	return 0;
}

