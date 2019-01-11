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

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

int main()
{
    int n; fin >> n;
    vector<int> a(n + 1), cows(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        fin >> cows[i];
    }

    for (int c = 1; c <= 3; ++c)
    {
        vector<int> back(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            back[i] = cows[a[i]];
        }
        
        cows = back;
    }

    for (int i = 1; i <= n; ++i)
    {
        fout << cows[i] << '\n';
    }

    return 0;
}
