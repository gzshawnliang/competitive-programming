#include <bits/stdc++.h>

using namespace std;

ifstream fin("caesarCipher_UVA12604.in");
ofstream fout("caesarCipher_UVA12604.out");

const int num = 3;

int _count(string & s, string & w)
{
    int sizeW = w.size(), sizeS = s.size();

    int _i = 0, _j = -1;
    vector<int> next(sizeW + 1, 0); next[0] = -1;
    while (_i <= sizeW - 1)
    {
        while (_j >= 0 && w[_i] != w[_j])
        {
            _j = next[_j];
        }

        ++_i; ++_j;
        next[_i] = _j;
    }

    int i = 0, j = 0, ans = 0;
    while (i <= sizeS - 1)
    {
        while (j >= 0 && s[i] != w[j])
        {
            j = next[j];
        }
        
        ++i; ++j;
        if (j == sizeW)
        {
            ++ans;

            j = next[j];
        }
    }

    return ans;
}

int main()
{
    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        string itoc, w, s; fin >> itoc >> w >> s;
        int sizeA = itoc.size(), sizeW = w.size();

        vector<int> ctoi(256, -1);
        for (int i = 0; i <= sizeA - 1; ++i)
        {
            ctoi[itoc[i]] = i;
        }

        vector<int> w_i(sizeW, -1);
        for (int i = 0; i <= sizeW - 1; ++i) w_i[i] = ctoi[w[i]];

        vector<int> ans;
        for (int move = 0; move <= sizeA - 1; ++move)
        {
            for (int i = 0; i <= sizeW - 1; ++i)
            {
                w[i] = itoc[(w_i[i] + move) % sizeA];
            }

            if (_count(s, w) == 1)
            {
                ans.push_back(move);
            }
        }

        int sizeAns = ans.size();

        if      (sizeAns == 0) fout << "no solution";
        else if (sizeAns == 1) fout << "unique:";
        else                   fout << "ambiguous:";

        for (int i = 0; i <= sizeAns - 1; ++i)
        {
            fout << ' ' << ans[i];
        }
        fout << '\n';
    }

    return 0;
}
