/*
===========================================================
* @Name:           113B Petr#
* @Author:         Shawn
* @create Time:    2019/11/16 21:40:48
* @url:            https://codeforces.com/contest/113/problem/bp
* @Description:    
===========================================================
*/

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

    int sizeT = t.size(), sizeB = sbegin.size(), sizeE = send.size();
    ll nowH, nowB;
    
    string temp;
    vector<int> bp, ep;

    temp = t.substr(0, sizeB);
    nowH = _hash(temp);
    nowB = pow(base, sizeB - 1);
    for (int i = 0; i <= sizeT - sizeB; ++i)
    {
        if (nowH == hb) bp.push_back(i);
        
        nowH = (nowH - nowB * t[i]) * base + t[i + sizeB];
    }

    temp = t.substr(0, sizeE);
    nowH = _hash(temp);
    nowB = pow(base, sizeE - 1);
    for (int i = 0; i <= sizeT - sizeE; ++i)
    {
        if (nowH == he) ep.push_back(i);
        
        nowH = (nowH - nowB * t[i]) * base + t[i + sizeE];
    }

    int sizeBP = bp.size(), sizeEP = ep.size();
    unordered_set<ll> ans;
    for (int i = 0; i <= sizeBP - 1; ++i)
    {

        for (int j = 0; j <= sizeEP - 1; ++j)
        {
            if (bp[i] > ep[j]) continue;

            int nowSize = ep[j] - bp[i] + sizeE;

            temp = t.substr(bp[i], nowSize);
            ans.insert(_hash(temp));
        }
    }

    cout << ans.size() << '\n';

   	cout.flush();
   	return 0;
}

