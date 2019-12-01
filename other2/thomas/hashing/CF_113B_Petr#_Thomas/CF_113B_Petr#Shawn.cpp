#include <bits/stdc++.h>

using namespace std;

ifstream fin("CF_113B_Petr#.in");
ofstream fout("CF_113B_Petr#.out");

using ll = unsigned long long;

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

    ll hb = _hash2(sbegin), he = _hash2(send);

    int sizeT = t.size(), sizeB = sbegin.size(), sizeE = send.size(), minSize = max(sizeB, sizeE);
    unordered_set<ll> ans;

    ll nowBase = 1;
    for (int c = 1; c <= sizeE - 1; ++c)
    {
        nowBase *= base;
    }
    
    for (int i = 0; i <= sizeT - minSize; ++i)
    {
        string nowH = t.substr(i, sizeB); if (nowH != sbegin) continue;
        
        string nowT = t.substr(i + minSize - sizeE, sizeE);
        ll nowHash = _hash2(nowH), nowTH = _hash2(nowT);

        if (nowT == send) ans.insert(nowHash);

        for (int j = i + minSize; j <= sizeT - 1; ++j)
        {
            nowHash = nowHash * base + t[j];
            nowTH = (nowTH - nowBase * t[j - sizeE]) * base + t[j];
            //++sumCount;
            if (nowTH == he) ans.insert(nowHash);
        }
    }

    fout << ans.size() << '\n';
    //cout << sumCount << "\n";
    return 0;
}
