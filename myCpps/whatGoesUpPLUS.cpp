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

ifstream fin("whatGoesUp.in");
ofstream fout("whatGoesUp.out");

int main()
{
    vector<int> a;
    int in;
    while (fin >> in)
    {
        a.push_back(in);
    }

    int size0 = a.size();
    vector<int> tempAns = {a[0]}, pos = {0};
    for (int i = 1; i <= size0 - 1; ++i)
    {
        auto it = lower_bound(tempAns.begin(), tempAns.end(), a[i]);
        if (it == tempAns.end())
        {
            tempAns.push_back(a[i]);
            pos.push_back(tempAns.size() - 1);
        }
        else
        {
            int nowPos = it - tempAns.begin();
            tempAns[nowPos] = a[i];
            pos.push_back(nowPos);
        }
    }

    int size1 = tempAns.size();
    fout << size1 << "\n-\n";

    int want = size1 - 1;
    vector<int> temp;
    for (int i = size0 - 1; i >= 0 && want >= 0; --i)
    {
        if (pos[i] == want)
        {
            temp.push_back(a[i]);
            --want;
        }
    }

    for (int i = size1 - 1; i >= 0; --i)
    {
        fout << temp[i] << '\n';
    }

    return 0;
}