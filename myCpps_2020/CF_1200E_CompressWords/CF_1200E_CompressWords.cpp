/*
===========================================================
* @Name:           1200E Compress Words
* @Author:         Shawn
* @create Time:    2019/11/23 21:12:31
* @url:            https://codeforces.com/contest/1200/problem/E
* @Description:    
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

ifstream fin("CF_1200E_CompressWords.in");
ofstream fout("CF_1200E_CompressWords.out");

using ll = long long;
const ll base = 131, mode = 201326611;

void merge(string &a, string &b)
{
    int sizeA = a.size(), sizeB = b.size(), sizeMin = min(sizeA, sizeB);
    ll hashA = 0, hashB = 0;
    
    int ans = 0;
    ll nowB = 1;
    for (int len = 1; len <= sizeMin; ++len)
    {
        hashA = (hashA + (nowB * a[sizeA - len]) % mode) % mode;
        nowB = (nowB * base) % mode;

        hashB = ((hashB * base) % mode + b[len - 1] % mode) % mode;

        if (hashA == hashB)
        {
            ans = len;
        }
    }

    a += b.substr(ans, sizeB - ans);
}

int main()
{
    int n; fin >> n;

    vector<string> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }

    string now = a[0];
    for (int i = 1; i <= n - 1; ++i)
    {
        merge(now, a[i]);
    }

    fout << now << '\n';

    return 0;
}
