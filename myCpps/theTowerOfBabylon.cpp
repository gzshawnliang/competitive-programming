#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("theTowerOfBabylon.in");
ofstream fout("theTowerOfBabylon.out");

struct cube
{
    int x;
    int y;
    int h;

    bool operator<(const cube &temp) const
    {
        if (x == temp.x && y == temp.y)
        {
            return h < temp.h;
        }
        else
        {
            if (x == temp.x)
            {
                return y < temp.y;
            }
            else
            {
                return x < temp.x;
            }
        }
    }

    bool operator==(const cube &temp) const
    {
        return x == temp.x && y == temp.y && h == temp.h;
    }
};

void add(vector<cube> & a, int x, int y, int z)
{
    set<cube> out;
    cube temp;

    temp.x = min(x, y); temp.y = max(x, y); temp.h = z;
    out.insert(temp);

    temp.x = min(z, x); temp.y = max(z, x); temp.h = y;
    out.insert(temp);

    temp.x = min(z, y); temp.y = max(z, y); temp.h = x;
    out.insert(temp);

    for (auto it = out.begin(); it != out.end(); ++it)
    {
        a.push_back(*it);
    }
}

bool good(cube m, cube n)
{
    return n.x < m.x && n.y < m.y;
}

int main()
{
    int testCase = 0;

    while (true)
    {
        ++testCase;

        int n = 0;
        fin >> n;

        if (n == 0)
        {
            break;
        }

        vector<cube> a;
        for (int i = 1; i <= n; ++i)
        {
            int x, y, z;
            fin >> x >> y >> z;

            add(a, x, y, z);
        }

        sort(a.begin(), a.end());

        int size = a.size();
        vector<int> dp(size);
        for (int i = 0; i <= size - 1; ++i)
        {
            dp[i] = a[i].h;
            for (int j = 0; j <= i - 1; ++j)
            {
                if (good(a[i], a[j]) == true)
                {
                    dp[i] = max(dp[i], dp[j] + a[i].h);
                }
            }
        }

        auto it = max_element(dp.begin(), dp.end());
        fout << "Case " << testCase << ": maximum height = " << *it << '\n';
    }

    return 0;
}