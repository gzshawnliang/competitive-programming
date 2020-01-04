#include <bits/stdc++.h>

using namespace std;

ifstream fin("dishes.in");
ofstream fout("dishes.out");

bool check(int size, vector<int> & a)
{
    vector<int> b;
    for (int i = 0; i <= size - 1; ++i)
    {
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());

    vector<int> top(1, 0); top[0] = a[0];
    vector<vector<int>> desk; desk.push_back(vector<int>(1, a[0]));
    
    int smallestPos = 0, i = 1;
    while (true)
    {
        bool flag = false;
        if (i <= size - 1)
        {
            int nowPlate = a[i];
            int pos = lower_bound(top.begin(), top.end(), nowPlate) - top.begin();

            if (pos == top.size())
            {
                top.push_back(nowPlate);
                desk.push_back(vector<int>(1, nowPlate));
            }
            else
            {
                top[pos] = nowPlate;
                desk[pos].push_back(nowPlate);
            }

            ++i;

            flag = true;
        }

        while (top[0] == b[smallestPos])
           {
            ++smallestPos;
            desk[0].erase(desk[0].begin() + desk[0].size() - 1);

            if (desk[0].size() == 0)
            {
                top.erase(top.begin());
                desk.erase(desk.begin());
            }
            else
            {
                top[0] = desk[0].back();
            }

            flag = true;
        }

        if (flag == false)
        {
            break;
        }
    }

    return smallestPos >= size;
}

int main()
{
    int n; fin >> n;

    vector<int> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }

    int lb = 1, rb = n, ans = 0;
    while (lb <= rb)
    {
        int mid = (lb + rb) / 2;
        if (check(mid, a) == true)
        {
            lb = mid + 1;

            ans = mid;
        }
        else
        {
            rb = mid - 1;
        }
    }

    fout << ans << '\n';

    return 0;
}
