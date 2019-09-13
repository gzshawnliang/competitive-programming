#include <bits/stdc++.h>

using namespace std;

ifstream fin("powerStrings_UVA10298.in");
ofstream fout("powerStrings_UVA10298.out");

int main()
{
    string s = "ercaabcabcjjjj",
           t = "abcabc";

    int sizeS = s.size(), sizeT = t.size();

    int _i = 0, _j = -1;
    vector<int> next(sizeT + 1, 0); next[0] = -1;
    while (_i <= sizeT - 1)
    {
        while (_j >= 0 && t[_i] != t[_j])
        {
            _j = next[_j];
        }

        ++_i; ++_j;
        next[_i] = _j;
    }

    int i = 0, j = 0;
    vector<int> ans;
    while (i <= sizeS - 1)
    {
        while (j >= 0 && s[i] != t[j])
        {
            j = next[j];
        }
        
        ++i; ++j;
        if (j == sizeT)
        {
            ans.push_back(i - sizeT);
            j = next[j];
        }
    }

    return 0;
}
