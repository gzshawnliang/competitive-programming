#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
const ull R1 = 3;                     //质数
const ull PRIME = 100000000743856857ll; //大质数1e9+7不够大

ull hashCode(const string & s)
{

    int len = s.length();
    ull hashValue = 0;
    for (int i = 0; i <= len - 1; ++i)
    {
        //hashValue = R1 * hashValue + (s[i] - 'a'+1);
        hashValue = (R1 * hashValue + (s[i] - 'a' + 1)) % PRIME;
    }
    return hashValue;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("CF_514C_WattoandMechanism.in", "r", stdin);
    //freopen("CF_631D_Messenger.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    unordered_set<ull> data;

    while (n--)
    {
        string x;
        cin >> x;

        ull xhash = hashCode(x);
        data.insert(xhash);
    }

    while (m--)
    {
        string x;
        cin >> x;

        ull xHash = hashCode(x);
        int len = x.length();
        bool found = false;
        ull p = 1;
        ull nowHash = 0;
        for (int i = len - 1; i >= 0 && !found; --i)
        {
            for (ull k = 1; k <= 3; ++k)
            {
                if (k == (ull)x[i] - 'a' + 1)
                {
                    continue;
                }
                ull aHash = ((x[i] - 'a' + 1) * p);
                ull kHash = (k * p);

                nowHash = (PRIME + xHash - aHash % PRIME + kHash % PRIME) % PRIME;
                if (data.count(nowHash) == 1)
                {
                    found = true;
                    break;
                }
            }
            p = (p * R1) % PRIME;
        }

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
