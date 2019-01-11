#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

ifstream fin("newHanoi.in");
ofstream fout("newHanoi.out");


int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(7);
    int last = 7, add = 4;
    for (int i = 1; i <= 48; ++i)
    {
        if (i % 2 == 0)
        {
            add += 2;
        }
        a.push_back(last + add);
        last = last + add;
    }

    int count;
    fin >> count;
    for (int i = 1; i <= count; ++i)
    {
        int size;
        fin >> size;
        fout << a[size - 1] << '\n';
    }

    return 0;
}