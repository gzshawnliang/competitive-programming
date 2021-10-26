#include <bits/stdc++.h>

using namespace std;

ifstream fin("prefixSum1d.in");
ofstream fout("prefixSum1d.out");

int main()
{
    int n,m;
    fin >> n >> m;
    vector<int> a(n+1,0);
    a[0]=0;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    vector<int> b(n+1);       //prefixSum of a
    
    b[0]=a[0];
    for (int i = 1; i <= n ; ++i)
        b[i]=b[i-1]+a[i];

    for (int i = 1; i <= m ; ++i)
    {
        int p,q;
        fin >> p >> q;
        fout <<  b[q] - b[p-1] << "\n";
    }

    return 0;
}
