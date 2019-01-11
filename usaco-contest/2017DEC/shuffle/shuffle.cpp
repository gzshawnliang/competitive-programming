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

void shuffle(vector<int> & s, vector<int> & stage)
{
    int n = s.size() - 1;
    vector<int> backStage(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        backStage[s[i]] += stage[i];
        stage[i] = 0;
    }

    stage = backStage;
}

vector<int> gen(vector<int> & stage)
{
    int n = stage.size() - 1;

    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = stage[i] > 0;
    }

    return ans;
}

int main()
{
    int n; fin >> n;
    vector<int> s(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        fin >> s[i];
    }

    int total = n;
    vector<int> stage(n + 1, 1);
    map<vector<int>, bool> m;

    while (true)
    {
        vector<int> temp = gen(stage);

        if (m[temp] == true)
        {
            break;
        }

        m[temp] = true;
        
        shuffle(s, stage);

        int _count = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (stage[i] > 0)
            {
                ++_count;
            }
        }
        total = min(total, _count);

        // for (int i = 1; i <= n; ++i)
        // {
        //     fout << stage[i] << ' ';
        // }
        // fout << '\n';
    }

    fout << total << '\n';

    return 0;
}