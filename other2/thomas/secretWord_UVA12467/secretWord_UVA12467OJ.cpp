#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int tcc; cin >> tcc;
    for (int c = 1; c <= tcc; ++c)
    {
        string s; cin >> s;
        int sizeS = s.size();

        int l = 1, r = sizeS;
        while (l <= r)
        {
            int m = (l + r) / 2;

            string t = s.substr(0, m); reverse(t.begin(), t.end());
            int sizeT = t.size();

            int _i = 1, _j = 0;
            vector<int> next(sizeT, 0); next[0] = 0;
            while (_i <= sizeT - 1)
            {
                while (_j > 0 && t[_i] != t[_j])
                {
                    if (_j > 0) _j = next[_j - 1];

                    if (_j == -1) break;
                }
                
                if (t[_i] == t[_j]) next[_i] = _j + 1;

                ++_i;
                ++_j;
            }

            bool flag = false;
            int i = 0, j = 0;
            while (i <= sizeS - 1)
            {
                if (s[i] != t[j])
                {
                    if (j == 0)
                    {
                        ++i;
                    }
                    else
                    {
                        j = next[j - 1];
                    }
                }
                else
                {
                    if (j == sizeT - 1)
                    {
                        flag = true;
                        ++i;
                        j = 0;

                        break;
                    }
                    else
                    {
                        ++i;
                        ++j;
                    }
                }
            }

            if (flag == true)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        string ans = s.substr(0, l - 1); reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

