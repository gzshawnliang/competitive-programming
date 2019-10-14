#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

const int M = 1e9 + 7;
const int B = 1031;

ifstream fin("stammeringAliens_Uva12206.in");
//ofstream fout("stammeringAliens_Uva12206.out");

bool check(const string & s, const int & m, int L)
{
    map<string, int> umap;
    int len = s.length();
    for (int i = 0; i <= len - 1; ++i)
    {
        string subStr = s.substr(i, L);

        ++umap[subStr];
        if (umap[subStr] >= m)
        {
            return true;
        }
    }
    return false;
}

int getPos(const string & s, const int & m, int L)
{
    int subPos = -1;

    map<string, int> umap;
    int len = s.length();
    for (int i = 0; i <= len - L; ++i)
    {
        string subStr = s.substr(i, L);

        ++umap[subStr];
        if (umap[subStr] >= m)
        {
            subPos = i;
        }
    }
    return subPos;
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

        int l = 1;
        int r = s.length();
        int mid;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (check(s, m, mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        int subLen = l;
        if (check(s, m, r)) //如右值满足使用右值，subLen更大
            subLen = r;

        int subPos = getPos(s, m, subLen);
        if (subPos == -1)
        {
            cout << "none\n";
        }
        else
        {
            cout << subLen << " " << subPos << "\n";
        }
    }

    return 0;
}
