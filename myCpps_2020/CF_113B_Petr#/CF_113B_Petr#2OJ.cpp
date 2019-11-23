#include <bits/stdc++.h>

using namespace std;


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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    string t, sbegin, send; cin >> t >> sbegin >> send;

    ll hb = _hash(sbegin), he = _hash(send);

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

    cout << ans.size() << '\n';

   	cout.flush();
   	return 0;
}

