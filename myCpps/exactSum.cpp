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
#include <climits>

using namespace std;

ifstream fin("exactSum.in");
ofstream fout("exactSum.out");

int main()
{
    while (true)
    {
        int n = -1, totalCost;
        fin >> n;

        if (n == -1)
        {
            break;
        }
        vector<int> books(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> books[i];
        }
        sort(books.begin(), books.end());

        fin >> totalCost;

        int minDifferent = INT_MAX;
        int a = books[0], b = books.back();
        for (int i = 0; i <= n - 1; ++i)
        {
            auto it = lower_bound(books.begin(), books.end(), totalCost - books[i]);
            if (*it == totalCost - books[i])
            {
                if (it - books.begin() != i)
                {
                    if (abs(totalCost - books[i] - books[i]) < minDifferent)
                    {
                        a = min(totalCost - books[i], books[i]);
                        b = max(totalCost - books[i], books[i]);
                        minDifferent = totalCost - books[i] - books[i];
                    }
                }
            }
        }

        fout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
    }
}