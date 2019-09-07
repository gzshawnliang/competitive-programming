#include <bits/stdc++.h>

using namespace std;

ifstream fin("powerStrings_UVA10298.in");
ofstream fout("powerStrings_UVA10298.out");

vector<int> createNext(string & P)
{
    vector<int> next;
    return next;
}

vector<int> KmpSearch(string & T,string & P)
{
    vector<int> pos;
    vector<int> next = createNext(P);

    //begin search

    return pos;
}

int main()
{
    string s = "ababababababababcabababab",
           t = "abababc";

    int sizeS = s.size(), sizeT = t.size();

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

    int i = 0, j = 0;
    vector<int> ans;
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
                ans.push_back(i - sizeT + 1);
                ++i;
                j = 0;
            }
            else
            {
                ++i;
                ++j;
            }
        }
    }

    return 0;
}
