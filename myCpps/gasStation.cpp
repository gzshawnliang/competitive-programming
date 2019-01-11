#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("gasStation.in");
ofstream fout("gasStation.out");

struct gasStation
{
    int pos;
    int rad;

    bool operator<(const gasStation &temp)
    {
        return pos + rad < temp.pos + temp.rad;
    }
};

int station(int wantPos, vector<gasStation> a)
{
    int size = a.size();
    for (int i = size - 1; i >= 0; --i)
    {
        if (a[i].pos - a[i].rad <= wantPos)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    while (true)
    {
        int l = 0, g;
        fin >> l >> g;

        if (l == 0)
        {
            break;
        }

        vector<gasStation> a(g);
        for (int i = 0; i <= g - 1; ++i)
        {
            fin >> a[i].pos >> a[i].rad;
        }

        sort(a.begin(), a.end());

        int nowPos = 0, ans = 0, last = -1;
        while (nowPos < l)
        {
            int res = station(nowPos, a);
            if (res == last)
            {
                ans = -1;
                break;
            }
            else if (res == -1)
            {
                ans = -1;
                break;
            }
            else
            {
                last = res;
                nowPos = a[res].pos + a[res].rad;
                ++ans;
            }
        }

        if (ans == -1)
        {
            fout << "-1\n";
        }
        else
        {
            fout << g - ans << '\n';
        }
    }

    return 0;
}