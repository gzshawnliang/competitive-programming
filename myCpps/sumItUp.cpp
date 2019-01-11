#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

ifstream fin("sumItUp.in");
ofstream fout("sumItUp.out");

set<vector<int>> ans;
bool sth;

void solve(int t, vector<int> a, vector<int> out, int last)
{
    if (t == 0)
    {
        sth = true;
        sort(out.begin(), out.end(), greater<int>());
        ans.insert(out);

        return;
    }
    
    int size = a.size();
    for (int i = last; i <= size - 1; ++i)
    {
        if (a[i] <= t)
        {
            vector<int> temp1 = a, temp2 = out;
            temp1.erase(temp1.begin() + i);
            temp2.push_back(a[i]);
            solve(t - a[i], temp1, temp2, i);
        }
        else
        {
            return;
        }
    }
    
}

int main()
{
    while (true)
    {
        sth = false;
        ans.clear();
        int t = 0, n = 0, total = 0;
        fin >> t >> n;
        if (t == 0 && n == 0)
        {
            break;
        }

        vector<int> a(n), out;
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
            total += a[i];
        }

        fout << "Sums of " << t << ":\n";

        if (total < t)
        {
            fout << "NONE" << '\n';
            continue;
        }
        else if (total == t)
        {
            fout << a[0];
            for (int i = 1; i <= n - 1; ++i)
            {
                fout << '+' << a[i];
            }
            fout << '\n';
            continue;
        }

        sort(a.begin(), a.end());
        solve(t, a, out, 0);

        if (sth == false)
        {
            fout << "NONE" << '\n';
            continue;
        }
        for (auto it = ans.rbegin(); it != ans.rend(); ++it)
        {
            vector<int> out = *it;
            int size = out.size();
            fout << *out.begin();
            for (int i = 1; i <= size - 1; ++i)
            {
                fout << '+' << out[i];
            }
            fout << '\n';
        }
    }

    return 0;
}