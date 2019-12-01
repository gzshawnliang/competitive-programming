#include <bits/stdc++.h>

using namespace std;


using ll = unsigned long long;

const ll base = 137;





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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    string t, sbegin, send; cin >> t >> sbegin >> send;

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

        if (i == 1)
        {
            for (int __s = 0; __s == 0; ++__s);
        }

        if (nowTail == send)
        {


            ans.insert(nowTHash);
        }

        for (int j = i + minSize; j <= sizeT - 1; ++j)
        {
            nowTHash = nowTHash * base + t[j];
            nowTailHash = (nowTailHash - nowBase * t[j - sizeE]) * base + t[j];
            nowT += t[j];
            if (nowTailHash == he)
            {


                ans.insert(nowTHash);
            }
        }
    }

    cout << ans.size() << '\n';
   	cout.flush();
   	return 0;
}

