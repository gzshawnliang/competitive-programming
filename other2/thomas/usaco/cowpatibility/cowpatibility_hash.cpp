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
    vector<vector<int>> a(N+1,vector<int>(5+1,0));
    unordered_map<ll,int> b;
    unordered_map<int,int> c;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= 5; ++j)
            fin >> a[i][j];
            
        sort(a[i].begin()+1,a[i].end());

        for (int j = 1; j <= 5; ++j)
        {
            ll hashValue1=0;
            for (int len = 1; j+len-1 <= 5; ++len)
            {
                hashValue1 = (BASE * hashValue1 + a[i][j+len-1]) % PRIME;
                ++b[hashValue1];
                if(b[hashValue1]>1)
                    ++c[len];
            }
        }

    }

    for(auto it=c.begin();it!=c.end();++it)
        ++(it->second);

    int ans=0;

    fout << N*(N-1)/2 - ans << "\n";
    return 0;
}
