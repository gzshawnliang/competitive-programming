#include <bits/stdc++.h>

using namespace std;

ifstream fin("powerStrings_UVA10298.in");
ofstream fout("powerStrings_UVA10298.out");

int main()
{
    while (true)
    {
        string s = "."; fin >> s;
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

        fout << sizeS / (sizeS - next[sizeS - 1]) << '\n';
    }

    return 0;
}
