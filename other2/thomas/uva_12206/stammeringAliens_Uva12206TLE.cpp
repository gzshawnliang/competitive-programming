#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

const int M = 1e9 + 7;
const int B = 1031;

ifstream fin("stammeringAliens_Uva12206.in");
//ofstream fout("stammeringAliens_Uva12206.out");

ull hashCode(const string & x)
{
    int len = x.length();
    unsigned long long ans = 0;
    for (int i = 0; i <= len - 1; ++i)
    {
        ans = (ull)(ans * B + x[i]);
    }
    return ans;
}

int main()
{
    while (true)
    {
        int m;
        fin >> m;
        if (m == 0)
            break;

        string s;
        fin >> s;

        unordered_map<ull, int> umap;

        int len = s.length();
        int subLen = 0;
        int subPos = 0;
        for (int i = 0; i <= len - 1; ++i)
        {
            ull subStrHash = 0; //子串哈希值
            for (int j = i; j <= len - 1; ++j)
            {
                subStrHash = (subStrHash * B + s[j]);

                if (j - i + 1 < subLen)
                {
                    continue;
                }

                ++umap[subStrHash];
                if (umap[subStrHash] >= m)
                {
                    if (j - i + 1 >= subLen)
                    {
                        subLen = j - i + 1;
                        subPos = i;
                    }
                }
            }
        }
        if (subLen > 0)
            cout << subLen << " " << subPos << "\n";
        else
            cout << "none\n";
    }

    return 0;
}
