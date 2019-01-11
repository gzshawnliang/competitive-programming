#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

ifstream fin("P1328.in");
ofstream fout("P1328.out");

int main()
{
    vector<vector<bool>> game = 
    {
        {0,0,1,1,0},
        {1,0,0,1,0},
        {0,1,0,0,1},
        {0,0,1,0,1},
        {1,1,0,0,0}
    };

    int n, A, B; fin >> n >> A >> B;
    vector<int> a(A), b(B);

    for (int i = 0; i <= A - 1; ++i)
    {
        fin >> a[i];
    }
    for (int i = 0; i <= B - 1; ++i)
    {
        fin >> b[i];
    }

    int totalA = 0, totalB = 0;
    for (int g = 0; g <= n - 1; ++g)
    {
        totalA += game[a[g % A]][b[g % B]];
        totalB += game[b[g % B]][a[g % A]];
    }

    fout << totalA << ' ' << totalB << '\n';

    return 0;
}