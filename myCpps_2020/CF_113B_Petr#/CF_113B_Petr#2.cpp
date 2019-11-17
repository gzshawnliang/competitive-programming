#include <bits/stdc++.h>

using namespace std;

ifstream fin("CF_113B_Petr#.in");
ofstream fout("CF_113B_Petr#.out");

using ll = unsigned long long;

const ll base = 137;

ll _hash(string & s)
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

    ll hb = _hash(sbegin), he = _hash(send);

    int sizeT = t.size(), sizeB = sbegin.size(), sizeE = send.size(), minSize = max(sizeB, sizeE);
    unordered_set<ll> ans;


    ll nowBase = pow(base, sizeE - 1);

    for (int i = 0; i <= sizeT - minSize; ++i)
    {
        string nowH = t.substr(i, sizeB); if (nowH != sbegin) continue;
        
        string now = t.substr(i, minSize), nowT = t.substr(i + minSize - sizeE, sizeE);
        ll nowTH = _hash(nowT);

        if (nowT == send) ans.insert(_hash(now));

        for (int j = i + minSize; j <= sizeT - 1; ++j)
        {
            nowTH = (nowTH - nowBase * t[j - sizeE]) * base + t[j];
            now += t[j];

            if (nowTH == he) ans.insert(_hash(now));
        }
    }

    fout << ans.size() << '\n';

    return 0;
}
