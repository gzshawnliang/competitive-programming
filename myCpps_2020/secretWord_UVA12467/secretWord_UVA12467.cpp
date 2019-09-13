#include <bits/stdc++.h>

using namespace std;

ifstream fin("secretWord_UVA12467.in");
ofstream fout("secretWord_UVA12467.out");

int main()
{
    int tcc; fin >> tcc;
    for (int c = 1; c <= tcc; ++c)
    {
        string s; fin >> s;
        int sizeS = s.size();

        int l = 1, r = sizeS;
        while (l <= r)
        {
            int m = (l + r) / 2;

            string t = s.substr(0, m); reverse(t.begin(), t.end());

            int _i = 0, _j = -1;
            vector<int> next(m + 1, 0); next[0] = -1;
            while (_i <= m - 1)
            {
                while (_j >= 0 && t[_i] != t[_j])
                {
                    _j = next[_j];
                }

                ++_i; ++_j;
                next[_i] = _j;
            }


            bool flag = false;
            int i = 0, j = 0;
            while (i <= sizeS - 1)
            {
                while (j >= 0 && s[i] != t[j])
                {
                    j = next[j];
                }
                
                ++i; ++j;
                if (j == m)
                {
                    flag = true;
                    j = next[j];

                    break;
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

        string t = s.substr(0, r); reverse(t.begin(), t.end());
        fout << t << '\n';
    }

    return 0;
}
