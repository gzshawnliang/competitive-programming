#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

ifstream fin("newHanoi.in");
ofstream fout("newHanoi.out");

bool isSquare(int in)
{
    int i = sqrt(in);
    return i * i == in;
}

int solve(vector<int> a, int now)
{ 
    int size = a.size(), maxCount = 0;

    // for (int i = 0; i <= size - 1; ++i)
    // {
    //     fout << a[i] << ' ';
    // }
    // fout << '\n';

    bool sth = false;
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i <= size - 1; ++i)
    {
        if (isSquare(a[i] + now) == true && pos2 == -1 && a[i] != -1)
        {
            pos2 = i;
        }
        if (a[i] == -1 && pos1 == -1)
        {
            pos1 = i;
        }
    }

    if (pos1 == -1 && pos2 == -1)
    {
        return now - 1;
    }

    if (pos1 != -1)
    {
        int temp1 = a[pos1];
        a[pos1] = now;
        maxCount = max(maxCount, solve(a, now + 1));
        a[pos1] = temp1;
    }

    if (pos2 != -1)
    {
        int temp2 = a[pos2];
        a[pos2] = now;
        maxCount = max(maxCount, solve(a, now + 1));
        a[pos2] = temp2;
    }

    return maxCount;
}

int main()
{
    int count;
    fin >> count;

    for (int i = 1; i <= count; ++i)
    {
        int size;
        fin >> size;
        vector<int> a(size, -1);
        fout << solve(a, 1) << '\n';
    }

    return 0;
}