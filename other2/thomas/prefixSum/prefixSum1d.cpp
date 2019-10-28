#include <bits/stdc++.h>

using namespace std;

ifstream fin("prefixSum1d.in");
ofstream fout("prefixSum1d.out");

int main()
{
    vector<int> a;
    

    int t;
    while (fin>>t)
    {
        a.push_back(t);
    }
    
    int sizeA=a.size();


    vector<int> b(sizeA);       //prefixSum of a
    
    b[0]=a[0];
    for (int i = 1; i <= sizeA - 1; ++i)
        b[i]=b[i-1]+a[i];


    for (int i = 0; i <= sizeA - 1; ++i)
        fout <<  b[i] << " ";

    return 0;
}
