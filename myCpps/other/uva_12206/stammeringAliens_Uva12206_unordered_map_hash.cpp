/*
===========================================================
 * @名称:		12206 Stammering Aliens
 * @作者:		Shawn 
 * @创建时间: 2019-10-14 22:05:13 
 * @修改人:   Shawn 
 * @修改时间: 2019-10-14 22:05:13 
 * @备注:		Rabin-Karp算法（哈希Hash查找算法）
 * @题目来源： https://uva.onlinejudge.org/external/122/12206.pdf
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
const ull R = 13331; //质数

bool check(const string & s, const int & m, int L)
{
    unordered_map<ull, int> umap; //unordered_map比map快一点
    int len = s.length();

    ull subStrHash = 0; //子串哈希值
    ull rMax = 1;
    for (int i = 0; i <= L - 1; ++i)
    {
        subStrHash = (subStrHash * R + s[i]);
        if (i > 0)
            rMax *= R;
    }
    ++umap[subStrHash];
    if (umap[subStrHash] >= m)
    {
        return true;
    }

    for (int i = 1; i + L <= len; ++i)
    {
        subStrHash -= (rMax * s[i - 1]);
        subStrHash *= R;
        subStrHash += s[i + L - 1];

        ++umap[subStrHash];
        if (umap[subStrHash] >= m)
        {
            return true;
        }
    }
    return false;
}

int getPos(const string & s, const int & m, int L)
{
    int subPos = -1;

    unordered_map<ull, int> umap;
    int len = s.length();

    ull subStrHash = 0; //子串哈希值
    ull rMax = 1;
    for (int i = 0; i <= L - 1; ++i)
    {
        subStrHash = (subStrHash * R + s[i]);
        if (i > 0)
            rMax *= R;
    }
    ++umap[subStrHash];
    if (umap[subStrHash] >= m)
    {
        subPos = 0;
    }

    for (int i = 1; i + L <= len; ++i)
    {
        subStrHash -= (rMax * s[i - 1]);
        subStrHash *= R;
        subStrHash += s[i + L - 1];

        ++umap[subStrHash];
        if (umap[subStrHash] >= m)
        {
            subPos = i;
        }
    }
    return subPos;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("stammeringAliens_Uva12206.in", "r", stdin);
    //freopen("stammeringAliens_Uva12206.out", "w", stdout);
#endif

    while (true)
    {
        int m;
        cin >> m;
        if (m == 0)
            break;

        string s;
        cin >> s;

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

        int subMaxLen = l;
        if (check(s, m, r)) //l和r只相差1，如右值满足使用右值，subMaxLen更大
            subMaxLen = r;

        int subRightmostPos = getPos(s, m, subMaxLen);
        if (subRightmostPos == -1)
        {
            cout << "none\n";
        }
        else
        {
            cout << subMaxLen << " " << subRightmostPos << "\n";
        }
    }

    return 0;
}
