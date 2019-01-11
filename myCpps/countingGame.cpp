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

ifstream fin("countingGame.in");
ofstream fout("countingGame.out");

bool ok(int in)
{
    if (in % 7 == 0)
    {
        return false;
    }
    else
    {
        while (in > 0)
        {
            if (in % 10 == 7)
            {
                return false;
            }
            in /= 10; 
        }

        return true;
    }
}

int main()
{
    while (true)
    {
        int n, m, k;
        fin >> n >> m >> k;

        if (n == 0)
        {
            break;
        }
        
        int i = 1, count = 1;
        bool state = true;
        while (k > 0)
        {
            if (i == n)
            {
                state = false;
            }
            else if (i == 1)
            {
                state = true;
            }

            if (i == m)
            {
                if (ok(count) == false)
                {
                    --k;
                }
            }

            if (state == true)
            {
                ++i;
            }
            else
            {
                --i;
            }

            ++count;
        }

        fout << count - 1 << '\n';
    }

    return 0;
}