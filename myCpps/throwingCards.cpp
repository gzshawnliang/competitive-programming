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

using namespace std;

ifstream fin("throwingCards.in");
ofstream fout("throwingCards.out");

int main()
{
    while (true)
    {
        int n;
        fin >> n;

        if (n == 0)
        {
            break;
        }

        list<int> card;
        for (int c = 1; c <= n; ++c)
        {
            card.push_back(c);
        }

        for (int c = 2; c <= n; ++c)
        {
            card.pop_front();
            int temp = *(card.begin());
            card.pop_front();
            card.push_back(temp);

            // for (auto it = card.begin(); it != card.end(); ++it)
            // {
            //     fout << *it << ' ';
            // }
            // fout << '\n';
        }

        fout << *(card.begin()) << '\n';
    }

    return 0;
}