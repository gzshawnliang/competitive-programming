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

ifstream fin("dynamicFrog.in");
ofstream fout("dynamicFrog.out");

struct stone
{
    bool type;
    int pos;

    bool operator<(const stone &temp)
    {
        return pos < temp.pos;
    }
};

int main()
{
    int totalTest;
    fin >> totalTest;
    for (int c = 1; c <= totalTest; ++c)
    {
        int n, d;
        fin >> n >> d;
        vector<stone> a;
        for (int c0 = 1; c0 <= n; ++c0)
        {
            string in;
            fin >> in;
            int size0 = in.size();
            stone pushIn;
            if (in[0] == 'S')
            {
                pushIn.type = false;
            }
            else
            {
                pushIn.type = true;
            }

            string temp = "";
            for (int i = 2; i <= size0 - 1; ++i)
            {
                temp += in[i];
            }

            pushIn.pos = stoi(temp);

            a.push_back(pushIn);
        }

        stone temp{1, 0};
        a.push_back(temp);
        temp = {1, d};
        a.push_back(temp);
        n += 2;

        sort(a.begin(), a.end());

        // for (int i = 0; i <= n - 1; ++i)
        // {
        //     fout << a[i].type << ' ' << a[i].pos << '\n';
        // }
        // fout << '\n';

        int i = 0, maxD = 0;
        while (i <= n - 2)
        {
            int pos1 = i, count = 0, tempMaxD = 0;
            ++i;

            while (a[i].type == false)
            {
                ++count;
                if (count > 1)
                {
                    tempMaxD = max(tempMaxD, a[i].pos - a[i - 2].pos);
                }
                ++i;
            }

            tempMaxD = max(tempMaxD, a[i].pos - a[i - 2].pos);

            if (count <= 1)
            {
                maxD = max(maxD, a[i].pos - a[pos1].pos);
            }
            else
            {
                maxD = max(maxD, tempMaxD);
            }
        }

        fout << "Case " << c << ": " << maxD << '\n';
    }

    return 0;
}