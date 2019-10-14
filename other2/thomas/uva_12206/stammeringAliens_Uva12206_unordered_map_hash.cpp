#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

const ull M = 1e9 + 7;
const ull R = 13331;

bool check(const string & s, const int & m, int L)
{
    unordered_map<ull, int> umap;
    int len = s.length();
    
    ull subStrHash = 0;      //子串哈希值
    ull rMax = 1 ;
    for (int i = 0; i <= L - 1; ++i)
    {
        subStrHash = (subStrHash * R + s[i]);
        if(i>0)
            rMax *= R;
    }
    ++umap[subStrHash];
    if (umap[subStrHash] >= m)
    {
        return true;
    }

    for (int i = 1; i + L <= len ; ++i)
    {
        subStrHash -= (rMax*s[i-1]);
        subStrHash *= R;
        subStrHash += s[i+L-1];
        
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

    ull subStrHash = 0;      //子串哈希值
    ull rMax = 1 ;
    for (int i = 0; i <= L - 1; ++i)
    {
        subStrHash = (subStrHash * R + s[i]);
        if(i>0)
            rMax *= R;
    }
    ++umap[subStrHash];
    if (umap[subStrHash] >= m)
    {
        subPos=0;
    }

    for (int i = 1; i + L <= len ; ++i)
    {
        subStrHash -= (rMax*s[i-1]);
        subStrHash *= R;
        subStrHash += s[i+L-1];

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
