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
        cin >> t >> n;
        if (t == 0 && n == 0)
        {
            break;
        }

        vector<int> a(n), out;
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
            total += a[i];
        }

        cout << "Sums of " << t << ":\n";

        if (total < t)
        {
            cout << "NONE" << '\n';
            continue;
        }
        else if (total == t)
        {
            cout << a[0];
            for (int i = 1; i <= n - 1; ++i)
            {
                cout << '+' << a[i];
            }
            cout << '\n';
            continue;
        }

        sort(a.begin(), a.end());
        solve(t, a, out, 0);

        if (sth == false)
        {
            cout << "NONE" << '\n';
            continue;
        }
        for (auto it = ans.rbegin(); it != ans.rend(); ++it)
        {
            vector<int> out = *it;
            int size = out.size();
            cout << out[0];
            for (int i = 1; i <= size - 1; ++i)
            {
                cout << '+' << out[i];
            }
            cout << '\n';
        }
    }

    return 0;
}