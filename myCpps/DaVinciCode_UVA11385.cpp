#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define ll long long

ifstream fin("DaVinciCode_UVA11385.in");
ofstream fout("DaVinciCode_UVA11385.out");

int main()
{
    vector<ll> fibonacci = {1, 1};
    map<ll, ll> position;
    position[1] = 1;
    int _i = 1;
    ll limit = (ll)pow(2.0, 31.0);
    while (true)
    {
        ++_i;
        ll temp = (ll)fibonacci[_i - 1] + (ll)fibonacci[_i - 2];
        if (temp < limit)
        {
            position[temp] = _i;
            fibonacci.push_back(temp);
        }
        else
        {
            break;
        }
    }

    int T; fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n; fin >> n;
        vector<ll> clue(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> clue[i];
        }

        string in, ans = "";
        getline(fin, in);
        getline(fin, in);
        for (int i = 0; i <= 45; ++i)
        {
            ans += ' ';
        }

        int size = in.size(), j = 0;
        for (int i = 0; i <= size - 1 && j <= n - 1; ++i)
        {
            if (in[i] >= 'A' && in[i] <= 'Z')
            {
                ans[position[clue[j]]] = in[i];
                ++j;
            }
        }

        int endPos = 45;
        while (ans[endPos] == ' ')
        {
            --endPos;
        }

        for (int i = 1; i <= endPos; ++i)
        {
            fout << ans[i];
        }
        fout << '\n';
    }

    return 0;
}
