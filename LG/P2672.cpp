#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

ifstream fin("P2672.in");
ofstream fout("P2672.out");

struct house
{
    int d;
    int v;

    bool operator<(const house & temp) const
    {
        return v > temp.v;
    }
};

int main()
{
    int n;
    fin >> n;

    vector<int> qm(n + 1, 0), q(n + 1, 0), h(n + 2, 0);
    vector<house> a(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i].d;
    }

    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i].v;
    }

    sort(a.begin() + 1, a.end());

    for (int i = n; i >= 1; i--)
    {
        h[i] = max(h[i + 1], 2 * a[i].d + a[i].v);
    }

    for (int i = 1; i <= n; i++)
    {
        qm[i] = max(qm[i - 1], a[i].d);
        q[i] = q[i - 1] + a[i].v;
    }
        
    for (int x = 1; x <= n; ++x)
    {
        fout << max(h[x] + q[x - 1], 2 * qm[x] + q[x]) << '\n';
    }

    return 0;
}