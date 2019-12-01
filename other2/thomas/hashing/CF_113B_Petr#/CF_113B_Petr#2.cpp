#include <bits/stdc++.h>

using namespace std;

ifstream fin("CF_113B_Petr#.in");
ofstream fout("CF_113B_Petr#.out");

using ll = unsigned long long;

//const ll base = 137;
const ll base = 137;

//int sumCount=0;

// ll _hash(string & s)
// {
//     ll ans = 0;

//     int size = s.size();
//     for (int i = 0; i <= size - 1; ++i)
//     {
//         ans = ans * base + s[i];
//         ++sumCount;
//     }

//     return ans;
// }

ll _hash2(string & s)
{
    ll ans = 0;

    int size = s.size();
    for (int i = 0; i <= size - 1; ++i)
    {
        ans = ans * base + s[i];
    }

    return ans;
}

int main()
{
    string t, sbegin, send; fin >> t >> sbegin >> send;

    ll he = _hash2(send);

    int sizeT = t.size(), sizeB = sbegin.size(), sizeE = send.size(), minSize = max(sizeB, sizeE);
    unordered_set<ll> ans;

    ll nowBase = 1;
    for (int c = 1; c <= sizeE - 1; ++c)
    {
        nowBase *= base;
    }
    
    for (int i = 0; i <= sizeT - minSize; ++i)
    {
        string nowHead = t.substr(i, sizeB); if (nowHead != sbegin) continue;
        
        string nowTail = t.substr(i + minSize - sizeE, sizeE), nowT = t.substr(i, minSize);
        ll nowTHash = _hash2(nowT), nowTailHash = _hash2(nowTail);

        if (i == 4)
        {
            for (int __s = 0; __s == 0; ++__s);
        }

        if (nowT == send)
        {
            // if (ans.count(nowTHash) == 0)
            // {
            //     fout << t.substr(i, minSize) << '\n';
            // }

            //fout << i << ' ' << i + minSize - 1 << ": " << t.substr(i, minSize) << '\n';

            ans.insert(nowTHash);
        }

        for (int j = i + minSize; j <= sizeT - 1; ++j)
        {
            nowTHash = nowTHash * base + t[j];
            nowTailHash = (nowTailHash - nowBase * t[j - sizeE]) * base + t[j];
            nowT += t[j];
            //++sumCount;
            if (nowTailHash == he)
            {
                // if (ans.count(nowTHash) == 0)
                // {
                //     fout << t.substr(i, j - i + 1) << '\n';
                // }

                //fout << i << ' ' << j << ": " << t.substr(i, j - i + 1) << ": " << nowTHash << '\n';

                ans.insert(nowTHash);
            }
        }
    }

    fout << ans.size() << '\n';
    //cout << sumCount << "\n";
    return 0;
}
