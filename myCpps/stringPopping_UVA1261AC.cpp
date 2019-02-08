#include <bits/stdc++.h>

using namespace std;

ifstream fin("stringPopping_UVA1261.in");
ofstream fout("stringPopping_UVA1261.out");

bool solve(string & s)
{
    if (s.size() == 0)
    {
        return true;
    }
    else
    {
        bool ans = false;

        int n = s.size(); 
        for (int i = 0; i <= n - 1; ++i)
        {
            int _count = 0;
            string temp = s;

            while (temp[i] == s[i])
            {
                temp.erase(temp.begin() + i);
                ++_count;
            }

            if (_count > 1)
            {
                ans = (ans || solve(temp));
            }
        }

        return ans;
    }
}

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        string s; fin >> s;

        fout << solve(s) << '\n';
    }

    return 0;
}
