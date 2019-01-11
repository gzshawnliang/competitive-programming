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

ifstream fin("antimonotonicity.in");
ofstream fout("antimonotonicity.out");

int main()
{
    int totalTest;
    fin >> totalTest;
    for (int c = 0; c <= totalTest - 1; ++c)
    {
        int n;
        fin >> n;

        if (n == 1)
        {
            fout << "1\n";
            continue;
        }

        vector<int> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        int i = 0, count = 1;
        int last;
        bool lastID;
        while (i <= n - 2)
        {
            bool end0;

            end0 = false;
            while (true)
            {
                if (i <= n - 2)
                {
                    if (a[i] > a[i + 1])
                    {
                        break;
                    }
                    ++i;
                }
                else
                {
                    end0 = true;
                    break;
                }
            }

            if (end0 == true)
            {
                break;
            }
            else
            {
                ++count;
            }

            end0 = false;
            while (true)
            {
                if (i <= n - 2)
                {
                    if (a[i] < a[i + 1])
                    {
                        break;
                    }
                    ++i;
                }
                else
                {
                    end0 = true;
                    break;
                }
            }

            last = a[i];
            lastID = false;

            if (end0 == true)
            {
                break;
            }
            else
            {
                ++count;
            }
        }

        fout << count << '\n';
    }

    return 0;
}