#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

ifstream fin("citystate.in");
ofstream fout("citystate.out");

int main()
{
    map<int, map<int, int>> mmp;

    int n, ans = 0;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string a, b;
        fin >> a >> b;

        int A = a[0] * 26 + a[1];
        int B = b[0] * 26 + b[1];
        
        ans += mmp[B][A];

        if (A == B)
        {
            ans -= mmp[A][B];
        }
            
        ++mmp[A][B];
    }
    
    fout << ans << '\n';

    return 0;
}