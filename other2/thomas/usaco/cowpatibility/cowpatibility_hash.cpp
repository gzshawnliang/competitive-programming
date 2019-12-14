#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");

using ll = long long;
const ll BASE = 78539;
const ll PRIME = 1e9 + 7;

int main()
{
    int N;
    fin >>N;
    vector<unordered_set<int>> a(N+1);
    unordered_map<int,set<int>> b;

    for (int i = 1; i <= N; ++i)
    {
        int c=5;
        while (c--)
        {
            int temp;
            fin >> temp;
            a[i].insert(temp);
            b[temp].insert(i);
        }
    }
    set<ll> c;
    int ans=0;
    for (auto it = b.begin(); it !=b.end(); ++it)
    {
        for (auto it2 = it->second.begin(); it2 !=it->second.end(); ++it2)
        {
            auto it3=it2;
            ++it3;
            ll hashValue1=0;
            for (; it3 !=it->second.end(); ++it3)
            {
                hashValue1 = (BASE * hashValue1 + *it2) % PRIME;
                hashValue1 = (BASE * hashValue1 + *it3) % PRIME;
                if(c.count(hashValue1)==0)
                {
                    c.insert(hashValue1);
                    ++ans;
                }
                
                hashValue1=0;
            }
        }
    }
    fout << N*(N-1)/2 - ans << "\n";
    return 0;
}
