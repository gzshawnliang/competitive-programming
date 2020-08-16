#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

using ill = long long;

//ifstream fin("1.in");
//ofstream fout("1.out");

int main()
{
    vector<ill> a={40,50, 60, 94, 100, 106, 112, 144, 150, 156};
    ill p=1;
    for (int i = 0; i <= a.size() - 1; ++i)
    {
        p = p * a[i];
    }
    cout << p % 1000000007LL << "\n";
    return 0;
}
