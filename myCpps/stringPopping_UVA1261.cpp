#include <bits/stdc++.h>

using namespace std;

ifstream fin("stringPopping_UVA1261.in");
ofstream fout("stringPopping_UVA1261.out");

struct g
{
    char ch;
    int size;
};

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        string in; fin >> in;

        char last = in[0];
        int sizeI = in.size(), _count = 1;
        vector<g> s;

        for (int i = 1; i <= sizeI; ++i)
        {
            if (in[i] != last)
            {
                g temp{last, _count};
                s.push_back(temp);

                last = in[i];
                _count = 1;
            }
            else
            {
                ++_count;
            }
        }

        int n = s.size();
        while (true)
        {
            bool ok = false;
            for (int i = 1; i <= n - 2; ++i)
            {
                if (s[i - 1].ch == s[i + 1].ch)
                {
                    ok = true;
                }

                s[i - 1].size += s[i + 1].size;

                s.erase(s.begin() + i); s.erase(s.begin() + i);
            }

            if (ok == false)
            {
                break;
            }
        }

        if (s.size() > 1)
        {
            fout << "0\n";
        }
        else if (s[0].size <= 1)
        {
            fout << "0\n";
        }
        else
        {
            fout << "1\n";
        }
    }

    return 0;
}
