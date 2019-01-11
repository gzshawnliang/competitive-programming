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
#include <queue>

using namespace std;

ifstream fin("convention2.in");
ofstream fout("convention2.out");

struct cow1
{
    int z;
    int a;
    int t;

    bool operator<(const cow1 &temp) const
    {
        return a > temp.a;
    }
};

struct cow2
{
    int z;
    int a;
    int t;

    bool operator<(const cow2 &temp) const
    {
        return z > temp.z;
    }
};

cow2 trans(cow1 c)
{
    cow2 temp{c.z, c.a, c.t};

    return temp;
}

int main()
{
    int n; fin >> n;
    priority_queue<cow1> farm;

    int _count = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        int a, t; fin >> a >> t;
        cow1 temp{_count, a, t};

        ++_count;

        farm.push(temp);
    }

    int _time = farm.top().a;
    priority_queue<cow2> q;

    q.push(trans(farm.top()));
    farm.pop();

    vector<int> timer(n, 0);

    while (!q.empty() || !farm.empty())
    {
        if (q.empty() == true)
        {
            _time = farm.top().a;
            q.push(trans(farm.top()));
            farm.pop();
        }

        _time += q.top().t;

        priority_queue<cow2> tempP = q;
        while (!tempP.empty())
        {
            if (tempP.top().z != q.top().z)
            {
                timer[tempP.top().z] += q.top().t;
            }
            tempP.pop();
        }

        q.pop();

        if (!farm.empty())
        {
            while (farm.top().a <= _time)
            {
                cow1 temp = farm.top();

                q.push(trans(temp));
                timer[temp.z] = _time - farm.top().a;

                farm.pop();

                if (farm.empty())
                {
                    break;
                }
            }
        }
    }

    fout << *max_element(timer.begin(), timer.end()) << '\n';

    return 0;
}
