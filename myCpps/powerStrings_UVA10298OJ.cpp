#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        string s = "."; cin >> s;
        if (s == ".") break;

        int sizeS = s.size();

        int i = 1, j = 0;
        vector<int> next(sizeS, 0); next[0] = 0;
        while (i <= sizeS - 1)
        {
            while (j > 0 && s[i] != s[j])
            {
                if (j > 0) j = next[j - 1];

                if (j == -1) break;
            }
            
            if (s[i] == s[j]) next[i] = j + 1;

            ++i;
            ++j;
        }

        cout << sizeS / (sizeS - next[sizeS - 1]) << '\n';
    }

   	cout.flush();
   	return 0;
}

