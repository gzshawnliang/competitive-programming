#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("coinCollector.in");
ofstream fout("coinCollector.out");

int main()
{
    int totalTest;
    fin >> totalTest;
    for (int c = 1; c <= totalTest; ++c)
    {
        int size;
        fin >> size;

        vector<int> coins(size);
        for (int i = 0; i <= size - 1; ++i)
        {
            fin >> coins[i];
        }

        int sum = coins[0], totalChoose = 1;
        for (int i = 1; i <= size - 1; ++i)
        {
            if (i == size - 1)
            {
                 sum += coins[i];
                ++totalChoose;
            }
            else if (sum + coins[i] < coins[i + 1])
            {
                sum += coins[i];
                ++totalChoose;
            }
        }

        fout << totalChoose << '\n';
    }
}