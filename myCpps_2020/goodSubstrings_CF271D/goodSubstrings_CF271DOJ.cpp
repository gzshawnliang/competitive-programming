#include <bits/stdc++.h>

using namespace std;


using ull = unsigned long long;

const ull P = 10007;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    string s; cin >> s;

    string temp; cin >> temp;
    vector<int> isGood(256, 0);
    for (int i = 0; i <= 26 - 1; ++i)
    {
        isGood['a' + i] = temp[i] - '0';
    }

    int k; cin >> k;

    int n = s.size();
    //set<ull> sset;
    unordered_set <ull> sset;
    for (int i = 0; i <= n - 1; ++i)
    {
        int count = 0;

        ull now_ull = 0;
        for (int j = i; j <= n - 1; ++j)
        {
            if (isGood[s[j]] == 0) ++count;
            if (count > k) break;

            now_ull = P * now_ull + s[j];
            sset.insert(now_ull);
        }
    }

    cout << sset.size() << '\n';

   	cout.flush();
   	return 0;
}

